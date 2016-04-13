/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:53:24 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/20 16:29:51 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	i = 0;
	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == (unsigned char)c)
			return ((void*)dst2 + i + 1);
		i++;
	}
	return (NULL);
}
