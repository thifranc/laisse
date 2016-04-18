/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 11:29:24 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/18 09:28:09 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_higher(int a, int b);
int		ft_nblen(int nb);

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
	new->next = *list;
	*list = new;
}

t_list	*arg_to_list(int ac, char **av, int opt)
{
	int		i;
	t_list	*node;

	i = 1;
	if (opt)
		i++;
	node = NULL;
	while (i < ac)
	{
		if ((opt & OPT_A) || av[i][0] != '.')
		{
			new_in_list(av[i], &node);
			node->path = av[i];
		}
		i++;
	}
	return (node);
}

int		main(int ac, char **av)
{
	t_list	*cpy;
	t_list	*dir;
	int		opt;

	opt = get_opt(av[1]);
	if ((!opt && ac == 1) || (opt && ac == 2))
	{
		dir = new_node("./");
		dir->path = ft_strdup(".");
		get_info(dir, opt);
	}
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
