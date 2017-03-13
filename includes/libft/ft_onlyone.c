/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlyone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:49:44 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/13 18:52:47 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_onlyone(char *str)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	if ((cpy = ft_memalloc(ft_strlen(str))) == NULL)
		return (NULL);
	cpy[j++] = str[i++];
	while (str[i])
	{
		if (ft_strchr(cpy, str[i]) != NULL)
			i++;
		else
			cpy[j++] = str[i++];
	}
	return (cpy);
}
