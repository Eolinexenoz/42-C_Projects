/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:11:29 by qdupless          #+#    #+#             */
/*   Updated: 2015/12/08 12:04:35 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*map;

	map = f(lst);
	if (!map)
		return (NULL);
	tmp = map;
	while (lst->next)
	{
		lst = lst->next;
		map->next = f(lst);
		if (!map->next)
			return (NULL);
		map = map->next;
	}
	return (tmp);
}
