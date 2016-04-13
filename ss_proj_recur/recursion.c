
#include "lol.h"
t_list	*div_int_two(t_list **list)
{
	t_list	*tmp;
	t_list	*b;

	tmp = list_at(*list, list_size(*list) / 2 - 1);
	b = tmp->next;
	tmp->next = NULL;
	return (b);
}

t_list	*fusion(t_list *a, t_list *b)
{
	t_list	*out;

	if (!a)
		return (b);
	if (!b)
		return (a);
	if (a->val < b->val)
	{
		out = a;
		out->next = fusion(a->next, b);
	}
	else
	{
		out = b;
		out->next = fusion(a, b->next);
	}
	return (out);
}

void	recur_sort(t_list **list)
{
	t_list	*a;
	t_list	*b;

	if (!(*list) || !(*list)->next)
		return ;
	a = *list;
	b = div_int_two(list);
	recur_sort(&a);
	recur_sort(&b);
	*list = fusion(a, b);
}

