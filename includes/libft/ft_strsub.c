/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:09:52 by sbelazou          #+#    #+#             */
/*   Updated: 2016/11/09 19:32:40 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;
	unsigned int	state;

	i = 0;
	state = start;
	if (!s)
		return (NULL);
	if ((dest = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	while (start != state + (unsigned int)len)
	{
		if (!s[start])
			return (NULL);
		dest[i] = s[start];
		start++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}
