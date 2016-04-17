/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:18:16 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/17 12:46:21 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <string.h>

void	print_list(t_list *node, int opt)
{
	t_list	*tmp;
	struct passwd	*usr;
	struct group	*grp;
	int				max[5];
	char			*out;
	char			*date;

	tmp = node;
	max[0] = 0;
	max[1] = 0;
	max[2] = 0;
	max[3] = 0;
	max[4] = 0;
	while (tmp)
	{
		usr = getpwuid((tmp->lstat).st_uid);
		grp = getgrgid((tmp->lstat).st_gid);
		max[0] = ft_higher(max[0], ft_nblen((tmp->lstat).st_nlink));
		max[1] = ft_higher(max[1], ft_strlen(usr->pw_name));
		max[2] = ft_higher(max[2], ft_strlen(grp->gr_name));
		max[3] = ft_higher(max[3], ft_nblen((int)(tmp->lstat).st_size));
		max[4] = ft_higher(max[4], ft_nblen((int)(tmp->lstat).st_ino));
		tmp = tmp->next;
	}
	tmp = node;
	while (tmp)
	{
		if (opt & OPT_I)
			print_it("%-*d ", max[4], (tmp->lstat).st_ino);
		if (opt & OPT_L)
		{
			usr = getpwuid((tmp->lstat).st_uid);
			grp = getgrgid((tmp->lstat).st_gid);
			out = print_it("%s  %*d %-*s  %-*s  %*d ", get_type((tmp->lstat).st_mode), max[0] ,(tmp->lstat).st_nlink,max[1], usr->pw_name, max[2], grp->gr_name, max[3], (int)(tmp->lstat).st_size);
			date = get_date((tmp->lstat).st_mtimespec.tv_sec);
			out = ft_strjoin(out, date);
			out = ft_strjoin(out, tmp->name);
			ft_putstr(out);
			write(1, "\n", 1);
		}
		else
			ft_putstr(print_it("%s\n", tmp->name));
		tmp = tmp->next;
	}
}

char	*make_path(char *s1, char *s2)
{
	char	*out;
	int		i;

	i = 0;
	if (!(out = (char*)malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	while (*s1)
	{
		out[i++] = *s1;
		s1++;
	}
	out[i++] = '/';
	while (*s2)
	{
		out[i++] = *s2;
		s2++;
	}
	out[i] = '\0';
	return (out);
}

t_list	*get_new_list(char *path, int opt)
{
	DIR				*dir;
	struct dirent	*data;
	t_list			*node;

	dir = opendir(path);
	node = NULL;
	while ((data = readdir(dir)) != NULL)
	{
		if ((opt & OPT_A) || data->d_name[0] != '.')//+- = opt a toussa
		{
			new_in_list(data->d_name, &node);
			node->path = make_path(path, data->d_name);
		}
	}
	closedir(dir);
	return (node);
}

void	recur_me(t_list **list, int opt)
{
	t_list	*new;

	if (!*list)
		return ;
	else if (S_ISDIR((*list)->lstat.st_mode) && 
	strcmp3((*list)->name, DR_SON) && strcmp3((*list)->name, DR_FAT))
	{
		new = get_new_list((*list)->path, opt);
		get_info(new, opt);
		recur_sort(&new, opt);
		printf("%s:\n", (*list)->path);
		print_list(new, opt);
		printf("\n");
		recur_me(&(*list)->next, opt);
		if (opt & OPT_RCUR)
			recur_me(&new, opt);
	}
	else
		recur_me(&(*list)->next, opt);
}
