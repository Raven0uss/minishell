/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:33:50 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/14 18:30:35 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

//Gestion des \ a gerer

static int			print_echo(char *str, int fd)
{
	unsigned int	i;

	i = 0;
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

int					ft_echo(int ac, char **av, int fd)
{
	unsigned int	n;
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
				if (i != 1)
					ft_putchar(' ');
				if (print_echo(av[i], fd))
					return (0);
			}
			i++;
		}
	if (!n)
		ft_putchar_fd('\n', fd);
	return (0);
}
