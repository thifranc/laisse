/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 12:30:55 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/14 10:35:32 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*out;

	if (!(out = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	if (str)
	{
		ft_strcpy(out, str);
		ft_memdel((void*)&str);
	}
	else
		out[0] = '\0';
	return (out);
}
