/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:29:31 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/07 17:46:05 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <pwd.h>

int		main(int ac, char **av)
{
	struct stat		lol;
	struct passwd	*mdr;

	if (ac == 2)
	{
		lstat(av[1], &lol);
		mdr = getpwuid(lol.st_uid);
		printf("%s\n", mdr->pw_name);
	}
	return (0);
}
