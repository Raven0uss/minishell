/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:45:49 by sbelazou          #+#    #+#             */
/*   Updated: 2016/11/08 18:55:27 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *nptr)
{
	int		nb;
	int		i;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' ||
			nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		sign = nptr[i++] == '+' ? 1 : -1;
	while (ft_isdigit(nptr[i]))
	{
		nb *= 10;
		nb += (nptr[i++] - '0');
	}
	return (nb * sign);
}
