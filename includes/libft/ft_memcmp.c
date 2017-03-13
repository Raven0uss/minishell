/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:48:07 by sbelazou          #+#    #+#             */
/*   Updated: 2016/11/09 18:09:47 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;

	ptr = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (n)
	{
		if (*ptr != *ptr2)
			return ((int)(*ptr - *ptr2));
		n--;
		ptr++;
		ptr2++;
	}
	return (0);
}
