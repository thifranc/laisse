/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_date.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 09:34:40 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/17 10:00:28 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*get_date(time_t t)
{
	char	*out;
	char	**splitted;

	out = ctime(&t);
	printf("first date =%s", out);
	splitted = ft_strsplit(out, ' ');
	splitted[3][5] = '\0';
	print_it("%s %s %s\n", splitted[1], splitted[2], splitted[3]);
	return (out);
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
