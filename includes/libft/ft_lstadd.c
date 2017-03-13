/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:07:34 by sbelazou          #+#    #+#             */
/*   Updated: 2016/11/09 21:07:36 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		if (!*alst)
		{
			*alst = new;
			return ;
		}
		(*alst)->prev = new;
		new->next = *alst;
		*alst = new;
		new->prev = NULL;
	}
}
