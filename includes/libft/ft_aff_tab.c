/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:07:08 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/13 18:53:31 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_aff_tab(char **tab, char *sep)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i++]);
		if (tab[i])
			ft_putstr(sep);
	}
	ft_putchar('\n');
}
