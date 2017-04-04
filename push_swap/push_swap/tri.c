/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:24:55 by qdupless          #+#    #+#             */
/*   Updated: 2017/04/01 13:25:12 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tri_lb(t_push **lb, t_var *test)
{
	if ((*lb)->name == test->min)
	{
		ft_rot_a(lb, test);
		if (ft_check_lb(lb) == 1)
			return ;
		ft_tri_lb(lb, test);
	}
	if ((*lb)->next != NULL && (*lb)->name < (*lb)->next->name)
	{
		ft_swap_a(lb, test);
		if (ft_check_lb(lb) == 1)
			return ;
		ft_tri_lb(lb, test);
	}
	else
	{
		if (ft_check_lb(lb) == 1)
			return ;
		ft_rot_a(lb, test);
		ft_tri_lb(lb, test);
	}
}

void	ft_tri_la(t_push **la, t_var *test)
{
	if ((*la)->name == test->max)
	{
		ft_rot_a(la, test);
		if (ft_check(la) == 1)
			return ;
		ft_tri_la(la, test);
	}
	if ((*la)->next != NULL && (*la)->name > (*la)->next->name)
	{
		ft_swap_a(la, test);
		if (ft_check(la) == 1)
			return ;
		ft_tri_la(la, test);
	}
	else
	{
		if (ft_check(la) == 1)
			return ;
		ft_rot_a(la, test);
		ft_tri_la(la, test);
	}
}
