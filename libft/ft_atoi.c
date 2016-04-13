/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 11:52:58 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/20 10:28:30 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int i;
	int flag;
	int nb;
	int tmp;

	i = 0;
	nb = 0;
	flag = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == ' '
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
		flag = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9' && str[i])
	{
		tmp = str[i] - 48;
		nb = nb * 10 + tmp;
		i++;
	}
	if (flag == 1)
		nb = -nb;
	return (nb);
}
