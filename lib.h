/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:41:57 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/10 12:23:17 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef	struct	s_list
{
	struct s_list	*next;
	char			*name;
	char			*path;
	struct stat		lstat;
}					t_list;

void	recur_me(t_list *lol, t_list *cur);
t_list	*do_dir(char *dir_name);
t_list	*new_node(char *name);
void	new_in_list(char *data, t_list **list);
t_list	*arg_to_list(int ac, char **av);
int		main(int ac, char **av);
