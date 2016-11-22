/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_l.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 15:48:47 by qdupless          #+#    #+#             */
/*   Updated: 2016/09/16 15:48:50 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_base_l(long num, long base)
{
	int			i;
	long		n;
	long		mod;
	char		*tab;
	const char	op[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a',
	'b', 'c', 'd', 'e', 'f'};

	i = 0;
	n = num;
	while (n != 0)
	{
		mod = n % base;
		n = n / base;
		i++;
	}
	tab = ft_strnew(i);
	i = 0;
	n = num;
	while (n != 0)
	{
		mod = n % base;
		n = n / base;
		tab[i++] = op[mod];
	}
	return (num == 0) ? ft_strdup("0") : tab;
}
