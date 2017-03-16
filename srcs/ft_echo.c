/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:33:50 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/16 21:32:40 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

// Gestion des \ a gerer

static void			check_env(char *str, int fd, char **envp)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	while (str[i])
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = 0;
	size = ft_strlen(str);
	while (envp[i])
	{
		if (!(ft_strncmp(str, envp[i], size)) && envp[i][size] == '=')
		{
			while (envp[i][++size])
				ft_putchar_fd(envp[i][size], fd);
			return ;
		}
		i++;
	}
}

static int			print_echo(char *str, int fd, char **envp)
{
	unsigned int	i;

	i = 0;
	if (str[i] && str[i] == '$' && str[i + 1])
	{
		check_env(str, fd, envp);
		return (0);
	}
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1])
			if (str[i + 1] == 'c')
				return (1);
		ft_putchar_fd(str[i], fd);
		i++;
	}
	return (0);
}

int					ft_echo(int ac, char **av, int fd, char **envp)
{
	unsigned char	n;
	unsigned int	i;

	i = 1;
	n = 0;
	if (ac != 1)
		while (av[i])
		{
			if (!ft_strcmp(av[i], "-n") && i == 1)
				n++;
			else
			{
				if (i >= 2)
					if (!(i == 2 && n))
						ft_putchar_fd(' ', fd);
				if (print_echo(av[i], fd, envp))
					return (0);
			}
			i++;
		}
	if (!n)
		ft_putchar_fd('\n', fd);
	return (0);
}
