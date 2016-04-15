/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:18:16 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/15 13:57:11 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	get_info(t_list *node);

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return (i);
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

t_list	*get_new_list(char *path)
{
	DIR				*dir;
	struct dirent	*data;
	t_list			*node;

	dir = opendir(path);
	node = NULL;
	while ((data = readdir(dir)) != NULL)
	{
		if (data->d_name[0] != '.')//+- = opt a toussa
		{
			new_in_list(data->d_name, &node);
			node->path = make_path(path, data->d_name);
		}
	}
	closedir(dir);
	return (node);
}

void	recur_me(t_list **list)
{
	t_list	*new;
	t_list	*tmp;
	struct passwd	*mdr;
	struct group	*xd;

	if (!*list)
		return ;
	else if (/*S_ISDIR((*list)->lstat.st_mode)*/(*list)->name[0] == 'd')
	{
		new = get_new_list((*list)->path);
		//get_info((*list));
		//	sort_list();
		//	print_list();
		//	if (opt & OPT_RCUR)
		tmp = new;
		get_info(tmp);
		printf("%s:\n", (*list)->path);
		while (tmp)
		{
			mdr = getpwuid((tmp->lstat).st_uid);
			xd = getgrgid((tmp->lstat).st_gid);
			print_it("%s  %d %s  %s  %d %s %s\n", get_type((tmp->lstat).st_mode), (tmp->lstat).st_nlink, mdr->pw_name, xd->gr_name, (int)(tmp->lstat).st_size, "2015", tmp->name);
			tmp = tmp->next;
		}
		printf("\n");
		recur_me(&new);
		recur_me(&(*list)->next);
	}
	else
		recur_me(&(*list)->next);
}
