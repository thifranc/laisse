
#include <stdlib.h>
#include <stdio.h>

typedef struct s_struct
{
	struct s_struct *next;
	char			*data;
	int				val;
}				t_list;

int		strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

t_list	*new_node(char *data, int nb)
{
	t_list	*out;

	if (!(out = (t_list*)malloc(sizeof(t_list) * 1)))
		return (NULL);
	out->data = data;
	out->val = nb;
	return (out);
}

void	add_in_list(char *data, int val, t_list **list)
{
	t_list	*new;

	new = new_node(data, val);
	new->next = *list;
	*list = new;
}

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

t_list	*fusion(t_list *a, t_list *b)
{
	t_list	*out;

	if (!a)
		return (b);
	if (!b)
		return (a);
	if (a->val < b->val)
	{
		a->next = b;
		out = fusion(a->next, b);
	}
	else
	{
		b->next = a;
		out = fusion(a, b->next);
	}
	return (out);
}

void	recur_sort(t_list **list)
{
	t_list	*out;
	t_list	*a;
	t_list	*b;

	if (!list || !(list->next))
		return ;
	div_int_two(list, a, b);
	recur_sort(a);
	recur_sort(b);
	out = fusion(a, b);
}

void	print_list(t_list *list)
{
	if (!list)
		return ;
	printf("node == %s &&&& %d\n", list->data, list->val);
	print_list(list->next);
}

int		main(int ac, char **av)
{
	int	i;
	t_list	*list;
	t_list	*a;
	t_list	*b;

	i = 1;
	list = NULL;
	a = NULL;
	while (i < ac)
	{
		add_in_list(av[i], atoi(av[i + 1]), &list);
		i += 2;
	}
	printf("%d ====== size list \n", list_size(list));
	a = list;
	b = div_int_two(&list);
	printf("1ere liste \n");
	print_list(a);
	printf("2eme liste \n");
	print_list(b);
	return (0);
}
