/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_prtf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 11:50:27 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/16 10:07:35 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

int		get_blank(int opt, char *out, int max, int len)
{
	int		end;
	int		i;

	end = (max > len ? max : len);
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
	return (end - (max - len));//pb si max = 0 et len > 0;
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

char	*do_nb(int opt, int max, va_list va)
{
	char	*out;
	int		arg;
	int		len;
	int		k;

	arg = va_arg(va, int);
	len = ft_nb_len_base(arg, 10);
	if (!(out = malloc((max > len ? max : len) + 1)))
		return (NULL);
	out[max > len ? max : len] = '\0';
	k = get_blank(opt, out, max, len) - 1;
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

char	*do_string(int opt, int max, va_list va)
{
	char	*out;
	char	*arg;
	int		i;
	int		k;
	int		len;

	i = 0;
	arg = va_arg(va, char *);
	len = ft_strlen(arg);
	if (!(out = malloc((max > len ? max : len) + 1)))
		return (NULL);
	out[max > len ? max : len] = '\0';
	k = get_blank(opt, out, max, len);
	while (len > -1)
		out[k--] = arg[len--];
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

void	print_it(char *str, ...)
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
		tmp2 = ft_strdup(out);
		out = ft_strjoin(tmp2, tmp);
		if (*str && *str == '%')
		{
			tmp = get_opt_and_arg(&str, va);
			str++;
			tmp2 = ft_strdup(out);
			out = ft_strjoin(tmp2, tmp);
		}
	}
	va_end(va);
	write(1, out, ft_strlen(out));
}
