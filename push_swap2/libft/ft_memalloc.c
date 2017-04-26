/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:04:42 by qdupless          #+#    #+#             */
/*   Updated: 2015/11/30 20:04:00 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*zone;

	if (size == 0)
		return (NULL);
	if ((zone = (void*)malloc(sizeof(*zone) * size)) == NULL)
		return (NULL);
	ft_bzero(zone, size);
	return (zone);
}
