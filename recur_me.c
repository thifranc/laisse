/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:24:06 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/10 10:41:31 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

//pb mettre a jour les path sinon opendir => segfault

void	print_list(t_list *cur)
{
	while (cur)
	{
		printf("%s\n", cur->name);
		cur = cur->next;
	}
	printf("\n");
}

t_list	*do_dir(char *dir_name)
{
	DIR				*lol;
	struct dirent	*mdr;
	t_list			*out;

	lol = opendir(dir_name);
	out = NULL;
	printf("%s:\n", dir_name);
	while ((mdr = readdir(lol)) != NULL)
		new_in_list(mdr->d_name, &out);
	closedir(lol);
	return (out);
}

void	recur_me(t_list *lol, t_list *cur)
{
	t_list	*new;

	if (!cur)
	{
//		printf("erasing////////////\n");
		while (lol)
		{
			new = lol;
			lol = lol->next;
			free(new);
		}
//		printf("fin de recur_me peace out bros\n");
	}
	else if (cur->name[0] == 'd')
	{
//		printf("trouve un repo---------\n");
		new = do_dir(cur->name);
		print_list(new);
		recur_me(new, new);
		recur_me(lol, cur->next);
	}
	else
	{
//		printf("recursing........\n");
		recur_me(lol, cur->next);
	}
}
