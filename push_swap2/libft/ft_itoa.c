/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:30:53 by qdupless          #+#    #+#             */
/*   Updated: 2015/12/08 17:04:37 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nbrlen(int n)
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
	if (n < 0)
		return (i + 1);
	else
		return (i);
}

char			*ft_itoa(int n)
{
	int		val;
	int		len;
	char	*str;

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
	if (val < 0)
		str[0] = '-';
	return (str);
}
