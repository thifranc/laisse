/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 11:29:24 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/13 16:50:15 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

t_list	*new_node(char *name)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list) * 1)))
		return (NULL);
	new->name = name;
	new->next = NULL;
	return (new);
}

void	new_in_list(char *data, t_list **list)
{
	t_list	*new;

	new = new_node(data);
	new->next = *list;
	*list = new;
}

t_list	*arg_to_list(int ac, char **av)
{
	int		i;
	t_list	*node;

	i = 1;
	node = NULL;
	while (i < ac)
	{
		if (/*(opt & OPT_A) ||*/ av[i][0] != '.')//dont get arg if !A and file is hidden
		{
			new_in_list(av[i], &node);
			node->path = av[i];//voir si actualise bien le node
		}
		i++;
	}
	return (node);
}

int		main(int ac, char **av)
{
	t_list	*list;
	t_list	*cpy;

	list = arg_to_list(ac, av);
	cpy = list;
	while (list)
	{
		printf("%s &&&&& %s\n", list->name, list->path);
		list = list->next;
	}
	printf("end of directories listing\n");
//	recur_me(cpy, cpy);
	return (0);
}
