/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 11:11:51 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/11 15:33:35 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/* cflag code is short = 0000 0000 Rlih rtfa*/

short	get_opt(char *str)
{
	short	out;

	out = 0;
	if (!str || str[0] != '-')
		return (out);
	s++;
	while (*s && (get_char("raRtflih", *s) != -1))
	{
		if (*s == 'a')
			out = out | OPT_A;
		else if (*s == 'f')
			out = out | OPT_F;
		else if (*s == 't')
			out = out | OPT_T;
		else if (*s == 'r')
			out = out | OPT_R;
		else if (*s == 'h')
			out = out | OPT_H;
		else if (*s == 'i')
			out = out | OPT_I;
		else if (*s == 'l')
			out = out | OPT_L;
		else if (*s == 'R')
			out = out | OPT_RCUR;
		s++;
	}
	if (!*s)
		return (out);
	//else return illegal option;
}

int		main(int ac, char **av)
{
	int		opt;
	t_list	*list;
	t_list	*repo_list;

	opt = get_opt(av[1]);
	if (opt == 0 && (ac == 1 || ac == 2))
		repo_list->name = ".";
	else
	{
		list = get_arg_in_list(ac, av);//if a or no get or dont the '.'beginning files
		get_info(list);
		repo_list = sort_by_types(list);//div list in two lists repo|others (others are "first")
		sort_list(&list);
		sort_list(&repo_list);
		print_list(&list);//print and del
	}
	recur_me(&repo_list);//if !R opt it will just print list-directories content
}

void	recur_me(t_list **list, short opt)
{
	if (!*list)
		dellist;
	else if (S_ISDIR((*list)->lstat.st_mode))
	{
		get_new_list;
		sort_list();
		get_info();
		print_list();
		if (opt & OPT_RCUR)
			recur_me(&new);
		recur_me(list->next);
	}
	else
		recur_me(list->next);
}
