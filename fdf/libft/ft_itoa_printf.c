/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 22:13:20 by qdupless          #+#    #+#             */
/*   Updated: 2016/09/19 22:13:21 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nbrlen(intmax_t n)
{
	int		i;
	int		nb;

	i = 0;
	nb = n;
	if (n == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa_printf(intmax_t n)
{
	intmax_t		val;
	int				len;
	char			*str;

	val = n;
	len = ft_nbrlen(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		if (n < 0)
		{
			str[len] = (n % 10) * -1 + 48;
			n /= 10;
		}
		else
		{
			str[len] = (n % 10) + 48;
			n /= 10;
		}
	}
	return (str);
}
