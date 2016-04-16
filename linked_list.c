/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 13:47:25 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/16 09:50:10 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		strcmp3(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/*
t_list	*new_node(char *data)
{
	t_list	*out;

	if (!(out = (t_list*)malloc(sizeof(t_list) * 1)))
		return (NULL);
	out->data = data;
	return (out);
}

void	add_in_list(char *data, t_list **list)
{
	t_list	*new;

	new = new_node(data);
	new->next = *list;
	*list = new;
}
*/
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
/*
void	print_list(t_list *list)
{
	if (!list)
		return ;
	printf("node == %s\n", list->data);
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
		add_in_list(av[i], &list);
		i++;
	}
	printf("%d ====== size list \n", list_size(list));
	recur_sort(&list);
	print_list(list);
	return (0);
}*/
