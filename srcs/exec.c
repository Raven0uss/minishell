/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:58:04 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/17 10:51:45 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static char			*find_path(char **envp)
{
	unsigned int	i;
	unsigned int	size;
	unsigned int	j;
	char			*str;

	i = 0;
	j = 0;
	size = 5;
	while (envp[i])
	{
		if (!(ft_strncmp(envp[i], "PATH=", size)))
		{
			if (!(str = malloc(sizeof(char) * ft_strlen(envp[i]))))
				return (NULL);
			while (envp[i][size])
				str[j++] = envp[i][size++];
			str[j] = 0;
			if (j == 0)
				return (NULL);
			return (str);
		}
		i++;
	}
	return (NULL);
}

static int			execat(char *dir, char **cmd, char **envp)
{
	char			*way;
	unsigned int	size;

	size = 0;
	if (!(way = malloc(sizeof(char) * ft_strlen(dir) + ft_strlen(cmd[0]) + 3)))
		return (0);
	way = ft_strcpy(way, dir);
	size = ft_strlen(way);
	if (way[size - 1] != '/')
	{
		way[size++] = '/';
		way[size] = 0;
	}
	way = ft_strcat(way, cmd[0]);
	if (access(way, X_OK | F_OK) == 0)
	{
		if (fork() == 0)
			execve(way, cmd, envp);
		wait(NULL);
		free(way);
		return (1);
	}
	free(way);
	return (0);
}

static int			exec_wpath(char **cmd, char **envp)
{
	unsigned int	i;
	char			*nc_path;
	char			**path;

	i = 0;
	if ((nc_path = find_path(envp)) == NULL)
		return (0);
	path = ft_strsplit(nc_path, ':');
	while (path[i])
		if (execat(path[i++], cmd, envp))
		{
			free(path);
			free(nc_path);
			return (1);
		}
	free(path);
	free(nc_path);
	return (0);
}

int					exec_cmd(char **cmd, char **envp)
{
	if (access(cmd[0], X_OK | F_OK) == 0)
	{
		if (fork() == 0)
			execve(cmd[0], cmd, envp);
		wait(NULL);
	}
	else
	{
		if (!exec_wpath(cmd, envp))
		{
			ft_putstr(cmd[0]);
			ft_putendl(": command not found");
		}
	}
	return (0);
}
