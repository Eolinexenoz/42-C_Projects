/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:03:08 by qdupless          #+#    #+#             */
/*   Updated: 2017/04/01 13:03:10 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b_to_a(t_push **lb, t_push **la, t_var *test)
{
	t_push	*tmp;
	t_push	*tmp2;

	tmp = (*lb)->next;
	tmp2 = *la;
	while (tmp2)
		tmp2 = tmp2->next;
	if (lb)
	{
		if ((*lb))
		{
			ft_addlst(la, (*lb)->name);
			(*lb) = (*lb)->next;
		}
	}
	test->ope += 1;
	ft_putendl("pa");
	return ;
}

void	ft_push_a_to_b(t_push **la, t_push **lb, t_var *test)
{
	t_push	*tmp;
	t_push	*tmp2;

	tmp = (*la)->next;
	tmp2 = *lb;
	while (tmp2)
		tmp2 = tmp2->next;
	if (la)
	{
		if ((*la))
		{
			ft_addlst(lb, (*la)->name);
			(*la) = (*la)->next;
		}
	}
	test->ope += 1;
	ft_putendl("pb");
	return ;
}

void	ft_swap_b(t_push **lb, t_var *test)
{
	t_push	*tmp;
	int		c;

	tmp = *lb;
	c = tmp->name;
	tmp->name = tmp->next->name;
	tmp->next->name = c;
	test->ope += 1;
	ft_putendl("sb");
}

void	ft_swap_a(t_push **la, t_var *test)
{
	t_push	*tmp;
	int		c;

	tmp = *la;
	c = tmp->name;
	tmp->name = tmp->next->name;
	tmp->next->name = c;
	test->ope += 1;
	ft_putendl("sa");
}

void	ft_swap_ab(t_push *la, t_push *lb, t_var *test)
{
	ft_swap_a(&la, test);
	ft_swap_b(&lb, test);
	ft_putendl("ss");
}
