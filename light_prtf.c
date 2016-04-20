/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_prtf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 11:50:27 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/20 10:33:01 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

char	*do_nb(int opt, int max, va_list va)
{
	char	*out;
	int		arg;
	int		i;

	i = 0;
	arg = va_arg(va, int);
	max = max ? max : ft_nb_len_base(arg, 10);
	if (!(out = malloc(max + 1)))
		return (NULL);
	out[max] = '\0';
	while (i < max)
		out[i++] = ' ';
	i = opt ? ft_nb_len_base(arg, 10) : max;
	if (arg == 0)
		out[i - 1] = '0';
	while (arg)
	{
		out[--i] = arg % 10 + 48;
		arg /= 10;
	}
	return (out);
}

char	*do_string(int opt, int max, va_list va)
{
	char	*out;
	char	*arg;
	int		i;
	int		len;

	i = 0;
	arg = va_arg(va, char *);
	len = ft_strlen(arg);
	max = max ? max : len;
	if (!(out = malloc(max + 1)))
		return (NULL);
	out[max] = '\0';
	while (i < max)
		out[i++] = ' ';
	i = opt ? len : max;
	while (len > 0)
		out[--i] = arg[--len];
	return (out);
}

char	*get_opt_and_arg(char **s, va_list va)
{
	int		opt;
	int		max;

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

char	*get_till_opt(char **str)
{
	int		i;
	char	*out;

	i = 0;
	while ((*str)[i] && (*str)[i] != '%')
		i++;
	if (!(out = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (**str && **str != '%')
	{
		out[i++] = **str;
		(*str)++;
	}
	out[i] = '\0';
	return (out);
}

char	*print_it(char *str, ...)
{
	va_list	va;
	char	*out;
	char	*tmp;
	char	*tmp2;

	va_start(va, str);
	out = NULL;
	while (*str)
	{
		tmp = get_till_opt(&str);
		if (!out)
			tmp2 = ft_strdup(out);
		else
			tmp2 = ft_strdup_del(out);
		out = ft_strjoin_del(tmp2, tmp, 2);
		if (*str && *str == '%')
		{
			tmp = get_opt_and_arg(&str, va);
			str++;
			tmp2 = ft_strdup_del(out);
			out = ft_strjoin_del(tmp2, tmp, 2);
		}
	}
	va_end(va);
	return (out);
}
