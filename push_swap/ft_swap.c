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
}

void	ft_reverse_rot_ab(t_push *la, t_push *lb, t_var *test)
{
	ft_reverse_rot_a(&la, test);
	ft_reverse_rot_b(&lb, test);
}

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
}

void	ft_rot_ab(t_push *la, t_push *lb, t_var *test)
{
	ft_rot_a(&la, test);
	ft_rot_b(&lb, test);
}

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
}

void	ft_swap_ab(t_push *la, t_push *lb, t_var *test)
{
	ft_swap_a(&la, test);
	ft_swap_b(&lb, test);
}

void	ft_tri_2(t_push **la, t_var *test)
{
	t_push	*tmp;

	tmp = *la;
	if (tmp->next != NULL && tmp->name > tmp->next->name)
	{
		ft_swap_a(&tmp, test);
		ft_tri_2(&tmp, test);
	}
	if (tmp->next == NULL)
		return ;
	else
		ft_tri_2(&tmp->next, test);
}

int		ft_check_lb(t_push **lb)
{
	t_push	*tmp;

	tmp = *lb;
	while (tmp->next)
	{
		if (tmp->name < tmp->next->name)
			return (0);
		else
			tmp = tmp->next;
	}
	return (1);
}

int		ft_check(t_push **cop)
{
	t_push	*tmp;

	tmp = *cop;
	while (tmp->next)
	{
		if (tmp->name > tmp->next->name)
			return (0);
		else
			tmp = tmp->next;
	}
	return (1);
}

int		ft_calc_med(t_push **cop, int ac)
{
	int		j;
	int		i;
	t_push	*tmp;

	tmp = *cop;
	j = (ac / 2) + (ac % 2);
	i = 1;
	while (j != i)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->med = tmp->name;
	return (tmp->med);
}

void	ft_tri_lb(t_push **lb, int i, t_var *test)
{
	t_push	*tmp;

	tmp = *lb;
	if (tmp->name == test->min)
	{
		ft_rot_a(lb, test);
		if (ft_check_lb(lb) == 1)
			return ;
		ft_tri_lb(lb, i, test);
	}
	if (tmp->next != NULL && tmp->name < tmp->next->name)
	{
		ft_swap_a(lb, test);
		if (ft_check_lb(lb) == 1)
			return ;
		ft_tri_lb(lb, i, test);
	}
	else
	{
		if (ft_check_lb(lb) == 1)
			return ;
		ft_rot_a(lb, test);
		ft_tri_lb(lb, i, test);
	}
}

void	ft_tri_la(t_push **la, int j, t_var *test)
{
	t_push	*tmp;

	tmp = *la;
	if (tmp->name == test->max)
	{
		ft_rot_a(la, test);
		if (ft_check(la) == 1)
			return ;
		ft_tri_la(la, j, test);
	}
	if (tmp->next != NULL && tmp->name > tmp->next->name)
	{
		ft_swap_a(la, test);
		if (ft_check(la) == 1)
			return ;
		ft_tri_la(la, j, test);
	}
	else
	{
		if (ft_check(la) == 1)
			return ;
		ft_rot_a(la, test);
		ft_tri_la(la, j, test);
	}
}

int		ft_list_size(t_push **list)
{
	t_push	*tmp;
	int		i;

	i = 0;
	tmp = *list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_separate_to_tri(t_push **la, t_push **lb, t_var *test)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	j = ft_list_size(la);
	i = ft_list_size(lb);
	ft_tri_la(la, j, test);
	ft_tri_lb(lb, i, test);
	while (k != i)
	{
		ft_push_b_to_a(lb, la, test);
		ft_reverse_rot_a(la, test);
		k++;
	}
}

void	ft_tri(t_push **cop, int ac, t_push **la, t_push **lb, t_var *test)
{
	int		i;
	int		med;
	t_push	*tmp;
	t_push	*tmp2;
	t_push	*tmp3;

	i = 1;
	while (!ft_check(cop))
		ft_tri_2(cop, test);
	tmp = *cop;
	tmp2 = *la;
	tmp3 = *la;
	med = ft_calc_med(cop, ac);
	ft_putstr("valeur mediane = ");
	ft_putnbr(med);
	ft_putendl("");
	while (i != ac)
	{
		if ((*la)->name < med)
			ft_push_a_to_b(la, lb, test);
		else
			ft_rot_a(la, test);
		i++;
	}
	ft_separate_to_tri(la, lb, test);
}

void	ft_get_ac(int ac, char **av, t_push *la, t_push *lb)
{
	int 		i;
	int 		stock;
	t_push		*tmp;
	t_push		*tmp2;
	t_var		*test;
	t_push		*cop;

	i = 1;
	cop = NULL;
	test = NULL;
	test = ft_memalloc(sizeof(t_list));
	test->ope = 0;
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
	ft_putstr("test->min = ");
	ft_putnbr(test->min);
	ft_putendl("");
	ft_putstr("test->max = ");
	ft_putnbr(test->max);
	ft_putendl("");
	i = 1;
	while (i < ac)
	{
		stock = ft_atoi(av[i]);
		ft_addlst(&cop, stock);
		i++;
	}
	ft_tri(&cop, ac, &la, &lb, test);
	tmp = la;
	tmp2 = lb;
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
	ft_putstr("test->ope = ");
	ft_putnbr(test->ope);
	ft_putendl("");
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
