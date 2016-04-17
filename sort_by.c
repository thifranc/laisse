/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 13:47:25 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/17 15:58:03 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		strcmp3(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int		timed(t_list *a, t_list *b)
{
	return (a->lstat.st_mtimespec.tv_sec - b->lstat.st_mtimespec.tv_sec);
}

int		status(t_list *a, t_list *b)
{
	return (a->lstat.st_ctimespec.tv_sec - b->lstat.st_ctimespec.tv_sec);
}

int		t_access(t_list *a, t_list *b)
{
	return (a->lstat.st_atimespec.tv_sec - b->lstat.st_atimespec.tv_sec);
}

int		ascii(t_list *a, t_list *b)
{
	return (strcmp3(a->name, b->name));
}

int		is_dir(t_list *a, t_list *b)
{
	int		min;

	min = 0;
	if (S_ISDIR((a->lstat).st_mode) || (S_ISDIR((a->lstat).st_mode) && S_ISDIR((b->lstat).st_mode)))
		min--;
	return (min);
}
