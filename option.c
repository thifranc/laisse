/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 11:11:51 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/20 08:51:10 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	option_check(int *out, char c)
{
	if (c == 'a')
		*out = *out | OPT_A;
	else if (c == 'f')
		*out = *out | OPT_F;
	else if (c == 't')
		*out = *out | OPT_T;
	else if (c == 'r')
		*out = *out | OPT_R;
	else if (c == 'h')
		*out = *out | OPT_H;
	else if (c == 'i')
		*out = *out | OPT_I;
	else if (c == 'l')
		*out = *out | OPT_L;
	else if (c == 'R')
		*out = *out | OPT_RCUR;
	else if (c == 'c')
		*out = *out | OPT_C;
	else if (c == 'b')
		*out = *out | OPT_U;
	else if (c == 'z')
		*out = *out | OPT_COL;
}

t_list	*error_dir(char *str)
{
	perror(str);
	return (NULL);
}

void	illegal_option(char *c)
{
	char	*out;

	out = print_it("ls: illegl option -- %s\nusage: ls -[opt][file...]", c);
	ft_putstr(out);
	exit(-1);
}

int		get_opt(char *s)
{
	int		out;
	int		i;

	out = 0;
	i = 0;
	if (!s || s[0] != '-')
		return (out);
	i++;
	while (s[i] && (ft_get_char("zucraRtflih", s[i]) != -1))
	{
		option_check(&out, s[i]);
		i++;
	}
	if (!s[i])
		return (out);
	s[i + 1] = '\0';
	illegal_option(&s[i]);
	return (0);
}
