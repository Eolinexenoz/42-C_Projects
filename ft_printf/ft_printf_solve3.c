/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_solve3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 12:43:02 by qdupless          #+#    #+#             */
/*   Updated: 2016/10/05 12:43:05 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_modif(va_list ap, t_list_printf *list)
{
	list->has_mod = 1;
	if (ft_strchr(list->fl_size, 'j') && !(ft_strchr(list->fl, 'p')))
		list->max = (uintmax_t)va_arg(ap, uintmax_t);
	else if (ft_strchr(list->fl_size, 'z'))
		list->max = va_arg(ap, size_t);
	else if (ft_strchr(list->fl_size, 'l') && (ft_anco(list->fl_size, 'l') \
	== 2) && !(ft_strchr(list->fl, 'p')))
		list->max = (long long int)va_arg(ap, long);
	else if (ft_strchr(list->fl_size, 'l') && ft_strchr(list->fl, 'c') && \
		!(ft_strchr(list->fl, 'p')))
		list->ret += ft_utfchar(ap, list);
	else if (ft_strchr(list->fl_size, 'l') && ft_strchr(list->fl, 's') && \
		!(ft_strchr(list->fl, 'p')))
		list->ret += ft_put_wchar(ap, list);
	else if (ft_strchr(list->fl_size, 'l') && (!(ft_anco(list->fl_size, 'l') \
		== 2)) && !(ft_strchr(list->fl, 'p')))
		list->max = (long int)va_arg(ap, long);
	else if (ft_strchr(list->fl_size, 'h') && (!(ft_anco(list->fl_size, 'h') \
	== 2)) && !(ft_strchr(list->fl, 'p')))
		list->max = (unsigned short int)va_arg(ap, int);
	else if (ft_strchr(list->fl_size, 'h') && (ft_anco(list->fl_size, 'h') \
	== 2) && !(ft_strchr(list->fl, 'p')) && !(ft_strchr(list->fl, 'S')))
		list->max = (char)va_arg(ap, int);
	else
		list->has_mod = 0;
}

void	ft_printf_solve3(va_list ap, t_list_printf *list)
{
	if (ft_strchr(list->fl, 'o'))
	{
		list->ret += ft_printf_o(ap, list);
		if (list->tab_c)
			free(list->tab_c);
	}
	else if (ft_strchr(list->fl, 'O'))
	{
		list->ret += ft_printf_lo(ap, list);
		if (list->tab_c)
			free(list->tab_c);
	}
	else if (ft_strchr(list->fl, 'u'))
	{
		list->ret += ft_printf_u(ap, list);
		if (list->tab_c)
			free(list->tab_c);
	}
	else if (ft_strchr(list->fl, 'U'))
	{
		list->ret += ft_printf_lu(ap, list);
		if (list->tab_c)
			free(list->tab_c);
	}
}
