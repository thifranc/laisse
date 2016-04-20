/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 11:29:24 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/20 18:17:59 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_list	*arg_to_list(int ac, char **av)
{
	int		i;
	t_list	*node;

	i = 1;
	while (i < ac && av[i] && av[i][0] == '-')
		i++;
	node = new_node("temp");
	while (i < ac)
	{
		if (lstat(av[i], &(node->lstat)) == -1)
			error_dir(av[i]);
		else
		{
			if (!ft_strcmp(av[i], ".") || !ft_strcmp(av[i], ".."))
				new_in_list(print_it("%s-", av[i]), &node);
			else
				new_in_list(av[i], &node);
			node->path = av[i];
		}
		i++;
	}
	suppr_elem(&node);
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

	opt = get_opt(ac, av);
	if (!hay_arg(ac, av))
		dir = no_arg(opt);
	else
	{
		cpy = arg_to_list(ac, av);
		get_info(cpy, opt);
		dir = div_by_types(&cpy);
		recur_sort(&cpy, opt);
		recur_sort(&dir, opt);
		if (opt & OPT_R)
		{
			ft_list_reverse(&cpy);
			ft_list_reverse(&dir);
		}
		print_list(cpy, (opt | OPT_FIRST));
	}
	if (dir && cpy)
		write(1, "\n", 1);
	recur_me(&dir, (opt | OPT_FT));
	return (0);
}
