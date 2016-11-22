/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wcharlen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 21:15:54 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/06 21:16:05 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wcharlen3(t_list_printf *list, int i)
{
	if (list->wstr[i] < 65536)
	{
		list->len += 3;
		if (list->prec > 0 && list->len > list->prec)
		{
			list->bobo = 1;
			list->len -= 3;
			list->k -= list->len;
			return ;
		}
	}
	else if (list->wstr[i] >= 65536 && list->wstr[i] < 1114112)
	{
		list->len += 4;
		if (list->prec > 0 && list->len > list->prec)
		{
			list->bobo = 1;
			list->len -= 4;
			list->k -= list->len;
			return ;
		}
	}
}

void	ft_wcharlen2(t_list_printf *list, int i)
{
	if (list->wstr[i] >= 1114112)
		list->len += 0;
	if (list->wstr[i] < 128)
	{
		list->len++;
		if (list->prec > 0 && list->len > list->prec)
		{
			list->bobo = 1;
			list->len -= 1;
			list->k -= list->len;
			return ;
		}
	}
	else if (list->wstr[i] < 2048)
	{
		list->len += 2;
		if (list->prec > 0 && list->len > list->prec)
		{
			list->bobo = 1;
			list->len -= 2;
			list->k -= list->len;
			return ;
		}
	}
}

void	ft_wcharlen(t_list_printf *list)
{
	int		i;

	i = 0;
	while (list->wstr[i])
	{
		if (list->wstr[i] < 2048)
			ft_wcharlen2(list, i);
		else
			ft_wcharlen3(list, i);
		if (list->bobo == 1)
			return ;
		i++;
	}
	list->k -= list->len;
}
