#include "push_swap.h"

void	ft_reverse_rot_b(t_push **lb)
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
}

void	ft_reverse_rot_a(t_push **la)
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
}

void	ft_reverse_rot_ab(t_push *la, t_push *lb)
{
	ft_reverse_rot_a(&la);
	ft_reverse_rot_b(&lb);
}

void	ft_rot_rev_a(t_push **la)
{
	t_push	*tmp;
	int		c;

	tmp = *la;
	while (tmp->next)
	{
		c = tmp->next->name;
		tmp->next->name = tmp->name;
		tmp->name = c;
		tmp = tmp->next;
	}
}

void	ft_rot_b(t_push **lb)
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
}

void	ft_rot_a(t_push **la)
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
}

void	ft_rot_ab(t_push *la, t_push *lb)
{
	ft_rot_a(&la);
	ft_rot_b(&lb);
}

int		ft_push_b_to_a(t_push **lb, t_push **la)
{
	t_push	*tmp;
	int		c;

	if (lb)
	{
		tmp = *lb;
		c = tmp->name;
		ft_addlst(la, c);
		*lb = tmp->next;
		free(tmp);
		return (1);
	}
	return (0);
}

int		ft_push_a_to_b(t_push **la, t_push **lb)
{
	t_push	*tmp;
	int		c;

	if (la)
	{
		tmp = *la;
		c = tmp->name;
		ft_addlst(lb, c);
		*la = tmp->next;
		free(tmp);
		return (1);
	}
	return (0);
}

void	ft_swap_b(t_push **lb)
{
	t_push	*tmp;
	int		c;

	tmp = *lb;
	c = tmp->name;
	tmp->name = tmp->next->name;
	tmp->next->name = c;
}

void	ft_swap_a(t_push **la)
{
	t_push	*tmp;
	int		c;

	tmp = *la;
	c = tmp->name;
	tmp->name = tmp->next->name;
	tmp->next->name = c;
}

void	ft_swap_ab(t_push *la, t_push *lb)
{
	ft_swap_a(&la);
	ft_swap_b(&lb);
}

void	ft_tri_3(t_push **lb)
{
	t_push	*tmp;
	t_push	*tmp2;

	tmp = *lb;
	tmp2 = *lb;
	tmp2 = tmp2->next;
	if (tmp->next != NULL && tmp->name < tmp->next->name)
	{
		ft_swap_b(&tmp);
		ft_tri_3(&tmp);
	}
	if (tmp->next == NULL)
		return ;
	else
		ft_tri_3(&tmp->next);
}

void	ft_tri_2(t_push **la)
{
	t_push	*tmp;

	tmp = *la;
	if (tmp->next != NULL && tmp->name > tmp->next->name)
	{
		ft_swap_a(&tmp);
		ft_tri_2(&tmp);
	}
	if (tmp->next == NULL)
		return ;
	else
		ft_tri_2(&tmp->next);
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
	int		val;
	t_push	*tmp;

	val = 0;
	tmp = *cop;
	j = ac / 2;
	i = 0;
	while (j != i)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->med = tmp->name;
	return (tmp->med);
}

void	ft_tri(t_push **cop, int ac, t_push **la, t_push **lb)
{
	int		i;
	int		j;
	int		med;
	t_push	*tmp;
	t_push	*tmp2;
	t_push	*tmp3;

	i = 0;
	j = ac / 2;
	while (!ft_check(cop))
		ft_tri_2(cop);
	i = 0;
	tmp = *cop;
	tmp2 = *la;
	tmp3 = *la;
	med = ft_calc_med(cop, ac);
	ft_putstr("valeur mediane = ");
	ft_putnbr(med);
	ft_putendl("");
	while (tmp3)
	{
		ft_putstr("la Valeur maillon ->name : ");
		ft_putnbr(tmp3->name);
		ft_putendl("-------------------");
		tmp3 = tmp3->next;
	}
	while (tmp2)
	{
		if ((int)tmp2->name <= med)
		{
			ft_putendl("");
			ft_putnbr(tmp2->name);
			ft_putendl("");
			ft_putnbr(med);
			ft_putendl("");
			ft_push_a_to_b(la, lb);
		}
		tmp2 = tmp2->next;
	}
}

void	ft_get_ac(int ac, char **av, t_push *la, t_push *lb)
{
	int 		i;
	int 		stock;
	t_push		*tmp;
	t_push		*tmp2;
	t_push		*cop;

	i = 1;
	cop = NULL;
	while (i < ac)
	{
		stock = ft_atoi(av[i]);
		ft_addlst(&la, stock);
		i++;
	}
	i = 1;
	while (i < ac)
	{
		stock = ft_atoi(av[i]);
		ft_addlst(&cop, stock);
		i++;
	}
	ft_tri(&cop, ac, &la, &lb);
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
