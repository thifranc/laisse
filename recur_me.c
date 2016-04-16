/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:18:16 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/16 10:01:22 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <string.h>

void	get_info(t_list *node);

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
		get_info(new);
		recur_sort(&new);
		printf("%s:\n", (*list)->path);
		print_list(new);
		printf("\n");
		recur_me(&(*list)->next, opt);
		if (opt & OPT_RCUR)
			recur_me(&new, opt);
	}
	else
		recur_me(&(*list)->next, opt);
}
