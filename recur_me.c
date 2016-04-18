/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:18:16 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/18 16:04:49 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <string.h>

void	print_list(t_list *node, int opt)
{
	t_list			*tmp;
	struct passwd	*usr;
	struct group	*grp;
	int				max[6];
	char			*out;
	char			buf[256];

	tmp = node;
	out = NULL;
	ft_tabnew(max, 6);
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
	tmp = node;
	if ((opt & OPT_L) && !(opt & OPT_FIRST))
		ft_putstr(print_it("total: %d\n", max[5]));
	while (tmp)
	{
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
		tmp = tmp->next;
	}
}

t_list	*get_new_list(char *path, int opt)
{
	DIR				*dir;
	struct dirent	*d;
	t_list			*node;

	if ((dir = opendir(path)) == NULL)
		return (error_dir(path));
	node = new_node("temp");
	while ((d = readdir(dir)) != NULL)
	{
		if ((opt & OPT_A) || d->d_name[0] != '.')
		{
			if (lstat(print_it("%s/%s", path, d->d_name), &(node->lstat)) == -1)
				perror(d->d_name);
			else
			{
				new_in_list(d->d_name, &node);
				node->path = print_it("%s/%s", path, d->d_name);
			}
		}
	}
	closedir(dir);
	suppr_elem(node);
	return (node);
}

void	recur_me(t_list **list, int opt)
{
	t_list	*new;

	if (!*list)
		return ;
	else if (S_ISDIR((*list)->lstat.st_mode) &&
	strcmp3((*list)->name, ".") && strcmp3((*list)->name, ".."))
	{
		new = get_new_list((*list)->path, opt);
		get_info(new, opt);
		recur_sort(&new, opt);
		if (opt & OPT_R)
			ft_list_reverse(&new);
		if (list_size(*list) > 1 || !(opt & OPT_FIRST))
			ft_putstr(print_it("\n%s:\n", (*list)->path));
		print_list(new, opt);
		recur_me(&(*list)->next, (opt & (MAX - OPT_FIRST)));
		if (opt & OPT_RCUR)
			recur_me(&new, (opt & (MAX - OPT_FIRST)));
	}
	else
		recur_me(&(*list)->next, (opt & (MAX - OPT_FIRST)));
}
