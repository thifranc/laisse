/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:13:23 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/20 16:29:56 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s1, int c, size_t len)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char*)s1;
	while (i <= len && len != 0)
	{
		s2[i] = (unsigned char)c;
		i++;
	}
	return ((void*)s2);
}
