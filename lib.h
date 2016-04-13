/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:41:57 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/13 17:04:27 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define OPT_A 1
#define OPT_F 3
#define OPT_T 4
#define OPT_R 8
#define OPT_H 16
#define OPT_I 32
#define OPT_L 64
#define OPT_RCUR 128

typedef	struct	s_list
{
	struct s_list	*next;
	char			*name;
	char			*path;
	struct stat		lstat;
}					t_list;

void	recur_me(t_list **lol);
t_list	*do_dir(char *dir_name);
t_list	*new_node(char *name);
void	new_in_list(char *data, t_list **list);
t_list	*arg_to_list(int ac, char **av);

#endif
