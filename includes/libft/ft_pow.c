/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:45:38 by sbelazou          #+#    #+#             */
/*   Updated: 2016/11/10 16:45:40 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int nb, int pow)
{
	if (!pow || nb == 1 || (nb == -1 && !(pow % 2)))
		return (1);
	if (pow < 0)
		return (0);
	if (nb == -1 && pow % 2)
		return (-1);
	if (pow > 1)
		return (nb * ft_pow(nb, pow - 1));
	else
		return (nb);
}
