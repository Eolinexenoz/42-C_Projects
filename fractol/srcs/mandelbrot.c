/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:05:03 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/22 15:05:05 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void				mandelbrot(t_e *e)
{
	e->i_x = HEIGTH;
	e->i_y = WIDTH;
	e->x = 0;
	while (e->x < e->i_x)
	{
		e->y = 0;
		while (e->y < e->i_y)
		{
			e->c_r = e->x / e->zoom + e->x1;
			e->c_i = e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->im)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i++;
			}
			color(e);
			e->y++;
		}
		e->x++;
	}
}

void				mandelbrot1(t_e *e)
{
	e->i_x = HEIGTH;
	e->i_y = WIDTH;
	e->x = 0;
	while (e->x < e->i_x)
	{
		e->y = 0;
		while (e->y < e->i_y)
		{
			e->c_r = e->x / e->zoom + e->x1;
			e->c_i = e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->im)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = sqrt(6) * e->z_i * e->tmp + e->c_i;
				e->i++;
			}
			color(e);
			e->y++;
		}
		e->x++;
	}
}

void				tricorn(t_e *e)
{
	e->i_x = HEIGTH;
	e->i_y = WIDTH;
	e->x = 0;
	while (e->x < e->i_x)
	{
		e->y = 0;
		while (e->y < e->i_y)
		{
			e->c_r = e->x / e->zoom + e->x1;
			e->c_i = e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->im)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = -2 * e->z_i * e->tmp + e->c_i;
				e->i++;
			}
			color(e);
			e->y++;
		}
		e->x++;
	}
}

void				burning(t_e *e)
{
	e->i_x = HEIGTH;
	e->i_y = WIDTH;
	e->x = 0;
	while (e->x < e->i_x)
	{
		e->y = 0;
		while (e->y < e->i_y)
		{
			e->c_r = e->x / e->zoom + e->x1;
			e->c_i = e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->im)
			{
				e->tmp = e->z_r;
				e->z_r = fabs(e->z_r * e->z_r - e->z_i * e->z_i + e->c_r);
				e->z_i = fabs(2 * e->z_i * e->tmp + e->c_i);
				e->i++;
			}
			color(e);
			e->y++;
		}
		e->x++;
	}
}
