/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:53:24 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/28 12:32:56 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static char			**unset_value(char **envp, int i)
{
	char			*tmp;

	tmp = envp[i];
	while (envp[i + 1])
	{
		tmp = envp[i];
		envp[i] = envp[i + 1];
		envp[i + 1] = tmp;
		i++;
	}
	envp[i] = 0;
	return (envp);
}

static int			usage(int m, char *str)
{
	if (m)
		ft_putendl("usage: unsetenv [VAR ...]");
	else
	{
		ft_putstr(str);
		ft_putendl(" was not found");
	}
	return (-1);
}

int					ft_unsetenv(int ac, char **av, char **envp, int mode)
{
	int				i;
	unsigned int	size;
	unsigned int	j;
	unsigned char	flag;

	j = 1;
	i = -1;
	size = 0;
	while (j != (unsigned int)ac)
	{
		flag = 0;
		size = ft_strlen(av[j]);
		while (envp[++i])
			if (!ft_strncmp(av[j], envp[i], size - 1) && envp[i][size] == '=')
			{
				envp = unset_value(envp, i);
				flag++;
			}
		if (!flag && mode)
			usage(0, av[j]);
		j++;
		i = -1;
	}
	return (j == 1 ? usage(1, NULL) : 0);
}
