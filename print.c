/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 16:25:00 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/18 16:25:49 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	get_max(t_list *list, int *max)
{
	struct passwd	*usr;
	struct group	*grp;
	t_list			*tmp;

	ft_tabnew(max, 6);
	tmp = list;
	while (tmp)
	{
		usr = getpwuid((tmp->lstat).st_uid);
		grp = getgrgid((tmp->lstat).st_gid);
		max[0] = ft_higher(max[0], ft_nblen((tmp->lstat).st_nlink));
		max[1] = ft_higher(max[1], ft_strlen(usr->pw_name));
		max[2] = ft_higher(max[2], ft_strlen(grp->gr_name));
		max[3] = ft_higher(max[3], ft_nblen((int)(tmp->lstat).st_size));
		max[4] = ft_higher(max[4], ft_nblen((int)(tmp->lstat).st_ino));
		max[5] += tmp->lstat.st_blocks;
		tmp = tmp->next;
	}
}

void	print_node(t_list *tmp, int *max, int opt)
{
	char	*out;
	char	buf[256];

	out = NULL;
	if (opt & OPT_I)
		out = print_it("%*d ", max[4], (tmp->lstat).st_ino);
	if (opt & OPT_L)
	{
		out = print_it("%s%s  %*d %-*s  %-*s  %*d %s %s",
	out, get_type((tmp->lstat).st_mode), max[0], (tmp->lstat).st_nlink, max[1],
	getpwuid((tmp->lstat).st_uid)->pw_name, max[2],
	getgrgid((tmp->lstat).st_gid)->gr_name, max[3], (tmp->lstat).st_size,
	get_date((tmp->lstat).st_mtimespec.tv_sec), tmp->name);
		if (S_ISLNK((tmp->lstat).st_mode))
		{
			buf[readlink(tmp->path, buf, 100)] = '\0';
			out = print_it("%s -> %s", out, buf);
		}
		ft_putstr(print_it("%s\n", out));
	}
	else
		ft_putstr(print_it("%s%s\n", out, tmp->name));
	ft_memdel((void**)&out);
}

void	print_list(t_list *node, int opt)
{
	t_list			*tmp;
	int				max[6];

	get_max(node, max);
	tmp = node;
	if ((opt & OPT_L) && !(opt & OPT_FIRST))
		ft_putstr(print_it("total: %d\n", max[5]));
	while (tmp)
	{
		print_node(tmp, max, opt);
		tmp = tmp->next;
	}
}
