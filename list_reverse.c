/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:40:47 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/16 11:17:21 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *prv;
	t_list *cur;
	t_list *fol;

	cur = *begin_list;
	prv = NULL;
	while (cur != NULL)
	{
		fol = cur->next;
		cur->next = prv;
		prv = cur;
		cur = fol;
	}
	*begin_list = prv;
}
