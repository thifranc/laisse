/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 11:29:24 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/15 14:07:09 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

void	get_info(t_list *node);

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

void	print_list(t_list *node)
{
	t_list	*tmp;
	struct passwd	*mdr;
	struct group	*xd;

	tmp = node;
	while (tmp)
	{
		mdr = getpwuid((tmp->lstat).st_uid);
		xd = getgrgid((tmp->lstat).st_gid);
		print_it("%s  %d %s  %s  %d %s %s\n", get_type((tmp->lstat).st_mode), (tmp->lstat).st_nlink, mdr->pw_name, xd->gr_name, (int)(tmp->lstat).st_size, "2015", tmp->name);
		tmp = tmp->next;
	}
}

int		main(int ac, char **av)
{
	t_list	*list;
	t_list	*cpy;

	list = arg_to_list(ac, av);
	cpy = list;
	get_info(cpy);
	print_list(cpy);
	printf("\n");
	recur_me(&cpy);
	return (0);
}
