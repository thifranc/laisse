/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 12:28:36 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/06 13:00:15 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*beg;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	beg = ft_lstnew(0, 0);
	beg = f(lst);
	tmp = beg;
	while (lst->next)
	{
		tmp->next = ft_lstnew(0, 0);
		tmp->next = f(lst->next);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (beg);
}
