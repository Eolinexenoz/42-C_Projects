/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alex_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:23:28 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/06 21:39:21 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charlen(intmax_t n, size_t base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	else
		while (n > 0)
		{
			n /= base;
			i++;
		}
	return (i);
}

char		*ft_ultoabase(intmax_t n, size_t base)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(ft_charlen(n, base));
	if (n == -9223372036854775807 - 1)
		return (ft_strdup("9223372036854775808"));
	if (tmp == NULL)
		return (NULL);
	if (n == 0)
		tmp[i++] = '0';
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		tmp[i++] = (n % base) > 9 ? (n % base) - 10 + 'a' : (n % base) + '0';
		n /= base;
	}
	tmp[i] = '\0';
	ft_strrev(tmp);
	return (tmp);
}
