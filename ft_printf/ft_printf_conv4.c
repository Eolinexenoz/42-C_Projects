/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:37:20 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/03 20:37:22 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_o2(t_list_printf *list)
{
	if (list->prec > ft_strlen(list->tab_c))
		ft_prec(list);
	ft_putstr(list->tab_c);
	if (ft_strchr(list->fl_opt, '-'))
		ft_parse_less(list);
}

void	ft_printf_di2(t_list_printf *list)
{
	if (list->max < 0)
	{
		ft_putchar('-');
		list->ret++;
	}
	if (ft_strchr(list->fl_opt, '+') && list->max >= 0)
		ft_parse_more(list);
	if (ft_strchr(list->fl_opt, '0') && list->prec == 0 && \
		!(ft_strchr(list->fl_opt, '-')))
		ft_parse_0(list);
}
