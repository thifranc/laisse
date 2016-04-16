/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:29:31 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/16 10:07:25 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	get_other_right(mode_t st_mode, char *r)
{
	r[0] = (st_mode & S_IROTH) ? 'r' : '-';
	r[1] = (st_mode & S_IWOTH) ? 'w' : '-';
	if (st_mode & S_ISVTX && st_mode & S_IXOTH)
		r[2] = 's';
	else if (st_mode & S_ISVTX && !(st_mode & S_IXOTH))
		r[2] = 'S';
	else if (st_mode & S_IXOTH)
		r[2] = 'x';
	else
		r[2] = '-';	
}

void	get_grp_right(mode_t st_mode, char *r)
{
	r[0] = (st_mode & S_IRGRP) ? 'r' : '-';
	r[1] = (st_mode & S_IWGRP) ? 'w' : '-';
	if (st_mode & S_ISGID && st_mode & S_IXGRP)
		r[2] = 's';
	else if (st_mode & S_ISGID && !(st_mode & S_IXGRP))
		r[2] = 'S';
	else if (st_mode & S_IXGRP)
		r[2] = 'x';
	else
		r[2] = '-';	
}

char	*get_user_right(mode_t st_mode, char *r)
{
	r[0] = (st_mode & S_IRUSR) ? 'r' : '-';
	r[1] = (st_mode & S_IWUSR) ? 'w' : '-';
	if (st_mode & S_ISUID && st_mode & S_IXUSR)
		r[2] = 's';
	else if (st_mode & S_ISUID && !(st_mode & S_IXUSR))
		r[2] = 'S';
	else if (st_mode & S_IXUSR)
		r[2] = 'x';
	else
		r[2] = '-';	
	get_grp_right(st_mode, r + 3);
	get_other_right(st_mode, r + 6);
	return (r - 1);
}

char	*get_type(mode_t st_mode)
{
	char	*r;

	if (!(r = (char*)malloc(sizeof(char) * 11)))
		return (0);
	r[10] = '\0';
	if (S_ISBLK(st_mode))
		r[0] = 'b';
	else if (S_ISCHR(st_mode))
		r[0] = 'c';
	else if (S_ISDIR(st_mode))
		r[0] = 'd';
	else if (S_ISLNK(st_mode))
		r[0] = 'l';
	else if (S_ISSOCK(st_mode))
		r[0] = 's';
	else if (S_ISFIFO(st_mode))
		r[0] = 'p';
	else if (S_ISREG(st_mode))
		r[0] = '-';
	get_user_right(st_mode, r + 1);
	return (r);
}

void	get_info(t_list *node)
{
	t_list			*tmp;

	tmp = node;
	while (tmp)
	{
		lstat(tmp->path, &(tmp->lstat));
		tmp = tmp->next;
	}
}
