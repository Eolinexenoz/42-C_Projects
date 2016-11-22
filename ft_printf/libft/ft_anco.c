/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anco.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:34:18 by qdupless          #+#    #+#             */
/*   Updated: 2016/09/22 16:34:29 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_anco(const char *s1, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			j++;
		i++;
	}
	return (j);
}
