/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:05:23 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/22 15:05:25 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "color.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define USAGE_ERROR {  STR_E exit(0); }
# define STR_E ft_putendl("Error : Usage: ./fractol fractale or -h for help\n");
# define HEIGTH	900
# define WIDTH 800

typedef	struct		s_e
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*s;
	int				bpp;
	int				si;
	int				endian;
	int				im;
	int				x;
	int				y;
	int				motion;
	int				mot_i;
	int				r;
	int				g;
	int				b;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			zoom;
	double			i_x;
	double			i_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;
	double			i;
	int				fr;
	int				col;
	int				col1;
}					t_e;

void				check_fractale(t_e *e, char *av);
void				create_img(t_e *e);
void				color(t_e *e);
void				mandelbrot(t_e *e);
void				mandelbrot1(t_e *e);
void				tricorn(t_e *e);
void				julia(t_e *e);
void				julia1(t_e *e);
void				init(t_e *e);
int					key(int key, t_e *e);
void				re_draw(t_e *e, int i);
int					keym(int key, int x, int y, t_e *e);
int					motion(int x, int y, t_e *e);
void				burning(t_e *e);
void				choice(t_e *e, int i);
void				help(void);
void				mlx(t_e *e, int i);
void				color2(t_e *e, int i);
void				color1(t_e *e, int i);

#endif
