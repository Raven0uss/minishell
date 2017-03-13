/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:08:11 by sbelazou          #+#    #+#             */
/*   Updated: 2016/11/09 21:08:25 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *a;
	t_list *b;
	t_list *new_list;

	a = lst;
	if (!a && !f)
		return (0);
	a = f(lst);
	new_list = ft_lstnew(a->content, a->content_size);
	if (!new_list)
		return (0);
	b = new_list;
	while (lst->next)
	{
		a = f(lst->next);
		new_list->next = ft_lstnew(a->content, a->content_size);
		lst = lst->next;
		new_list = new_list->next;
	}
	return (b);
}
