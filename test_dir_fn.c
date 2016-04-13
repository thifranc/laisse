/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:03:13 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/09 10:39:49 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>

void	do_dir(char *dir_name)
{
	DIR	*lol;
	struct dirent	*mdr;

	lol = opendir(dir_name);
	printf("this is my dir => %s\n", dir_name);
	while ((mdr = readdir(lol)) != NULL)
		printf("%s\n", mdr->d_name);
	closedir(lol);
}

int		main(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		do_dir(av[i]);
		printf("end of dir\n\n");
		i++;
	}
	return (0);
}
