/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:29:31 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/07 17:53:39 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int		main(int ac, char **av)
{
	struct stat		lol;
	struct passwd	*mdr;
	struct group	*xd;

	if (ac == 2)
	{
		lstat(av[1], &lol);
		mdr = getpwuid(lol.st_uid);
		xd = getgrgid(lol.st_gid);
		printf("%s == auteur || %s == group || %s == time\n", mdr->pw_name, xd->gr_name);
	}
	return (0);
}
