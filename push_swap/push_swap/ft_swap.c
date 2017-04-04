/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:41:44 by qdupless          #+#    #+#             */
/*   Updated: 2017/04/01 13:41:46 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putlist(t_push **la, t_push **lb, t_var *test)
{
	t_push	*tmp;
	t_push	*tmp2;

	tmp = *la;
	tmp2 = *lb;
	while (tmp)
	{
		ft_putstr("la Valeur maillon ->name : ");
		ft_putnbr(tmp->name);
		ft_putendl("");
		tmp = tmp->next;
	}
	while (tmp2)
	{
		ft_putstr("lb valeur maillon ->name : ");
		ft_putnbr(tmp2->name);
		ft_putendl("");
		tmp2 = tmp2->next;
	}
	ft_putstr("test->ope Nb d'operations = ");
	ft_putnbr(test->ope);
	ft_putendl("");
}

void	ft_init(t_var *test, int ac)
{
	test->ope = 0;
	test->min = 2147483647;
	test->max = -2147483648;
	test->ac = ac;
}

void	ft_cop_go(int ac, char **av, t_push **cop)
{
	int		i;
	int		stock;

	i = 1;
	while (i < ac)
	{
		stock = ft_atoi(av[i]);
		ft_addlst(cop, stock);
		i++;
	}
}

void	ft_get_ac(int ac, char **av, t_push *la, t_push *lb)
{
	int			i;
	int			stock;
	t_var		*test;
	t_push		*cop;

	i = 1;
	test = NULL;
	cop = NULL;
	test = ft_memalloc(sizeof(t_list));
	ft_init(test, ac);
	while (i < ac)
	{
		stock = ft_atoi(av[i]);
		ft_addlst(&la, stock);
		if (stock > test->max)
			test->max = stock;
		if (stock < test->min)
			test->min = stock;
		i++;
	}
	i = 1;
	ft_cop_go(ac, av, &cop);
	ft_tri(&cop, test, &la, &lb);
	//ft_putlist(&la, &lb, test);
}

int		main(int ac, char **av)
{
	t_push		*la;
	t_push		*lb;

	la = NULL;
	lb = NULL;
	ft_get_ac(ac, av, la, lb);
	return (0);
}
