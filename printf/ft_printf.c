/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:13:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/06 10:07:14 by thifranc         ###   ########.fr       */
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

void	ft_opt_color(char *str, int *opt)
{
	char	*out;

	out = 0;
	if ((out = ft_strnstr(str, "{red}", 10)) != NULL)
		ft_put("\033[31m");
	else if ((out = ft_strnstr(str, "{yellow}", 10)) != NULL)
		ft_put("\033[33m");
	else if ((out = ft_strnstr(str, "{green}", 10)) != NULL)
		ft_put("\033[32m");
	else if ((out = ft_strnstr(str, "{blue}", 10)) != NULL)
		ft_put("\033[34m");
	if (out)
		*opt = 1;
}

int		ft_printf(char *str, ...)
{
	int			tab[4];
	char		f[5];
	t_data		s;
	int			opt;
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
			opt = 0;
			ft_opt_color(str - 10, &opt);
			ft_get_opt(&str, f, tab);
			get_arg(va, f, tab, s);
			if (opt)
				ft_put("\033[0m");
		}
	}
	va_end(va);
	return (tab[3]);
}
