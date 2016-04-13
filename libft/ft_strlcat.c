/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 16:37:16 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/20 17:08:33 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;

	i = 0;
	while (dst[i] && i < size)
		i++;
	x = i;
	while (src[i - x] && i < size - 1)
	{
		dst[i] = src[i - x];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (x + ft_strlen(src));
}
