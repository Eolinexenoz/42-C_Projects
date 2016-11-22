/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wchar_t.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 21:16:55 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/06 21:17:02 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_wchar4(t_list_printf *list, int len, int i)
{
	if (list->wstr[i] < 1114112 && list->wstr[i] >= 65536)
	{
		len += 4;
		if (list->prec && len > list->prec)
		{
			len -= 4;
			return (len);
		}
		ft_putchar(240 | (list->wstr[i] >> 18));
		ft_putchar(128 | ((list->wstr[i] >> 12) & 63));
		ft_putchar(128 | ((list->wstr[i] >> 6) & 63));
		ft_putchar(128 | (list->wstr[i] & 63));
	}
	return (len);
}

int		ft_put_wchar3(t_list_printf *list, int len, int i)
{
	if (list->wstr[i] < 2048)
	{
		len += 2;
		if (list->prec && len > list->prec)
		{
			len -= 2;
			return (len);
		}
		ft_putchar(192 | (list->wstr[i] >> 6));
		ft_putchar(128 | (list->wstr[i] & 63));
	}
	else if (list->wstr[i] < 65536)
	{
		len += 3;
		if (list->prec && len > list->prec)
		{
			len -= 3;
			return (len);
		}
		ft_putchar(224 | (list->wstr[i] >> 12));
		ft_putchar(128 | ((list->wstr[i] >> 6) & 63));
		ft_putchar(128 | (list->wstr[i] & 63));
	}
	len = ft_put_wchar4(list, len, i);
	return (len);
}

int		ft_put_wchar2(t_list_printf *list, int len)
{
	int		i;

	i = 0;
	while (list->wstr[i])
	{
		if (list->wstr[i] >= 1114112)
			len += 0;
		if (list->wstr[i] < 128)
		{
			len += 1;
			if (list->prec && len > list->prec)
			{
				len -= 1;
				return (len);
			}
			ft_putchar(list->wstr[i]);
		}
		else
			len = ft_put_wchar3(list, len, i);
		i++;
	}
	return (len);
}

int		ft_put_wchar(va_list ap, t_list_printf *list)
{
	int		len;

	len = 0;
	list->wstr = va_arg(ap, wchar_t*);
	if (!(ft_strchr(list->fl_opt, '-')) && !(ft_strchr(list->fl_opt, '0')))
		if (list->k > 0)
			ft_parse_sp(list);
	if (ft_strchr(list->fl_opt, '0'))
		ft_parse_0(list);
	if (list->boobool == 1)
		return (0);
	if (list->wstr == 0)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_put_wchar2(list, len);
	if (ft_strchr(list->fl_opt, '-'))
		ft_parse_less(list);
	return (len);
}
