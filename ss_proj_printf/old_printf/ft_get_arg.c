/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:02:24 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/12 15:34:43 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long int	get_arg_nb(va_list va, char c, char *flag)
{
	long long int	out;

	out = va_arg(va, long long);
	return (out);
}

void			get_arg(va_list va, char *flag, int *tab, t_data s)
{
	long long int	lli;

	lli = 0;
	if (flag[4] == 's' && flag[3] != 'l')
		s.s = va_arg(va, const char *);
	else
		lli = get_arg_nb(va, flag[4], flag);
	if (ft_get_char("pdioubxDIOUX%", flag[4]) != -1)
		do_nb(flag, tab, lli);
	else
		do_wrd(flag, tab, s);
}
