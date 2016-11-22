/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:32:22 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/14 10:32:24 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			init_t_m(t_e *e)
{
	e->xst = 200;
	e->yst = 200;
	e->deep = 5;
	e->zoom = 20;
	e->c_r = 255;
	e->c_b = 27;
	e->c_g = 199;
	e->c.c0 = 2;
	e->c.c1 = 2;
	e->c.c2 = 2.0;
	e->c.c3 = 3.0;
	e->c.c5 = 1;
	e->c.c4 = 6;
	e->c.var = 2;
	e->c.var1 = 1;
	e->c.var2 = 0;
}

void			free_tab(t_e *e)
{
	int			y;

	y = 0;
	while (y < e->cp_y)
	{
		free(e->tab[y]);
		y++;
	}
	ft_memdel((void **)&e->tab);
}

void			display_menu(t_e *e)
{
	mlx_string_put(e->mlx, e->win, 20, 20, 0xFFFFFF,
		"Fleches pour deplacer l'objet");
	mlx_string_put(e->mlx, e->win, 20, 34, 0xFFFFFF,
		"* /  pave num pour le relief");
	mlx_string_put(e->mlx, e->win, 20, 50, 0xFFFFFF,
		"+/- pave num pour le zoom");
	mlx_string_put(e->mlx, e->win, 20, 66, 0xFFFFFF,
		"2/3 pave l'inclinaison (seulement pour vue Iso)");
	mlx_string_put(e->mlx, e->win, 20, 82, 0xFFFFFF,
		"o pour projection Isometrique");
	mlx_string_put(e->mlx, e->win, 20, 100, 0xFFFFFF,
		"p pour projection Parallele");
}

void			init_color(t_e *e, int z)
{
	if (z >= 0 && z <= 3)
		BLUE;
	if (z >= 4 && z <= 6)
		GREY;
	if (z >= 6 && z <= 13)
		BROWN;
	if (z >= 13 && z <= 25)
		YELLOW;
	if (z >= 4 && z <= 6)
		BROW;
	if (z >= 26 && z <= 40)
		GREEN;
	if (z >= 41 && z <= 80)
		BROWN;
	if (z >= 81 && z <= 94)
		GREY;
	if (z > 95)
		WHITE;
}
