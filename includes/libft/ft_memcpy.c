/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:01:20 by sbelazou          #+#    #+#             */
/*   Updated: 2016/11/09 18:01:05 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*c1;
	char	*c2;

	i = 0;
	if (dst == src)
		return (dst);
	c1 = (char *)dst;
	c2 = (char *)src;
	while (i < n)
	{
		*c1++ = *c2++;
		i++;
	}
	return (dst);
}
