/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:53:24 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/28 15:41:03 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static char			**retab_av(int ac, char **av)
{
	unsigned int	i;

	i = 0;
	while (i != (unsigned int)ac)
	{
		av[i] = av[i + 1];
		i++;
	}
	if (av[0][0] == '-')
	{
		if (!ft_strcmp(av[0], "-i"))
		{
			i = 0;
			while (i != (unsigned int)ac)
			{
				av[i] = av[i + 1];
				i++;
			}
		}
		else
			return (NULL); // ERREUR
	}
	return (av);
}

int					ft_env(int ac, char **av, char **envp)
{
	unsigned int	i;

	i = 0;
	if (ac == 2)
		if (!ft_strcmp(av[1], "-i"))
			return (0);
	if (ac >= 2)
	{
		if ((av = retab_av(ac, av)) == NULL)
			return (-1);
		exec_cmd(av, envp);
		return (0);
	}
	while (envp[i])
		ft_putendl(envp[i++]);
	return (0);
}
