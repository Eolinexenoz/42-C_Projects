/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:31:18 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/14 10:31:21 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			new_img(t_e *e)
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGTH);
	e->pr_i = mlx_get_data_addr(e->img, &(e->bpp), &(e->img_l), &(e->endian));
	if (e->iso == 1)
		tab_to_iso(e);
	else
		tab_to_para(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	display_menu(e);
	mlx_destroy_image(e->mlx, e->img);
}

void			brese(t_p p1, t_p p2, t_e *e)
{
	t_a			a;

	a.dx = abs((p2.x - p1.x));
	a.sx = p1.x < p2.x ? 1 : -1;
	a.dy = abs((p2.y - p1.y));
	a.sy = p1.y < p2.y ? 1 : -1;
	a.err = (a.dx > a.dy ? a.dx : -a.dy) / 2;
	while (!(p1.x == p2.x && p1.y == p2.y))
	{
		put_pixel(p1.x, p1.y, e);
		a.e2 = a.err;
		if (a.e2 > -a.dx)
		{
			a.err -= a.dy;
			p1.x += a.sx;
		}
		if (a.e2 < a.dy)
		{
			a.err += a.dx;
			p1.y += a.sy;
		}
	}
}

void			put_pixel(int x, int y, t_e *e)
{
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGTH)
	{
		e->pr_i[(e->img_l * y) + (4 * x) + e->c.var] = e->c_r;
		e->pr_i[(e->img_l * y) + (4 * x) + e->c.var1] = e->c_g;
		e->pr_i[(e->img_l * y) + (4 * x) + e->c.var2] = e->c_b;
	}
}

void			create_img(t_e *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, HEIGTH, WIDTH, "FDF_42");
	new_img(e);
	mlx_hook(e->win, 2, 3, key, e);
	mlx_loop(e->mlx);
}
