/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:29:42 by qdupless          #+#    #+#             */
/*   Updated: 2016/02/12 09:04:40 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst2;
	char	*src2;

	i = 0;
	dst2 = (char*)dst;
	src2 = (char*)src;
	if (src2 < dst2)
	{
		while (++i <= len)
			dst2[len - i] = src2[len - i];
	}
	else
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	return (dst);
}
