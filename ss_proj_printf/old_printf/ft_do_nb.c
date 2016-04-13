/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_nb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 09:03:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/05 18:58:41 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		get_total_char(long long int arg, char *f, int *tab)
{
	int		tmp;
	int		len;

	if (f[4] == 'x' || f[4] == 'X' || f[4] == 'p')
		tab[2] = 16;
	else if (f[4] == 'o')
		tab[2] = 8;
	else if (f[4] == 'b')
		tab[2] = 2;
	else
		tab[2] = 10;
	if (f[4] == '%')
		tab[1] = -1;
	if (ft_get_char("diDI", f[4]) != -1)
		len = ft_nb_len_base(arg, tab[2]);
	else
		len = ft_nb_len_base2((unsigned long long)arg, tab[2]);
	tmp = len > tab[1] ? len : tab[1];
	if ((f[0] == '#' && (f[4] == 'o' || f[4] == 'O')) || (f[2] && f[4] != '%'))
		tmp++;
	if ((f[0] == '#' && (f[4] == 'x' || f[4] == 'X')) || f[4] == 'p')
		tmp += 2;
	if (!arg && !tab[1])
		tmp--;
	return (tmp);
}

void	print_beg(char *flag, int *tab, int max_char, long long int arg)
{
	if ((!flag[1] || (flag[1] == '0' && tab[1] >= 0)))
		ft_print_n_char(' ', tab[0] - max_char);
	if (flag[2] && flag[4] != '%')
		write(1, &flag[2], 1);
	if ((flag[0] == '#'
				&& (flag[4] == 'X' || flag[4] == 'x')) || flag[4] == 'p')
		flag[4] == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
	if (flag[0] == '#' && (flag[4] == 'o' || flag[4] == 'O'))
		write(1, "0", 1);
	if (flag[1] == '0' && tab[1] == -1)
		ft_print_n_char('0', tab[0] - max_char);
	ft_print_n_char('0', tab[1] - ft_nb_len_base(arg, tab[2]));
}

void	do_nb(char *flag, int *tab, long long int arg)
{
	int		max_char;

	if (!arg && flag[4] != 'o' && flag[4] != 'O')
		flag[0] = 0;
	max_char = get_total_char(arg, flag, tab);
	tab[3] += ft_higher(max_char, ft_higher(tab[0], tab[1]));
	print_beg(flag, tab, max_char, arg);
	if (tab[2] == 16 && flag[4] == 'X')
		tab[2] = 1;
	if (flag[4] == '%')
		write(1, "%", 1);
	if ((arg || tab[1]) && flag[4] != '%')
		ft_get_code(tab[2], arg, flag);
	if (flag[1] == '-' && tab[0] > tab[1])
		ft_print_n_char(' ', tab[0] - max_char);
}

void	ft_get_code(int base, long long int arg, char *flag)
{
	char	*out;

	if (base == 1)
		out = ft_strdup("0123456789ABCDEF");
	else
	{
		out = ft_strdup("0123456789abcdefghijklmonpqrstuvwxyz");
		out[base] = '\0';
	}
	if (ft_get_char("diDI", flag[4]) != -1)
		ft_putnb_base(arg, out);
	else
		ft_putnb_base2((unsigned long long int)arg, out);
	free(out);
}
