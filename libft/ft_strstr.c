/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 12:41:48 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/20 16:29:24 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1)
	{
		if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
