/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:18:02 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/18 17:24:56 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_del(const char *str)
{
	char	*out;
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	if (!(out = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (str)
	{
		ft_strcpy(out, str);
		ft_memdel((void*)&str);
	}
	else
		*out = '\0';
	return (out);
}
