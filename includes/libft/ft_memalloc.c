/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:43 by sbelazou          #+#    #+#             */
/*   Updated: 2016/11/08 19:33:41 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	i;
	void	*new;
	char	*ex;

	i = 0;
	if (!size)
		return (0);
	if ((new = malloc(size)) == NULL)
		return (NULL);
	ex = (char *)new;
	if (new != NULL)
	{
		while (i++ < size)
			*ex++ = 0;
	}
	return (new);
}
