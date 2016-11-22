/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:58:42 by qdupless          #+#    #+#             */
/*   Updated: 2015/12/08 18:14:47 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *zone;

	if (!(zone = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_strclr(zone);
	return (zone);
}
