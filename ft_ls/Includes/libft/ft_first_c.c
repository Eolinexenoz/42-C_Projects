/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:12:40 by qdupless          #+#    #+#             */
/*   Updated: 2016/06/11 17:50:10 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_first_c(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char*)s;
	if (tmp[i])
	{
		if ((char)tmp[i] == (char)c)
			return (0);
	}
	return (1);
}
