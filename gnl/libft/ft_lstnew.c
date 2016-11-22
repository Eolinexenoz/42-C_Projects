/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:35:46 by qdupless          #+#    #+#             */
/*   Updated: 2015/12/09 13:55:18 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == 0)
	{
		tmp->content = NULL;
		tmp->next = NULL;
		tmp->content_size = 0;
		return (tmp);
	}
	else
	{
		tmp->content = (void*)malloc(content_size);
		tmp->content_size = content_size;
		tmp->content = ft_memmove(tmp->content, content, content_size);
		tmp->next = NULL;
	}
	return (tmp);
}
