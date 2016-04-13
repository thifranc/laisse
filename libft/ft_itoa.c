/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 15:39:04 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/12 16:14:45 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_len(int n)
{
	if (0 <= n && n <= 9)
		return (1);
	else
		return (1 + ft_nb_len(n / 10));
}

static int	ft_sign(int *n)
{
	if (*n < 0)
	{
		*n = -*n;
		return (1);
	}
	else
		return (0);
}

char		*ft_itoa(int n)
{
	int		size;
	int		sign;
	char	*out;

	if (n == -2147483647 - 1)
		return (ft_strdup("-2147483648"));
	sign = ft_sign(&n);
	size = ft_nb_len(n) + sign;
	if (!(out = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	out[size] = '\0';
	while (size--)
	{
		out[size] = n % 10 + 48;
		n /= 10;
	}
	if (sign == 1)
		out[0] = '-';
	return (out);
}
