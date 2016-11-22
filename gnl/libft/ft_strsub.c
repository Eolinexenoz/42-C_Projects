/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 20:16:39 by qdupless          #+#    #+#             */
/*   Updated: 2015/12/09 13:57:18 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s)
	{
		str = ft_strnew(len);
		if (str)
		{
			while (s[start] && i < len)
			{
				str[i] = s[start];
				i++;
				start++;
			}
			str[i] = '\0';
		}
		return (str);
	}
	return (NULL);
}
