/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:04:48 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/22 15:04:50 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static	void		key6(t_e *e, int key)
{
	if (key == 32)
	{
		e->im -= 2;
		if (e->im == 0)
			e->im = 2;
	}
	else
		e->im += 2;
}

static	void		key5(t_e *e, int key)
{
	if (key == 9)
	{
		e->col1++;
		if (e->col1 > 8)
			e->col1 = 1;
	}
}

static	void		key4(t_e *e, int key)
{
	if (key == 124)
		e->x1 *= 0.99;
	else if (key == 123)
		e->x1 *= 1.01;
	else if (key == 125)
		e->y1 *= 0.99;
	else if (key == 126)
		e->y1 *= 1.01;
}

static	void		key3(t_e *e, int key)
{
	if (key == 47)
		e->zoom *= 0.97;
	else if (key == 43)
		e->zoom *= 1.05;
	else if (key == 3)
	{
		if (e->fr == 7)
			e->fr = 1;
		else
			e->fr++;
		re_draw(e, 3);
	}
	else
	{
		if (e->col == 1)
			e->col -= 1;
		else
			e->col = 1;
	}
}

int					key(int key, t_e *e)
{
	if (key == 53)
		mlx(e, 0);
	else if (key == 43 || key == 47 || key == 3 || key == 8)
		key3(e, key);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		key4(e, key);
	else if (key == 34 || key == 32)
		key6(e, key);
	else if (key == 9)
		key5(e, key);
	else if (key == 15)
		re_draw(e, 3);
	else if (key == 46)
		e->motion++;
	re_draw(e, 1);
	return (1);
}
