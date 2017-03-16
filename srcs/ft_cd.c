/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:53:24 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/16 22:23:06 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static int			not_found(char *str, int f)
{
	ft_putstr("cd: no such file or directory: ");
	ft_putendl(str);
	if (f)
		free(str);
	return (-1);
}

static int			cd_oldpwd(char **envp)
{
	int				i;
	unsigned int	j;
	unsigned int	begin;
	char			*oldpwd;

	i = -1;
	begin = 7;
	j = 0;
	while (envp[++i])
		if (!(ft_strncmp(envp[i], "OLDPWD=", begin)) && envp[i][begin])
		{
			if (!(oldpwd = malloc(sizeof(char) * ft_strlen(envp[i]))))
				return (-1);
			while (envp[i][begin])
				oldpwd[j++] = envp[i][begin++];
			oldpwd[j] = 0;
			if (chdir(oldpwd) != 0)
				return (not_found(oldpwd, 1));
			ft_putendl(oldpwd);
			free(oldpwd);
			return (0);
		}
	ft_putendl("cd: OLDPWD not set");
	return (-1);
}

static int			cd_home(char **envp)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	begin;
	char			*home;

	i = 0;
	begin = 5;
	j = 0;
	while (envp[i])
	{
		if (!(ft_strncmp(envp[i], "HOME=", begin)) && envp[i][begin])
		{
			if (!(home = malloc(sizeof(char) * ft_strlen(envp[i]))))
				return (-1);
			while (envp[i][begin])
				home[j++] = envp[i][begin++];
			home[j] = 0;
			if (chdir(home) != 0)
				return (not_found(home, 1));
			free(home);
			return (0);
		}
		i++;
	}
	ft_putendl("cd: HOME not set");
	return (-1);
}

int					ft_cd(int ac, char **av, char **envp)
{
	int				ret;

	ret = 0;
	if (ac > 2)
	{
		ft_putendl("cd: too many arguments");
		return (-1);
	}
	else if (ac == 1)
		return (cd_home(envp));
	else if (ac == 2)
	{
		if (!(ft_strcmp(av[1], "-")))
			return (cd_oldpwd(envp));
		if (!ft_strcmp(av[1], "~"))
			return (cd_home(envp));
		if (chdir(av[1]) != 0)
			return (not_found(av[1], 0));
	}
	return (0);
}
