/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:53:24 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/16 20:36:09 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

// GESTION DE -i

int		ft_env(char **envp)
{
  unsigned int	i;

  i = 0;
  while (envp[i])
    ft_putendl(envp[i++]);
  return (0);
}
