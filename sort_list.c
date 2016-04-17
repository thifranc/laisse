/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 13:47:12 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/17 14:40:10 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		list_size(t_list *list)
{
	if (!list)
		return (0);
	else
		return (1 + list_size(list->next));
}

t_list	*list_at(t_list *list, int nb)
{
	if (!nb)
		return (list);
	else
		return (list_at(list->next, nb - 1));
}

t_list	*div_int_two(t_list **list)
{
	t_list	*tmp;
	t_list	*b;

	tmp = list_at(*list, list_size(*list) / 2 - 1);
	b = tmp->next;
	tmp->next = NULL;
	return (b);
}

t_list	*div_by_types(t_list **list)
{
	t_list	*dir;

	recur_sort(&(*list), -666);
	dir = *list;
	while ((*list) && S_ISDIR((*list)->lstat.st_mode))
		*list = (*list)->next;
	return (dir);
}

t_list	*fusion(t_list *a, t_list *b, int(*f)(t_list *, t_list *))
{
	t_list	*out;

	if (!a)
		return (b);
	if (!b)
		return (a);
	if (f(a, b) < 0)
	{
		out = a;
		out->next = fusion(a->next, b, f);
	}
	else
	{
		out = b;
		out->next = fusion(a, b->next, f);
	}
	return (out);
}

void	recur_sort(t_list **list, int opt)
{
	t_list	*a;
	t_list	*b;

	if (!(*list) || !(*list)->next || (opt & OPT_F) == 3)
	{
		return ;
	}
	a = *list;
	b = div_int_two(list);
	recur_sort(&a, opt);
	recur_sort(&b, opt);
	if (opt == -666)
		*list = fusion(a, b, is_dir);
	else if (opt & OPT_T)
		*list = fusion(a, b, timed);
	else 
		*list = fusion(a, b, ascii);
}
