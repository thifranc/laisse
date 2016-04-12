/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:12:12 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/12 15:53:56 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_first_char(char **s, char *flag)
{
	while (**s && ft_get_char("#+- 0", **s) != -1)
	{
		if (**s == '0' && flag[1] != '-')
			flag[1] = **s;
		if (**s == '-' && flag[1] != '0')
			flag[1] = **s;
		(*s)++;
	}
}

void	ft_get_last_char(char **s, char *flag)
{
	flag[4] = **s;
}

void	ft_get_opt(char **s, char *flag, int *tab)
{
	(*s)++;
	ft_get_first_char(s, flag);
	if ('1' <= **s && **s <= '9')
	{
		tab[0] = ft_atoi(*s);
		*s += ft_nb_len_base(tab[0], 10);
	}
	if (**s == '.')
	{
		if ('0' <= *((*s) + 1) && *((*s) + 1) <= '9')
		{
			tab[1] = ft_atoi(*(s) + 1);
			*s += ft_nb_len_base(tab[1], 10) + 1;
		}
		else
			(*s)++;
	}
	else
		tab[1] = -1;
	ft_get_last_char(s, flag);
	(*s)++;
}
