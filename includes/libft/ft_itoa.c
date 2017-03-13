/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:23:16 by sbelazou          #+#    #+#             */
/*   Updated: 2016/11/09 18:07:18 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(int n)
{
	int		c;

	c = 1;
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

static char	*reverse_res(char *str)
{
	char	c;
	int		j;
	int		i;

	i = str[0] == '-' ? 1 : 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	if ((str = malloc(sizeof(char) * (counter(n) + 1))) == NULL)
		return (NULL);
	if (n == 0)
		return (ft_strcpy(str, "0\0"));
	if (n == (-2147483647 - 1))
		return ((str = ft_strcpy(str, "-2147483648\0")));
	if (n < 0)
	{
		str[i++] = '-';
		n *= -1;
	}
	while (n)
	{
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	str[i] = 0;
	return ((str = reverse_res(str)));
}
