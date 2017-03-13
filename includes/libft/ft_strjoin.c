/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:26:51 by sbelazou          #+#    #+#             */
/*   Updated: 2016/11/09 19:33:55 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	unsigned int	size;

	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
		if ((new = malloc(sizeof(char) * size)) == NULL)
			return (NULL);
		new = ft_strcpy(new, s1);
		new = ft_strcat(new, s2);
		new[size] = 0;
		return (new);
	}
	return (NULL);
}
