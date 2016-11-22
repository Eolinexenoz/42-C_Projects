/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:01:12 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/06 17:01:14 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_size(t_list_printf *list)
{
	const char	*size = "hjlz";

	list->size = 0;
	list->j = 0;
	list->fl_size = ft_strnew(6);
	while (list->fl[list->j])
	{
		if (ft_strchr(size, list->fl[list->j]))
		{
			if (ft_anco(list->fl_size, list->fl[list->j]) < 2 && \
				(list->fl[list->j] == 'l' || list->fl[list->j] == 'h'))
				list->fl_size[list->size++] = list->fl[list->j];
			else if (!(ft_strchr(list->fl_size, list->fl[list->j])))
				list->fl_size[list->size++] = list->fl[list->j];
		}
		list->j++;
	}
}

void	ft_parse_prec(t_list_printf *list)
{
	list->j = 0;
	while (list->fl[list->j])
	{
		if (list->fl[list->j] == '.')
		{
			list->j++;
			if (list->fl[list->j] == '0' || ft_isalpha(list->fl[list->j]))
				list->boobool = 1;
			while (ft_isdigit(list->fl[list->j]))
				list->prec = (list->prec * 10) + list->fl[list->j++] - 48;
		}
		list->j++;
	}
}

void	ft_parse_width(t_list_printf *list)
{
	list->j = 0;
	while (list->fl[list->j])
	{
		if (ft_isdigit(list->fl[list->j]) && list->fl[list->j - 1] != '.' && \
			list->j > 0)
			list->k = (list->k * 10) + list->fl[list->j] - 48;
		if (list->fl[list->j] == '.')
			break ;
		list->j++;
	}
}

void	ft_parse_opt(t_list_printf *list)
{
	const char *opt = "#0 -+";

	list->fl_opt = ft_strnew(5);
	while (list->fl[list->j])
	{
		if (!(ft_strchr(list->fl_opt, list->fl[list->j])) && \
		ft_strchr(opt, list->fl[list->j]))
		{
			if (list->fl[list->j] == '0')
			{
				if (!(list->fl[list->j - 1] >= '1' && \
				list->fl[list->j - 1] <= '9'))
					list->fl_opt[list->size] = list->fl[list->j];
			}
			else
				list->fl_opt[list->size] = list->fl[list->j];
			list->size++;
		}
		list->j++;
	}
}

void	ft_fl_tab(const char *format, t_list_printf *list)
{
	const char	*str = "disScCoOxXpDuU";

	list->b = 0;
	list->j++;
	list->size++;
	while (format[list->j])
	{
		if (ft_strchr(str, format[list->j]) || format[list->j] == '%')
		{
			if (format[list->j] == '%' && !(ft_strchr(str, format[list->j])))
				list->b = 1;
			else
				list->size++;
			break ;
		}
		list->size++;
		list->j++;
	}
	if (list->b)
		list->size++;
	list->fl = ft_strnew(list->size);
	list->fl = ft_strncpy(list->fl, &format[list->i], list->size);
	list->size = 0;
	list->j = 0;
}
