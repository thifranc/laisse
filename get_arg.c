/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 11:29:24 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/18 13:51:09 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_list	*new_node(char *name)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list) * 1)))
		return (NULL);
	new->name = ft_strdup(name);//dup free par defaut
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

void	suppr_elem(t_list *list)
{
	t_list	*cpy;

	cpy = list;
	while (cpy->next && (cpy->next)->next)
		cpy = cpy->next;
	ft_memdel((void**)&(cpy->next));
	cpy->next = NULL;
}

t_list	*arg_to_list(int ac, char **av, int opt)
{
	int		i;
	t_list	*node;

	i = 1;
	if (opt)
		i++;
	node = new_node("temp");
	while (i < ac)
	{
		if ((opt & OPT_A) || av[i][0] != '.')
		{
			if (lstat(av[i], &(node->lstat)) == -1)
				perror(av[i]);
			else
			{
				new_in_list(av[i], &node);
				node->path = av[i];
			}
		}
		i++;
	}
	suppr_elem(node);
	return (node);
}

t_list	*no_arg(int opt)
{
	t_list	*dir;

	dir = new_node("./");
	dir->path = ft_strdup(".");
	get_info(dir, opt);
	return (dir);
}

int		main(int ac, char **av)
{
	t_list	*cpy;
	t_list	*dir;
	int		opt;

	opt = get_opt(av[1]);
	if ((!opt && ac == 1) || (opt && ac == 2))
		dir = no_arg(opt);
	else
	{
		cpy = arg_to_list(ac, av, opt);
		get_info(cpy, opt);
		dir = div_by_types(&cpy);
		recur_sort(&cpy, opt);
		recur_sort(&dir, opt);
		if (opt & OPT_R)
		{
			ft_list_reverse(&cpy);
			ft_list_reverse(&dir);
		}
		print_list(cpy, opt);
	}
	recur_me(&dir, opt);
	return (0);
}
