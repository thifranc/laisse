/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 13:47:25 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/14 13:47:29 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lol.h"

int		strcmp3(char *s1, char *s2)
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

	i = 1;
	list = NULL;
	a = NULL;
	while (i < ac)
	{
		add_in_list(av[i], atoi(av[i + 1]), &list);
		i += 2;
	}
	printf("%d ====== size list \n", list_size(list));
	recur_sort(&list);
	print_list(list);
	return (0);
}
