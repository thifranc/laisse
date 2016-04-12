/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:13:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/12 15:49:12 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_clear_all(int *tab, char *flag, t_data *s)
{
	int		i;

	i = -1;
	while (++i < 3)
		tab[i] = 0;
	i = -1;
	while (++i < 5)
		flag[i] = 0;
	(*s).s_spe = 0;
	(*s).c_spe = 0;
	(*s).s = 0;
	(*s).c = 0;
}

int		ft_strlen_char(const char *s, char b)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != b)
		i++;
	return (i);
}

int		ft_strcount(const char *s, char b)
{
	write(1, s, ft_strlen_char(s, b));
	return (ft_strlen_char(s, b));
}

int		ft_printf(char *str, ...)
{
	int			tab[4];
	char		f[5];
	t_data		s;
	va_list		va;

	va_start(va, str);
	tab[3] = 0;
	while (*str)
	{
		tab[3] += ft_strcount(str, '%');
		str += ft_strlen_char(str, '%');
		ft_clear_all(tab, f, &s);
		if (*str)
		{
			ft_get_opt(&str, f, tab);
			get_arg(va, f, tab, s);
		}
	}
	va_end(va);
	return (tab[3]);
}
