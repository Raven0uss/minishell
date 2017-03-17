/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:36:30 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/17 10:49:13 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void			exec_builtin(char **cmd, unsigned int i, char **envp)
{
	if (i == 0)
		ft_echo(ft_sizetab(cmd), cmd, 1, envp);
	else if (i == 1)
		ft_cd(ft_sizetab(cmd), cmd, envp);
	else if (i == 2)
		ft_setenv(ft_sizetab(cmd), cmd, envp);
	else if (i == 3)
		ft_unsetenv(ft_sizetab(cmd), cmd, envp);
	else if (i == 4)
		ft_env(ft_sizetab(cmd), cmd, envp);
}

static char			**build_list(char **btl)
{
	unsigned int	i;

	i = 0;
	btl[i++] = ft_strdup("echo");
	btl[i++] = ft_strdup("cd");
	btl[i++] = ft_strdup("setenv");
	btl[i++] = ft_strdup("unsetenv");
	btl[i++] = ft_strdup("env");
	btl[i] = 0;
	return (btl);
}

static int			check_builtins(char **cmd, char **envp)
{
	unsigned int	i;
	char			**builtin_list;

	i = 0;
	if (!(builtin_list = malloc(sizeof(char *) * 7)))
		return (-1);
	builtin_list = build_list(builtin_list);
	while (builtin_list[i])
	{
		if (!ft_strcmp(cmd[0], builtin_list[i]))
		{
			exec_builtin(cmd, i, envp);
			while (i)
				free(builtin_list[i--]);
			free(builtin_list[i]);
			free(builtin_list);
			return (1);
		}
		i++;
	}
	while (--i != 0)
		free(builtin_list[i]);
	free(builtin_list[i]);
	free(builtin_list);
	return (0);
}

static void			minishell(char *buff, char **envp)
{
	char			**cmd;
	int				size;

	size = 0;
	if (buff[0])
	{
		if (!(cmd = ft_whitespaces(buff)))
			return ;
		size = ft_sizetab(cmd);
		if (check_builtins(cmd, envp) == 1)
		{
			while (--size)
				free(cmd[size]);
			free(cmd);
			return ;
		}
		exec_cmd(cmd, envp);
		while (--size)
			free(cmd[size]);
		free(cmd);
	}
}

int					main(int ac, char **av, char **envp)
{
	char			*buff;

	ft_putstr("$>");
	while (get_next_line(0, &buff) && ft_strcmp(buff, "exit"))
	{
		minishell(buff, envp);
		ft_putstr("$>");
	}
	ft_putendl("Exiting minishell...");
	return (0);
}
