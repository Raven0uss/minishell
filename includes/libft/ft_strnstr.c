/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:27:25 by sbelazou          #+#    #+#             */
/*   Updated: 2016/11/08 18:45:14 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_pos_cmp(const char *big, const char *little, int pos, size_t l)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = pos;
	while (little[i])
	{
		if (big[n] != little[i] || n == l)
			return (-1);
		n++;
		i++;
	}
	return (pos);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	if (!little[0])
		return ((char *)big);
	if (!big[0] && little[0])
		return (NULL);
	while (big[i] && (size_t)i < len)
	{
		if (big[i] == little[0])
			if (str_pos_cmp(big, little, i, len) != -1)
			{
				while (pos++ != i)
					big++;
				return ((char *)big);
			}
		i++;
	}
	return (NULL);
}
