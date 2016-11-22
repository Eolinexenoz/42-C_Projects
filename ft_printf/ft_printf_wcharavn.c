/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wcharavn.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 21:18:47 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/06 21:18:52 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_utfchar(t_list_printf *list)
{
	if (list->win < 65536)
	{
		ft_putchar(224 | (list->win >> 12));
		ft_putchar(128 | ((list->win >> 6) & 63));
		ft_putchar(128 | (list->win & 63));
		list->ret += 3;
	}
	else
	{
		ft_putchar(240 | (list->win >> 18));
		ft_putchar(128 | ((list->win >> 12) & 63));
		ft_putchar(128 | ((list->win >> 6) & 63));
		ft_putchar(128 | (list->win & 63));
		list->ret += 4;
	}
}

int		ft_utfchar(va_list ap, t_list_printf *list)
{
	list->win = va_arg(ap, wint_t);
	if (!list->win)
		return (1);
	if (ft_anco(list->fl_size, 'h') == 2)
		return (ft_count_wint_t(list));
	if (list->win >= 1114112)
		list->ret += 0;
	if (list->win < 128)
	{
		ft_putchar(list->win);
		list->ret += 1;
	}
	else if (list->win < 2048)
	{
		ft_putchar(192 | (list->win >> 6));
		ft_putchar(128 | (list->win & 63));
		list->ret += 2;
	}
	else
		ft_printf_utfchar(list);
	return (0);
}

void	ft_count_wint(t_list_printf *list)
{
	int		i;

	i = 0;
	if (list->wstr[i] >= 1114112)
		list->precwchar += 0;
	else if (list->wstr[i] < 128)
		list->precwchar += 1;
	else if (list->wstr[i] < 2048)
		list->precwchar += 2;
	else if (list->wstr[i] < 65536)
		list->precwchar += 3;
	else
		list->precwchar += 4;
}

int		ft_count_wint_t(t_list_printf *list)
{
	if (list->win >= 1114112)
		list->ret += 0;
	else if (list->win < 128)
		list->ret += 1;
	else if (list->win < 2048)
		list->ret += 2;
	else if (list->win < 65536)
		list->ret += 3;
	else
		list->ret += 4;
	return (0);
}
