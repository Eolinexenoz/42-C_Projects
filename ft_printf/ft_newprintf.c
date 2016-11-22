/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 17:04:59 by qdupless          #+#    #+#             */
/*   Updated: 2016/09/20 17:05:01 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_list_printf *list)
{
	list->boobool = 0;
	list->ret = 0;
	list->i = 0;
	list->j = 0;
	list->size = 0;
	list->k = 0;
	list->ps = 0;
	list->prec = 0;
	list->l = 0;
	list->has_mod = 0;
	list->fl_size = NULL;
	list->fl = NULL;
	list->fl_opt = NULL;
	list->len = 0;
	list->bobo = 0;
}

void	ft_parse(va_list ap, const char *format, t_list_printf *list)
{
	while (format[list->i])
	{
		if (format[list->i] == '%' && ap)
		{
			list->j = list->i;
			ft_fl_tab(format, list);
			ft_parse_opt(list);
			ft_parse_width(list);
			ft_parse_prec(list);
			ft_parse_size(list);
			list->i += ft_strlen(list->fl + 1);
			ft_printf_solve(ap, list);
		}
		else
		{
			list->ret++;
			ft_putchar(format[list->i]);
		}
		list->i++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_list_printf	*list;
	va_list			ap;
	int				res;

	list = NULL;
	list = ft_memalloc(sizeof(t_list_printf));
	ft_init(list);
	va_start(ap, format);
	ft_parse(ap, format, list);
	va_end(ap);
	res = list->ret;
	free(list->fl_size);
	free(list->fl_opt);
	free(list->fl);
	free(list);
	return (res);
}
