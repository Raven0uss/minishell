/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:53:24 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/16 21:52:43 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int					ft_env(int ac, char **av, char **envp)
{
	unsigned int	i;

	i = 0;
	if (ac == 2)
		if (!(ft_strcmp(av[1], "-i")))
			return (0);
	while (envp[i])
		ft_putendl(envp[i++]);
	return (0);
}
