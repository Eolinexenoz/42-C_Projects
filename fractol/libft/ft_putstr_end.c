/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 18:47:34 by qdupless          #+#    #+#             */
/*   Updated: 2016/08/04 19:01:42 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_end(char *str, int len)
{
	while (len != -1)
	{
		ft_putchar(str[len]);
		len--;
	}
}