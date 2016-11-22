/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 08:50:16 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/14 08:50:18 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_sqrt(int n)
{
	double	a;
	double	x;
	int		i;
	float	tmp;

	a = (double)n;
	x = 1;
	i = 0;
	tmp = 0.5;
	while (i < n)
	{
		x = 0.5 * (x + a / x);
		i++;
	}
	tmp += x;
	if ((tmp - x) > 0.000001)
		return ((int)x + 1);
	else
		return ((int)x);
}
