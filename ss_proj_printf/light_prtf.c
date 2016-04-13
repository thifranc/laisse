/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_prtf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 11:50:27 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/13 13:02:22 by thifranc         ###   ########.fr       */
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

char	*get_opt_and_arg(char **str)
{
	int		opt;

	opt = 0;
	(*str)++;
	if (**s == '-')
	{
		opt = | 128;
		(*s)++;
	}

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
