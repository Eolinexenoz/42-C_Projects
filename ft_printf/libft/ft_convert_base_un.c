/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_un.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 21:42:02 by qdupless          #+#    #+#             */
/*   Updated: 2016/08/07 21:42:04 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_base_un(unsigned int num, unsigned int base)
{
	int				i;
	unsigned int	n;
	unsigned int	mod;
	char			*tab;
	const char		op[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'a', 'b', 'c', 'd', 'e', 'f'};

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
