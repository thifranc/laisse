/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 11:11:51 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/15 19:28:20 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/* cflag code is short = 0000 0000 Rlih rtfa*/

int		get_opt(char *s)
{
	int		out;
	int		i;

	out = 0;
	i = 0;
	if (!s || s[0] != '-')
		return (out);
	i++;
	while (s[i] && (ft_get_char("raRtflih", s[i]) != -1))
	{
		if (s[i] == 'a')
			out = out | OPT_A;
		else if (s[i] == 'f')
			out = out | OPT_F;
		else if (s[i] == 't')
			out = out | OPT_T;
		else if (s[i] == 'r')
			out = out | OPT_R;
		else if (s[i] == 'h')
			out = out | OPT_H;
		else if (s[i] == 'i')
			out = out | OPT_I;
		else if (s[i] == 'l')
			out = out | OPT_L;
		else if (s[i] == 'R')
			out = out | OPT_RCUR;
		i++;
	}
	if (!s[i])
		return (out);
	return (out);
	//else return illegal option;
}
/*
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
		list = arg_to_list(ac, av, opt);//if a or no get or dont the '.'beginning files
		get_info(list);
		repo_list = sort_by_types(list);//div list in two lists repo|others (others are "first")
		sort_list(&list);
		sort_list(&repo_list);
		print_list(&list);//print and del
	}
	recur_me(&repo_list);//if !R opt it will just print list-directories content
}
*/
/*
void	get_info(t_list	*cur)
{
	if (!cur)
		return ;
	lstat(cur->path, &(cur->lstat));
	get_info(cur->next);
}*/
