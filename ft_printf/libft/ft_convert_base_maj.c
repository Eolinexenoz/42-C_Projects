/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_maj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 16:10:23 by qdupless          #+#    #+#             */
/*   Updated: 2016/08/07 21:56:13 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_base_maj(uintmax_t num, uintmax_t base)
{
	int				i;
	uintmax_t		n;
	uintmax_t		mod;
	char			*tab;
	const char		op[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F'};

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
