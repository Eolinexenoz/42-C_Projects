/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:15:46 by qdupless          #+#    #+#             */
/*   Updated: 2016/09/30 16:15:48 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_less(t_list_printf *list)
{
	if (list->k > 0)
	{
		if (ft_strchr(list->fl, 'S'))
			ft_wcharlen(list);
		if (list->max < 0 && list->max)
			list->k--;
		if (list->prec > 0 && list->tab_c)
			list->k -= (list->prec - ft_strlen(list->tab_c));
		if (list->prec > 0 && list->str && list->prec < ft_strlen(list->str))
			list->k -= (list->prec - ft_strlen(list->str));
		if (list->tab_c)
			list->k -= ft_strlen(list->tab_c);
		else if (list->str)
			list->k -= ft_strlen(list->str);
		if (!list->str && ft_strchr(list->fl, 's'))
			list->k -= 6;
		while (list->k > 0)
		{
			ft_putchar(' ');
			list->ret++;
			list->k--;
		}
	}
}

void	ft_parse_diez(t_list_printf *list)
{
	if (ft_strchr(list->fl, 'o'))
	{
		ft_putchar('0');
		list->ret++;
		list->prec--;
	}
	else if (ft_strchr(list->fl, 'O'))
	{
		ft_putchar('0');
		list->ret++;
		list->prec--;
	}
	else if (ft_strchr(list->fl, 'x'))
	{
		ft_putstr("0x");
		list->ret += 2;
	}
	else if (ft_strchr(list->fl, 'X'))
	{
		ft_putstr("0X");
		list->ret += 2;
	}
}

void	ft_parse_sp(t_list_printf *list)
{
	if (list->k > 0)
	{
		if (ft_strchr(list->fl, 'S') && list->wstr && list->boobool == 0)
			ft_wcharlen(list);
		if (list->tab_c && list->prec > 0 && list->k > list->prec \
			&& list->prec > ft_strlen(list->tab_c))
			list->k -= (list->prec - ft_strlen(list->tab_c));
		if (list->k < list->prec && list->k > 0 && ft_anco(list->fl, '%') < 2)
			list->k = 0;
		if (ft_strchr(list->fl_opt, '+'))
			list->k--;
		if (list->max < 0 && !(ft_strchr(list->fl_opt, '+')))
			list->k--;
		if (list->tab_c && list->boobool == 0)
			list->k -= ft_strlen(list->tab_c);
		while (list->k > 0)
		{
			ft_putchar(' ');
			list->ret++;
			list->k--;
		}
	}
}

void	ft_parse_0(t_list_printf *list)
{
	if (list->k > 0)
	{
		if (ft_strchr(list->fl, 'S') && list->wstr && list->boobool == 0)
			ft_wcharlen(list);
		if (list->tab_c && list->prec > ft_strlen(list->tab_c))
			list->k -= list->prec;
		if (ft_strchr(list->fl_opt, '-'))
			list->k--;
		if (list->max < 0)
			list->k--;
		if (list->str)
			list->k -= ft_strlen(list->str);
		if (list->tab_c)
			list->k -= ft_strlen(list->tab_c);
		while (list->k > 0)
		{
			ft_putchar('0');
			list->ret++;
			list->k--;
		}
	}
}

void	ft_printf_solve(va_list ap, t_list_printf *list)
{
	ft_get_modif(ap, list);
	if (ft_strchr(list->fl, 'C'))
		list->ret += ft_utfchar(ap, list);
	else if (ft_strchr(list->fl, 'S'))
		list->ret += ft_put_wchar(ap, list);
	else if (ft_strchr(list->fl, 's') && !(ft_strchr(list->fl_size, 'l')))
		list->ret += ft_printf_s(ap, list);
	else if (ft_strchr(list->fl, 'c') && !(ft_strchr(list->fl_size, 'l')))
		list->ret += ft_printf_char(ap, list);
	else if (ft_strchr(list->fl, 'd') || ft_strchr(list->fl, 'i'))
	{
		list->ret += ft_printf_di(ap, list);
		if (list->tab_c)
			free(list->tab_c);
	}
	else if (ft_strchr(list->fl, 'D'))
	{
		list->ret += ft_printf_ld(ap, list);
		if (list->tab_c)
			free(list->tab_c);
	}
	else
		ft_printf_solve2(ap, list);
}
