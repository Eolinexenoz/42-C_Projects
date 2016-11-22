/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 08:49:57 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/14 08:50:00 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "color.h"
# include <math.h>
# include <stdio.h>
# include <mlx.h>

# define USAGE_ERROR { perror("Error"); return(-1); }
# define HEIGTH	2048
# define WIDTH 1800
# define FDF_ERROR { ft_putstr("Error, invalid file"); exit(0); }
# define MLC_ERROR { ft_putstr("Error, malloc fail"); exit(0); }

typedef	struct	s_c
{
	float		c0;
	float		c1;
	float		c2;
	float		c3;
	float		c4;
	float		c5;
	int			var;
	int			var1;
	int			var2;
}				t_c;

typedef struct	s_e
{
	char		*buf;
	int			**tab;
	int			ret;
	int			fd;
	int			cp_y;
	int			cp_x;
	size_t		ret_gnl;
	int			x;
	int			y;
	int			z;
	void		*mlx;
	void		*win;
	void		*img;
	char		*pr_i;
	int			xst;
	int			yst;
	int			bpp;
	int			endian;
	int			zoom;
	int			img_l;
	int			deep;
	int			c_r;
	int			c_g;
	int			c_b;
	int			para;
	int			iso;
	t_c			c;
}				t_e;

typedef	struct	s_a
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_a;

typedef	struct	s_p
{
	int			x;
	int			y;
}				t_p;

int				check_validity(t_e *e, char *av);
void			create_img(t_e *e);
void			tab_to_iso(t_e *e);
void			tab_to_para(t_e *e);
void			brese(t_p p1, t_p p2, t_e *e);
void			put_pixel(int x, int y, t_e *e);
int				key(int key, t_e *e);
void			new_img(t_e *e);
void			init_t_m(t_e *e);
void			free_tab(t_e *e);
t_p				p_pa(int y, int x, int z, t_e *e);
t_p				p_iso(int y, int x, int z, t_e *e);
void			display_menu(t_e *e);
void			init_color(t_e *e, int z);

#endif
