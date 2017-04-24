/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cop_med.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:33:16 by qdupless          #+#    #+#             */
/*   Updated: 2017/04/01 13:33:28 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_number(char **av, t_var *test, int i)
{
	double	nb;

	while (i < test->ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > test->max)
			ft_put_error();
		else if (nb < test->min)
			ft_put_error();
		else
			i++;
	}
	ft_putendl("more good");
}

void	ft_tri_2(t_push **la, t_var *test)
{
	t_push	*tmp;
	int		c;

	tmp = *la;
	if (tmp->next != NULL && tmp->name > tmp->next->name)
	{
		c = tmp->name;
		tmp->name = tmp->next->name;
		tmp->next->name = c;
		ft_tri_2(&tmp, test);
	}
	if (tmp->next == NULL)
		return ;
	else
		ft_tri_2(&tmp->next, test);
}

int		ft_calc_med(t_push **cop, t_var *test)
{
	int		j;
	int		i;
	t_push	*tmp;

	tmp = *cop;
	j = (test->ac / 2) + (test->ac % 2);
	i = 1;
	while (j != i)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->med = tmp->name;
	return (tmp->med);
}

void	ft_separate_to_tri(t_push **la, t_push **lb, t_var *test)
{
	int		i;
	int		k;
	t_push	*tmp;

	k = 0;
	i = 0;
	tmp = *lb;
	if ((*la))
		ft_tri_la(la, test);
	if ((*lb))
	{
		i = ft_list_size(lb);
		ft_tri_lb(lb, test);
	}
	while (k != i)
	{
		ft_push_b_to_a(lb, la, test);
		ft_reverse_rot_a(la, test);
		k++;
	}
}

void	ft_tri(t_push **cop, t_var *test, t_push **la, t_push **lb)
{
	int		i;
	t_push	*tmp;
	int		stock;

	i = 1;
	stock = 0;
	while (!ft_check(cop))
		ft_tri_2(cop, test);
	ft_check_list(cop);
	tmp = *cop;
	test->med = ft_calc_med(cop, test);
	while (i != test->ac)
	{
		if ((*la)->name < test->med)
			ft_push_a_to_b(la, lb, test);
		else
			ft_rot_a(la, test);
		i++;
	}
	ft_separate_to_tri(la, lb, test);
}
