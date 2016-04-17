/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:41:57 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/17 10:10:47 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
#define LIB_H

#include "libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#define OPT_A 1
#define OPT_F 3
#define OPT_T 4
#define OPT_R 8
#define OPT_H 16
#define OPT_I 32
#define OPT_L 64
#define OPT_RCUR 128
#define DR_SON "."
#define DR_FAT ".."

typedef	struct		s_list
{
	struct s_list	*next;
	char			*name;
	char			*path;
	struct stat		lstat;
}					t_list;

char	*get_date(time_t t);
int		timed(t_list *a, t_list *b);
int		ascii(t_list *a, t_list *b);
void	ft_list_reverse(t_list **begin_list);
int		get_opt(char *s);
t_list	*list_at(t_list *list, int nb);
int		list_size(t_list *list);
int		strcmp3(char *s1, char *s2);
t_list	*div_int_two(t_list **list);
void	recur_sort(t_list **list, int opt);
t_list	*fusion(t_list *a, t_list *b, int (*f)(t_list *, t_list *));
void	print_list(t_list *node, int opt);
void	recur_me(t_list **lol, int opt);
t_list	*do_dir(char *dir_name);
t_list	*new_node(char *name);
void	new_in_list(char *data, t_list **list);
t_list	*arg_to_list(int ac, char **av, int opt);
char	*print_it(char *str, ...);
char	*get_type(mode_t st_mode);
char	*get_user_right(mode_t st_mode, char *r);
void	get_grp_right(mode_t st_mode, char *r);
void	get_other_right(mode_t st_mode, char *r);

#endif
