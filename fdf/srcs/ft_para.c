/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_para.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:32:08 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/14 10:32:11 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_p				p_pa(int y, int x, int z, t_e *e)
{
	t_p			p;

	init_color(e, z);
	p.x = e->xst + ((1.2 * x) - (0.1 * (z * e->deep))) * e->zoom;
	p.y = e->yst + ((1.0 * y) - (0.1 * (z * e->deep))) * e->zoom;
	return (p);
}

void			tab_to_para(t_e *e)
{
	t_p			p;
	t_p			p2;

	e->x = 0;
	e->y = 0;
	while (e->y < e->cp_y)
	{
		while (e->x < e->cp_x)
		{
			p = p_pa(e->y, e->x, e->tab[e->y][e->x], e);
			e->x++;
			if (e->x < e->cp_x)
			{
				p2 = p_pa(e->y, e->x, e->tab[e->y][e->x], e);
				brese(p, p2, e);
			}
			if (e->y < e->cp_y - 1)
			{
				p2 = p_pa(e->y + 1, e->x - 1, e->tab[e->y + 1][e->x - 1], e);
				brese(p, p2, e);
			}
		}
		e->x = 0;
		e->y++;
	}
}
