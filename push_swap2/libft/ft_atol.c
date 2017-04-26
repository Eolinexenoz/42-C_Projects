/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:57:30 by qdupless          #+#    #+#             */
/*   Updated: 2017/04/25 12:57:31 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atol(const char *nptr)
{
	long	i;
	long	nb;
	long	nbn;

	i = 0;
	nb = 0;
	nbn = 1;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\r' || \
				nptr[i] == '\v' || nptr[i] == '\t' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			nbn = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i] - 48);
		i++;
	}
	return (nb * nbn);
}
