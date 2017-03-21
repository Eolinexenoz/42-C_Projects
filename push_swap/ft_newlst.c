#include "push_swap.h"

t_push	*ft_newlst(int d_name)
{
	t_push	*new;

	new = NULL;
	if ((new = ft_memalloc(sizeof(t_push))) != NULL)
	{
		new->name = d_name;
		new->next = NULL;
	}
	return (new);
}

void	ft_addlst(t_push **list, int d_name)
{
	t_push	*tmp;
	t_push	*lst;

	tmp = *list;
	lst = ft_newlst(d_name);
	if (*list == NULL && lst)
		*list = lst;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_newlst(d_name);
	}
}
