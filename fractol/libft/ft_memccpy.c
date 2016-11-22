/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:59:33 by qdupless          #+#    #+#             */
/*   Updated: 2015/12/09 13:59:42 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dst2;
	const char	*src2;

	i = 0;
	dst2 = dst;
	src2 = src;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (dst2[i] == c)
			return ((void*)&dst2[i] + 1);
		i++;
	}
	return (NULL);
}
