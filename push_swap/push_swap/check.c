/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:26:57 by qdupless          #+#    #+#             */
/*   Updated: 2017/04/01 13:27:04 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
