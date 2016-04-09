/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:29:31 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/09 11:27:37 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void	get_info(char *path_file)
{
	struct stat		lol;
	struct passwd	*mdr;
	struct group	*xd;

	lstat(path_file, &lol);
	mdr = getpwuid(lol.st_uid);
	xd = getgrgid(lol.st_gid);
	printf("name: %s\nauteur: %s\ngroup: %s\ninode: %lld\nnb_link: %d\nsize: %lld\n", path_file, mdr->pw_name, xd->gr_name, lol.st_ino, lol.st_nlink, lol.st_size);
}

int		main(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		get_info(av[i]);
		printf("next file\n\n");
		i++;
	}
	return (0);
}
