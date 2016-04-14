/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:29:31 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/14 13:44:57 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void	print_it(char *str, ...);

void	get_other_right(mode_t st_mode, char *r)
{
	r[0] = (st_mode & S_IROTH) ? 'r' : '-';
	r[1] = (st_mode & S_IWOTH) ? 'w' : '-';
	if (st_mode & S_ISVTX && st_mode & S_IXOTH)
		r[2] = 's';
	else if (st_mode & S_ISVTX && !(st_mode & S_IXOTH))
		r[2] = 'S';
	else if (st_mode & S_IXOTH)
		r[2] = 'x';
	else
		r[2] = '-';	
}

void	get_grp_right(mode_t st_mode, char *r)
{
	r[0] = (st_mode & S_IRGRP) ? 'r' : '-';
	r[1] = (st_mode & S_IWGRP) ? 'w' : '-';
	if (st_mode & S_ISGID && st_mode & S_IXGRP)
		r[2] = 's';
	else if (st_mode & S_ISGID && !(st_mode & S_IXGRP))
		r[2] = 'S';
	else if (st_mode & S_IXGRP)
		r[2] = 'x';
	else
		r[2] = '-';	
}

char	*get_user_right(mode_t st_mode, char *r)
{
	r[0] = (st_mode & S_IRUSR) ? 'r' : '-';
	r[1] = (st_mode & S_IWUSR) ? 'w' : '-';
	if (st_mode & S_ISUID && st_mode & S_IXUSR)
		r[2] = 's';
	else if (st_mode & S_ISUID && !(st_mode & S_IXUSR))
		r[2] = 'S';
	else if (st_mode & S_IXUSR)
		r[2] = 'x';
	else
		r[2] = '-';	
	get_grp_right(st_mode, r + 3);
	get_other_right(st_mode, r + 6);
	return (r - 1);
}

char	*get_type(mode_t st_mode)
{
	char	*r;

	if (!(r = (char*)malloc(sizeof(char) * 13)))
		return (0);
	if (S_ISBLK(st_mode))
		r[0] = 'b';
	else if (S_ISCHR(st_mode))
		r[0] = 'c';
	else if (S_ISDIR(st_mode))
		r[0] = 'd';
	else if (S_ISLNK(st_mode))
		r[0] = 'l';
	else if (S_ISSOCK(st_mode))
		r[0] = 's';
	else if (S_ISFIFO(st_mode))
		r[0] = 'p';
	else if (S_ISREG(st_mode))
		r[0] = '-';
	get_user_right(st_mode, r + 1);
	return (r);
}

void	get_info(char *path_file)
{
	struct stat		lol;
	struct passwd	*mdr;
	struct group	*xd;

	lstat(path_file, &lol);
	mdr = getpwuid(lol.st_uid);
	xd = getgrgid(lol.st_gid);
	print_it("name: %s\nauteur: %s\ngroup: %s\ninode: %d\nnb_link: %d\nsize: %d\nrights: %s\n", path_file, mdr->pw_name, xd->gr_name, lol.st_ino, lol.st_nlink, lol.st_size, get_type(lol.st_mode));
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
