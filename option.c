/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 11:11:51 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/20 17:47:53 by thifranc         ###   ########.fr       */
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
	else if (c == 'u')
		*out = *out | OPT_U;
}

t_list	*error_dir(char *str)
{
	ft_putstr("ls: ");
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

int		hay_arg(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac && av[i] && av[i][0] == '-')
		i++;
	if (i == ac)
		return (0);
	return (1);
}

int		get_opt(int ac, char **av)
{
	int		out;
	int		i;
	int		k;
	char	*s;

	out = 0;
	k = 1;
	while (k < ac && av[k] && av[k][0] == '-')
	{
		s = av[k];
		i = 1;
		while (s[i] && (ft_get_char("zucraRtflih", s[i]) != -1))
		{
			option_check(&out, s[i]);
			i++;
		}
		if (s[i])
			illegal_option(&s[i]);
		k++;
	}
	return (out);
}
