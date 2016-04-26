/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 12:30:55 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/26 15:20:28 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *str)
{
	char	*out;
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	if (!(out = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (str)
		ft_strcpy(out, str);
	else
		*out = '\0';
	return (out);
}
