/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:03:13 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/07 17:29:18 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	DIR	*lol;
	struct dirent	*mdr;

	if (ac == 2)
	{
		lol = opendir(av[1]);
		while ((mdr = readdir(lol)) != NULL)
			printf("%s\n", mdr->d_name);
	}
	return (0);
}
