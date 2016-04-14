/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 09:09:52 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/14 10:58:40 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	int		i;
	int		i2;

	if (!(out = (char*)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	i2 = 0;
	while (s2 && s2[i2])
		out[i++] = s2[i2++];
	out[i] = '\0';
	if (s1)
		ft_memdel((void*)&s1);
	if (s2)
		ft_memdel((void*)&s2);
	return (out);
}
