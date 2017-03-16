/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:35:30 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/16 20:42:34 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			strblank(char const *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		if (!ft_isblank(s[i++]))
			return (0);
	return (1);
}

static int			count_words(char const *s)
{
	int				a;
	int				count;

	count = 0;
	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] != ' ' && s[a] != '\t' &&
			(s[a - 1] == ' ' || s[a - 1] == '\t' || a == 0))
			count++;
		a++;
	}
	return (count);
}

static char			*words(char const *s, int *len, char *word)
{
	int				a;
	int				b;

	b = 0;
	while ((s[(*len)] == ' ' || s[(*len)] == '\t') && s[(*len)++])
		;
	while (s[b + *len] != ' ' && s[b + *len] != '\t' && s[*len + b++])
		;
	word = malloc(b + 1);
	if (!word)
		return (0);
	a = 0;
	while (s[(*len)] != ' ' && s[(*len)] != '\t' && s[(*len)])
		word[a++] = s[(*len)++];
	word[a] = 0;
	return (word);
}

char				**ft_whitespaces(char const *s)
{
	char			**new_str;
	int				i;
	int				j;

	i = 0;
	j = 0;
	new_str = 0;
	if (s && !strblank(s))
		new_str = malloc(sizeof(*new_str) * count_words(s) + 1);
	else
		return (NULL);
	if (!new_str)
		return (0);
	while (i < count_words(s))
	{
		new_str[i] = words(s, &j, new_str[i]);
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
