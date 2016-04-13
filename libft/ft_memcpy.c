/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:30:18 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/12 10:57:00 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*src2;
	char		*dst2;

	i = 0;
	src2 = (char*)src;
	dst2 = (char*)dst;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return ((void*)dst);
}
