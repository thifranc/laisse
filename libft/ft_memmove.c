/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:32:45 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/12 16:40:31 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*out;

	if (!(out = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	ft_memcpy(out, src, len);
	ft_memcpy(dst, out, len);
	ft_memdel((void**)&out);
	return (dst);
}
