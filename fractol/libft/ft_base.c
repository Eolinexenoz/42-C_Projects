/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 14:38:13 by qdupless          #+#    #+#             */
/*   Updated: 2016/08/04 16:07:09 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_base(int num, int base)
{
	int		i;
	int		j;
	int		n;
	int		mod;
	int		*digit;

	i = 0;
	n = num;
	j = 0;
	while (n != 0)
	{
		mod = n % base;
		n = n / base;
		j++;
	}
	digit = (int*)malloc(sizeof(j));
	digit[j + 1] = '\0';
	while (num != 0)
	{
		mod = num % base;
		num = num / base;
		digit[i] = mod;
		i++;
	}
	return (digit);
}
