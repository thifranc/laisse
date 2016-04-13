/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:18:16 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/13 17:06:25 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

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
	while ((data = readdir(dir)) != NULL)
	{
		new_in_list(data->d_name, &node);
		node->path = make_path(path, data->d_name);
	}
	closedir(dir);
	return (node);
}

void	recur_me(t_list **list)
{
	t_list	*new;
	t_list	*tmp;

	if (!*list)
		return ;
	else if (/*S_ISDIR((*list)->lstat.st_mode)*/(*list)->name[0] == 'd')
	{
		new = get_new_list((*list)->path);
	//	sort_list();
	//	get_info();
	//	print_list();
	//	if (opt & OPT_RCUR)
		tmp = new;
		while (tmp)
		{
			printf("%s &&&&&&&& %s \n", tmp->name, tmp->path);
			tmp = tmp->next;
		}
		recur_me(&new);
		recur_me(&(*list)->next);
	}
	else
		recur_me(&(*list)->next);
}
