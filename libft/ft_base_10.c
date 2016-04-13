/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 15:29:20 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/12 15:34:39 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_base_10(char *str, char *base)
{
	int	i;
	int	n;
	int	out;

	i = 0;
	out = 0;
	while (str[i])
	{
		n = 0;
		while (base[n] != str[i] && base[n])
			n++;
		if (base[n] == '\0')
			return (-1);
		out = out * (int)ft_strlen(base) + n;
		i++;
	}
	return (out);
}
