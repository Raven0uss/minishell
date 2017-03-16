/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:53:24 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/14 17:41:58 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

// NAME NE DOIT PAS CONTENIR =
// AJOUT DE SI VIDE BAH TU METS
// CAPITALIZE NAME

static char	*set_value(char *name, char *value)
{
       char	*result;
       unsigned int	size;

       if (value != 0)
	 size = ft_strlen(name) + ft_strlen(value) + 3;
       else
	 size = ft_strlen(name) + 2;
       if (!(result = malloc(sizeof(char) * size)))
	 return (NULL);
       result = ft_strcpy(result, name);
       size = ft_strlen(result);				//
       result[size++] = '=';
       result[size] = 0;
       if (value == 0)
	 return (result);
       result = ft_strcat(result, value);
       return (result);
}

static int	usage(int m, char *str)
{
	if (m)
		ft_putendl("usage: setenv name value [-o]");
	else
	  {
	    ft_putstr(str);
	    ft_putendl(" already exist, use -o to overwrite value");
	  }
	return (-1);
}

int		ft_setenv(int ac, char **av, char **envp)
{
	unsigned char	o;
	int		i;
	unsigned int	size;

	i = 0;
	o = 0;
	if (ac < 2 || ac > 4)
	  return (usage(1, NULL));
	if (ac == 4)
	    if (++o && ft_strcmp(av[3], "-o"))
	      return (usage(1, NULL));
	size = ft_strlen(av[1]);
	while (envp[i])
	  {
	    if (!ft_strncmp(av[1], envp[i], size - 1) && envp[i][size] == '=')
	      {
		if (o)
		  break ;
		return (usage(0, av[1]));
	      }
	    i++;
	  }
       	envp[i++] = set_value(av[1], av[2]);
	envp[i] = 0;
	return (0);
}
