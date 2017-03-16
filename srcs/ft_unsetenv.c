/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:53:24 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/14 17:41:58 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static char	**unset_value(char **envp, int i)
{
  char		*tmp;

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

static int	usage(int m, char *str)
{
	if (m)
		ft_putendl("usage: unsetenv name");
	else
	  {
	    ft_putstr(str);
	    ft_putendl(" was not found");
	  }
	return (-1);
}

int		ft_unsetenv(int ac, char **av, char **envp)
{
	int		i;
	unsigned int	size;

	i = -1;
	size = 0;
	if (ac != 2)
	  return (usage(1, NULL));
	size = ft_strlen(av[1]);
	while (envp[++i])
	    if (!ft_strncmp(av[1], envp[i], size - 1) && envp[i][size] == '=')
	      {
		envp = unset_value(envp, i);
		return (0);
	      }
	return (usage(0, av[1]));
}
