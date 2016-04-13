/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:39:05 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/12 15:16:03 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*s2;

	s2 = (const char*)s;
	while (n)
	{
		if (*s2 == (const char)c)
			return ((void*)&(*s2));
		s2++;
		n--;
	}
	return (NULL);
}
