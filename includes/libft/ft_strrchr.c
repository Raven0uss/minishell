/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:30:43 by sbelazou          #+#    #+#             */
/*   Updated: 2016/11/07 18:30:31 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	while (i >= 0)
	{
		if ((char)c == *s)
			return ((char *)s);
		s--;
		i--;
	}
	return (NULL);
}
