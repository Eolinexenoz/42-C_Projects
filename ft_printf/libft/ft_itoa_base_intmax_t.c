/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_intmax_t.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:00:58 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/06 21:37:21 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(intmax_t num, intmax_t base)
{
	int		i;

	i = 0;
	if (num < 0)
		i++;
	while (num != 0)
	{
		num /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base_intmax_t(intmax_t num, intmax_t base)
{
	int			i;
	intmax_t	n;
	intmax_t	mod;
	char		*tab;
	const char	op[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a',
	'b', 'c', 'd', 'e', 'f'};

	i = 0;
	n = num;
	i = ft_count(num, base);
	n = n * -1;
	tab = ft_strnew(i);
	if (n < 0)
		tab[0] = '-';
	while (n != 0)
	{
		mod = n % base;
		n = n / base;
		tab[--i] = op[mod];
	}
	ft_putendl(tab);
	return (num == 0) ? ft_strdup("0") : tab;
}
