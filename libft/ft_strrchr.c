/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 12:21:10 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/20 16:29:22 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s1, int c)
{
	int i;

	i = ft_strlen(s1);
	while (i != -1)
	{
		if (s1[i] == (char)c)
			return ((char*)&s1[i]);
		i--;
	}
	return (NULL);
}
