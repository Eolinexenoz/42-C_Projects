/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_solve2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:57:51 by qdupless          #+#    #+#             */
/*   Updated: 2016/09/30 17:57:52 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prec(t_list_printf *list)
{
	int		preci;

	preci = list->prec;
	if (preci > 0)
	{
		if (list->tab_c)
			preci -= ft_strlen(list->tab_c);
		while (preci != 0)
		{
			ft_putchar('0');
			list->ret++;
			preci--;
		}
	}
}

void	ft_parse_space(t_list_printf *list)
{
	if (ft_strchr(list->fl_opt, ' '))
	{
		ft_putchar(' ');
		list->ret++;
	}
	if (list->k > 0)
		list->k--;
}

void	ft_parse_sp_s(t_list_printf *list)
{
	if (list->k != 0)
	{
		if (list->prec > 0 && list->str && list->prec < ft_strlen(list->str))
			list->k -= (list->prec - ft_strlen(list->str));
		if (list->str && list->boobool == 0)
			list->k -= ft_strlen(list->str);
		else if (!list->str)
			list->k -= 6;
		while (list->k > 0)
		{
			ft_putchar(' ');
			list->ret++;
			list->k--;
		}
	}
}

void	ft_parse_more(t_list_printf *list)
{
	ft_putchar('+');
	list->ret++;
	if (list->k > 0)
		list->k--;
}

void	ft_printf_solve2(va_list ap, t_list_printf *list)
{
	if (ft_strchr(list->fl, 'x'))
	{
		list->ret += ft_printf_x(ap, list);
		if (list->tab_c)
			free(list->tab_c);
	}
	else if (ft_strchr(list->fl, 'X'))
	{
		list->ret += ft_printf_lx(ap, list);
		if (list->tab_c)
			free(list->tab_c);
	}
	else if (ft_strchr(list->fl, 'p'))
	{
		list->ret += ft_printf_p(ap, list);
		if (list->tab_c)
			free(list->tab_c);
	}
	else if (list->b)
	{
		list->ret += ft_printf_percent(list);
		if (list->tab_c)
			free(list->tab_c);
	}
	ft_printf_solve3(ap, list);
}
