/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:34:15 by sbelazou          #+#    #+#             */
/*   Updated: 2016/11/09 20:04:27 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(char c)
{
	return ((c == ' ' || c == '\n' || c == '\t') ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (ft_strnew(0));
	j = ft_strlen(s) - 1;
	while (s[i] && check_char(s[i]))
		i++;
	while (j >= 0 && check_char(s[j]))
		j--;
	if ((j == -1 && !s[i]))
		return (ft_strnew(0));
	if ((new = malloc(sizeof(char) * ((j + 1) - i) + 1)) == NULL)
		return (NULL);
	while (i != (j + 1))
		new[k++] = s[i++];
	new[k] = 0;
	return (new);
}
