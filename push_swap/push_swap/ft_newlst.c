/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:31:54 by qdupless          #+#    #+#             */
/*   Updated: 2017/04/01 13:31:56 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_list_size(t_push **list)
{
	t_push	*tmp;
	int		i;

	i = 0;
	tmp = *list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
