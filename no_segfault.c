/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_segfault.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 12:28:05 by thifranc          #+#    #+#             */
/*   Updated: 2016/04/20 12:30:43 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*get_usr(uid_t id)
{
	struct passwd	*user;

	user = getpwuid(id);
	if (user)
		return (ft_strdup(user->pw_name));
	return (ft_itoa(id));
}

char	*get_grp(gid_t id)
{
	struct group	*grp;

	grp = getgrgid(id);
	if (grp)
		return (ft_strdup(grp->gr_name));
	return (ft_itoa(id));
}
