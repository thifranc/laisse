/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 14:53:27 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/12 11:30:59 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t nb)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[i] && i < nb)
	{
		j = 0;
		k = i;
		while (s1[i] == s2[j] && s2[j] && s1[j] && i < nb)
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char*)s1 + k);
		i = k + 1;
	}
	return (NULL);
}
