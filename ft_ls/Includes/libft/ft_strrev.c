/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:48:09 by qdupless          #+#    #+#             */
/*   Updated: 2015/12/08 15:57:53 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*tmp;
	char	*tmp2;
	char	c;

	tmp2 = str;
	tmp = str + ft_strlen(str) - 1;
	while (str < tmp)
	{
		c = *str;
		*str++ = *tmp;
		*tmp-- = c;
	}
	return (tmp2);
}
