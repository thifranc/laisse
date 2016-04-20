/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 16:27:29 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/20 10:41:48 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_list	*new_node(char *name)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list) * 1)))
		return (NULL);
	if (ft_strcmp(name, ".") == 0)
		new->name = ft_strdup(".-");
	else if (ft_strcmp(name, "..") == 0)
		new->name = ft_strdup("..-");
	else
		new->name = ft_strdup(name);
	new->next = NULL;
	return (new);
}

void	new_in_list(char *data, t_list **list)
{
	t_list	*new;

	new = new_node(data);
	if (*list)
		new->next = *list;
	*list = new;
}

void	suppr_elem(t_list **list)
{
	t_list	*cpy;

	cpy = *list;
	if (!cpy->next)
	{
		ft_memdel((void**)&(*list));
		return ;
	}
	while (cpy->next && (cpy->next)->next)
		cpy = cpy->next;
	ft_memdel((void**)&(cpy->next));
	cpy->next = NULL;
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
