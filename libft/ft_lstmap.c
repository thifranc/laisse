/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 12:28:36 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/15 18:46:38 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lol	*ft_lstmap(t_lol *lst, t_lol *(*f)(t_lol *elem))
{
	t_lol	*beg;
	t_lol	*tmp;

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
