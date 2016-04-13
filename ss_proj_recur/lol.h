
#ifndef LOL_H
#define LOL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	char			*data;
	int				val;
}				t_list;

void	recur_sort(t_list **list);
t_list	*fusion(t_list *a, t_list *b);
t_list	*list_at(t_list *b, int nb);
int		list_size(t_list *list);

#endif
