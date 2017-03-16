/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:53:24 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/14 17:41:58 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

// HOME A CHECK DANS L'ENV SI NOT FOUND ERROR

static int	cd_home(char **envp)
{
  return (0);
}

int		ft_cd(int ac, char **av, char **envp)
{
	int	ret;

	ret = 0;
	if (ac > 2)
		ft_putendl("cd: too many arguments");
	else if (ac == 1)
	  return (cd_home(envp));
	else if (ac == 2)
	{
		ft_putendl(av[1]);
		ret = chdir(av[1]);
		ft_putnbr(ret);
	}
	return (0);
}
