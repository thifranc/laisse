/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_date.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 09:34:40 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/20 11:23:45 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*get_date(time_t t)
{
	char	*out;
	char	**sed;
	time_t	now;

	now = time(NULL);
	out = ctime(&t);
	sed = ft_strsplit(out, ' ');
	if (now - t > SIX_MONTH || t - now > 0)
	{
		sed[4][4] = '\0';
		out = print_it("%s %*s %*s ", sed[1], 2, sed[2], 5, sed[4]);
	}
	else
	{
		sed[3][5] = '\0';
		out = print_it("%s %*s %s ", sed[1], 2, sed[2], sed[3]);
	}
	ft_memdel((void*)&(*sed));
	return (out);
}

char	*get_min_maj(struct stat lstat, int *max)
{
	int		min;
	int		maj;

	if (S_ISBLK(lstat.st_mode) || S_ISCHR(lstat.st_mode))
	{
		maj = major(lstat.st_rdev);
		min = minor(lstat.st_rdev);
		return (print_it("%*d, %*d", max[6], maj, max[7], min));
	}
	else
		return (print_it("%*d", max[3], lstat.st_size));
}

void	get_info(t_list *node, int opt)
{
	t_list			*tmp;

	tmp = node;
	if (opt & OPT_STAT)
	{
		while (tmp)
		{
			if ((stat(tmp->path, &(tmp->lstat))) == -1)
				perror(print_it("ls: %s", tmp->name));
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp)
		{
			if ((lstat(tmp->path, &(tmp->lstat))) == -1)
				perror(print_it("ls: %s", tmp->name));
			tmp = tmp->next;
		}
	}
}
