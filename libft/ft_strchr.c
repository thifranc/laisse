/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 12:16:45 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/20 16:28:23 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int c)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char*)s1;
	while (s2[i])
	{
		if (s2[i] == (char)c)
			return (&s2[i]);
		i++;
	}
	if (s2[i] == (char)c)
		return (&s2[i]);
	else
		return (NULL);
}
