/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_prtf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 11:50:27 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/13 16:20:24 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

char	*get_till_opt(char **str)
{
	int		i;
	char	*out;

	i = 0;
	while (*str[i] != '%')
		i++;
	if (!(out = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (**str != '%')
	{
		out[i] = **str;
		(*str)++;
	}
	out[i] = '\0';
	return (out);
}

char	*get_opt_and_arg(char **s, va_list va)
{
	int				opt;
	int				max;
	int				d_arg;
	char			*s_arg;

	opt = 0;
	max = 0;
	(*s)++;
	if (**s == '-')
	{
		opt = 1;
		(*s)++;
	}
	if (**s == '*')
	{
		max = va_arg(va, int);
		(*s)++;
	}
	if (**s == 's')
		return (do_string(opt, max, va));
	else
		return (do_nb(opt, max, va));
}

int		get_blank(int opt, char *out, int max, int len)
{
	int		end;
	int		i;

	end = (max > len ? max : len) - 1;
	i = 0;
	if (!opt)
	{
		while ((max - i) > len)
			out[i++] = ' ';
		return (end);
	}
	else
	{
		while ((max - i) > len)
			out[end - i++] = ' ';
	}
	return (end - (max - len));
}

char	*do_nb(int opt, int max)
{
	char	*out;
	int		arg;
	int		len;
	int		k;

	arg = va_arg(va, int);
	len = ft_nb_len_base(arg, 10);
	if (!(out = malloc(sizeof * (max > len ? max : len) + 1)))
		return (NULL);
	out[max > len ? max : len] = '\0';
	k = get_blank(opt, out, max, len);
	if (arg == 0)
		out[0] = '0';
	while (arg)
	{
		out[k] = arg % 10 + 48;
		arg /= 10;
		k--;
	}
	return (out);
}

char	*do_string(int opt, int max)
{
	char	*out;
	char	*arg;
	int		i;
	int		k;

	i = 0;
	arg = va_arg(va, const char *);
	len = ft_strlen(arg);
	if (!(out = malloc(sizeof * (max > len ? max : len) + 1)))
		return (NULL);
	out[max > len ? max : len] = '\0';
	k = get_blank(opt, out, max, len);
	while (len)
		out[k--] = arg[len--];
	return (out);
}

void	print_it(char *str, ...)
{
	va_list	va;

	va_start(va, str);
	while (*str)
	{
		out = get_till_opt(&str);
		tmp = get_opt_and_arg(&str);
		tmp2 = ft_strdup(out);
		ft_memdel((void*)&out);
		out = ft_strjoin(tmp2, tmp);
		ft_memdel((void*)&tmp);
		ft_memdel((void*)&tmp2);
	}
	va_end(va);
	write(1, out, ft_strlen(out));
}
