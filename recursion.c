/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 13:47:12 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/16 11:37:12 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_list	*div_int_two(t_list **list)
{
	t_list	*tmp;
	t_list	*b;

	tmp = list_at(*list, list_size(*list) / 2 - 1);
	b = tmp->next;
	tmp->next = NULL;
	return (b);
}

int		timed(t_list *a, t_list *b)
{
	return (a->lstat.st_mtimespec.tv_sec - b->lstat.st_mtimespec.tv_sec);
}

int		ascii(t_list *a, t_list *b)
{
	return (strcmp3(a->name, b->name));
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
	if (opt & OPT_T)
	{
		*list = fusion(a, b, timed);
	}
	else 
	{
		*list = fusion(a, b, ascii);
	}
	if (opt & OPT_R)
		ft_list_reverse(list);
}

