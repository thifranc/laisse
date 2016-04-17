/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_date.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 09:34:40 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/17 10:38:47 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*get_date(time_t t)
{
	char	*out;
	char	**splitted;

	out = ctime(&t);
	splitted = ft_strsplit(out, ' ');
	splitted[3][5] = '\0';
	out = print_it("%s %s %s ", splitted[1], splitted[2], splitted[3]);
	ft_memdel((void*)&(*splitted));
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
