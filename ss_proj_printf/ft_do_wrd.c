/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_wrd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:57:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/12 15:31:38 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	do_wrd(char *flag, int *tab, t_data s)
{
	int		max_char;

	max_char = get_max_char(s, tab, flag);
	if (!flag[1])
		ft_print_n_char(' ', tab[0] - max_char);
	if (flag[4] == 's' && !flag[3])
		ft_putstr(s.s, max_char);
	tab[3] += max_char > tab[0] ? max_char : tab[0];
	if (flag[1] == '-')
		ft_print_n_char(' ', tab[0] - max_char);
}

int		get_max_char(t_data s, int *tab, char *flag)
{
	int	max;

	max = 0;
	if (flag[4] == 's' && !flag[3])
		max = ft_strlen(s.s);
	if (tab[1] >= 0)
		return (max > tab[1] ? tab[1] : max);
	else
		return (max);
}
