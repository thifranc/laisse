/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 11:29:24 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/15 18:48:22 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	get_info(t_list *node);
int		ft_higher(int a, int b);
int		ft_nblen(int nb);

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

t_list	*arg_to_list(int ac, char **av, int opt)
{
	int		i;
	t_list	*node;

	i = 1;
	node = NULL;
	while (i < ac)
	{
		if ((opt & OPT_A) || av[i][0] != '.')//dont get arg if !A and file is hidden
		{
			new_in_list(av[i], &node);
			node->path = av[i];
		}
		i++;
	}
	return (node);
}

void	print_list(t_list *node)
{
	t_list	*tmp;
	struct passwd	*usr;
	struct group	*grp;
	int				max[4];

	tmp = node;
	while (tmp)
	{
		usr = getpwuid((tmp->lstat).st_uid);
		grp = getgrgid((tmp->lstat).st_gid);
		max[0] = ft_higher(max[0], ft_nblen((tmp->lstat).st_nlink));
		max[1] = ft_higher(max[1], ft_strlen(usr->pw_name));
		max[2] = ft_higher(max[2], ft_strlen(grp->gr_name));
		max[3] = ft_higher(max[3], ft_nblen((int)(tmp->lstat).st_size));
		tmp = tmp->next;
	}
	tmp = node;//print_it plante si utilise max
	while (tmp)
	{
		usr = getpwuid((tmp->lstat).st_uid);
		grp = getgrgid((tmp->lstat).st_gid);
		print_it("%s  %d %s  %s  %d %s %s\n", get_type((tmp->lstat).st_mode), (tmp->lstat).st_nlink, usr->pw_name, grp->gr_name, (int)(tmp->lstat).st_size, "2015", tmp->name);
		tmp = tmp->next;
	}
}

int		main(int ac, char **av)
{
	t_list	*list;
	t_list	*cpy;
	int		opt;

	opt = get_opt(av[1]);
	list = NULL;
	if (opt == 0 && (ac == 1 || ac == 2))
		list->name = ".";
	else
	{
		list = arg_to_list(ac, av, opt);
		cpy = list;
		recur_sort(&cpy);
		get_info(cpy);
		print_list(cpy);
		printf("\n");
	}
	recur_me(&cpy);
	return (0);
}
