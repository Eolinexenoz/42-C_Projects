/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:31:46 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/14 10:31:48 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_p				p_iso(int y, int x, int z, t_e *e)
{
	t_p		p;

	init_color(e, z);
	p.x = e->xst + ((sqrt(e->c.c0) / e->c.c1) * ((x * e->zoom) -
				(y * e->zoom)));
	p.y = e->yst - ((sqrt(e->c.c2 / e->c.c3) * (z * e->zoom / e->deep)) -
				((e->c.c5 / sqrt(e->c.c4)) * (e->zoom * (x + y))));
	return (p);
}

void			tab_to_iso(t_e *e)
{
	t_p			p;
	t_p			p2;

	e->x = 0;
	e->y = 0;
	while (e->y < e->cp_y)
	{
		while (e->x < e->cp_x)
		{
			p = p_iso(e->y, e->x, e->tab[e->y][e->x], e);
			e->x++;
			if (e->x < e->cp_x)
			{
				p2 = p_iso(e->y, e->x, e->tab[e->y][e->x], e);
				brese(p, p2, e);
			}
			if (e->y < e->cp_y - 1)
			{
				p2 = p_iso(e->y + 1, e->x - 1, e->tab[e->y + 1][e->x - 1], e);
				brese(p, p2, e);
			}
		}
		e->x = 0;
		e->y++;
	}
}
