/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 18:32:20 by sbelazou          #+#    #+#             */
/*   Updated: 2016/11/10 16:34:06 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int	racine;

	racine = 1;
	if (nb <= 0)
		return (0);
	while ((racine * racine) <= nb)
	{
		if ((racine * racine) == nb)
			return (racine);
		racine++;
	}
	return (0);
}
