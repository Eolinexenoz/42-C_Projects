/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:19:41 by qdupless          #+#    #+#             */
/*   Updated: 2017/04/01 13:19:43 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rot_b(t_push **lb, t_var *test)
{
	t_push	*tmp;
	t_push	*tmp2;
	t_push	*tmp3;

	tmp = *lb;
	tmp2 = *lb;
	tmp3 = *lb;
	while (tmp->next)
	{
		if (tmp->next)
			tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp->next = tmp3;
	tmp2->next = NULL;
	*lb = tmp;
	test->ope += 1;
	ft_putendl("rrb");
}

void	ft_reverse_rot_a(t_push **la, t_var *test)
{
	t_push	*tmp;
	t_push	*tmp2;
	t_push	*tmp3;

	tmp = *la;
	tmp2 = *la;
	tmp3 = *la;
	while (tmp->next)
	{
		if (tmp->next)
			tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp->next = tmp3;
	tmp2->next = NULL;
	*la = tmp;
	test->ope += 1;
	ft_putendl("rra");
}

void	ft_reverse_rot_ab(t_push *la, t_push *lb, t_var *test)
{
	ft_reverse_rot_a(&la, test);
	ft_reverse_rot_b(&lb, test);
	ft_putendl("rrr");
}
