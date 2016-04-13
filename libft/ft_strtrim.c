/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:05:38 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/20 16:29:30 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*out;
	int		i;
	int		j;
	int		x;

	i = 0;
	x = 0;
	j = ft_strlen(s) - 1;
	if (!(out = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j != -1)
		j--;
	while (i <= j)
	{
		out[x] = s[i];
		x++;
		i++;
	}
	out[x] = '\0';
	return (out);
}
