/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:14:37 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/20 17:56:42 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wrd_ct(char const *s, char c)
{
	int i;
	int ct;

	i = 0;
	ct = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			ct++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (ct);
}

static char		**ft_get_let(char const *s, char c, char **out)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		x = 0;
		while (s[i] && s[i] != c)
		{
			out[y][x] = s[i];
			i++;
			x++;
		}
		out[y][x] = '\0';
		y++;
	}
	if (s[i - 1] == c)
		y--;
	out[y] = NULL;
	return (out);
}

char			**ft_strsplit(char const *s, char c)
{
	int		x;
	int		y;
	char	**out;
	int		i;

	y = 0;
	i = 0;
	if (!(out = (char**)malloc(sizeof(char*) * (ft_wrd_ct(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		x = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			x++;
		}
		if (!(out[y] = (char*)malloc(sizeof(char) * (x + 1))))
			return (NULL);
		y++;
	}
	return (ft_get_let(s, c, out));
}
