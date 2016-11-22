/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 19:24:12 by qdupless          #+#    #+#             */
/*   Updated: 2015/12/09 13:56:20 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*list;

	tmp = *alst;
	if (!alst || !del)
		return ;
	while (tmp != NULL)
	{
		list = tmp;
		tmp = tmp->next;
		del(list->content, list->content_size);
		*alst = tmp;
		free(list);
	}
	free(tmp);
	alst = NULL;
}
