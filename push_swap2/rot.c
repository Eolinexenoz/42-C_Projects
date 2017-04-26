/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:21:47 by qdupless          #+#    #+#             */
/*   Updated: 2017/04/01 13:22:01 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rot_b(t_push **lb, t_var *test)
{
	t_push	*tmp;
	int		c;

	tmp = *lb;
	while (tmp->next)
	{
		c = tmp->name;
		tmp->name = tmp->next->name;
		tmp->next->name = c;
		tmp = tmp->next;
	}
	test->ope += 1;
	ft_putendl("rb");
}

void	ft_rot_a(t_push **la, t_var *test)
{
	t_push	*tmp;
	int		c;

	tmp = *la;
	while (tmp->next)
	{
		c = tmp->name;
		tmp->name = tmp->next->name;
		tmp->next->name = c;
		tmp = tmp->next;
	}
	test->ope += 1;
	ft_putendl("ra");
}

void	ft_rot_ab(t_push *la, t_push *lb, t_var *test)
{
	ft_rot_a(&la, test);
	ft_rot_b(&lb, test);
	ft_putendl("rr");
}
