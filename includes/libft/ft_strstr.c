/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:27:25 by sbelazou          #+#    #+#             */
/*   Updated: 2016/11/08 18:15:37 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_pos_cmp(const char *big, const char *little, int pos)
{
	int		i;
	int		n;

	i = 0;
	n = pos;
	while (little[i])
	{
		if (big[n] != little[i])
			return (-1);
		n++;
		i++;
	}
	return (pos);
}

char		*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	if (!little[0])
		return ((char *)big);
	if (!big[0] && little[0])
		return (NULL);
	while (big[i])
	{
		if (big[i] == little[0])
			if (str_pos_cmp(big, little, i) != -1)
			{
				while (pos++ != i)
					big++;
				return ((char *)big);
			}
		i++;
	}
	return (NULL);
}
