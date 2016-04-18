/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:18:16 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/18 17:09:18 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <string.h>

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
		if (list_size(*list) > 1 || !(opt & OPT_FT))
			ft_putstr(print_it("\n%s:\n", (*list)->path));
		print_list(new, opt);
		recur_me(&(*list)->next, (opt & (MAX - OPT_FT)));
		if (opt & OPT_RCUR)
			recur_me(&new, (opt & (MAX - OPT_FT)));
	}
	else
		recur_me(&(*list)->next, (opt & (MAX - OPT_FT)));
}
