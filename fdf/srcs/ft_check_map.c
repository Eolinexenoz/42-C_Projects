/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:31:31 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/14 10:31:33 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static	void			check_char(char c)
{
	if (ft_isdigit(c) || c == ' ' || c == '-')
		;
	else
		FDF_ERROR;
}

static	void			count_value(char **tmp, t_e *e)
{
	int					i;

	i = 0;
	while (tmp[i])
		i++;
	e->cp_x = i;
	if (!i)
		FDF_ERROR;
}

static	void			create_int_tab(t_e *e)
{
	char				**tmp;

	tmp = NULL;
	while ((e->ret_gnl = get_next_line(e->fd, &e->buf)) > 0)
	{
		e->z = 0;
		tmp = ft_strsplit(e->buf, ' ');
		if (e->cp_x == 0)
			count_value(tmp, e);
		if (!(e->tab[e->y] = (int *)malloc(sizeof(int) * e->cp_x)))
			MLC_ERROR;
		while (tmp[e->z])
		{
			check_char(*tmp[e->z]);
			e->tab[e->y][e->x] = ft_atoi(tmp[e->z]);
			e->z++;
			e->x++;
		}
		if (e->x != e->cp_x)
			FDF_ERROR;
		e->y++;
		e->x = 0;
		ft_memdel((void **)&e->buf);
		ft_memdel((void **)&tmp);
	}
}

static	void			check_line(int *cp_line, t_e *e)
{
	int					ret;

	ret = 0;
	while ((ret = get_next_line(e->fd, &e->buf)) > 0)
	{
		(*cp_line)++;
		ft_memdel((void **)&e->buf);
	}
	e->cp_y = (*cp_line);
	if (e->cp_y == 0)
		FDF_ERROR;
}

int						check_validity(t_e *e, char *av)
{
	int					cp_line;

	cp_line = 0;
	if (!(e->fd = open(av, O_RDONLY, 0666)))
		FDF_ERROR;
	check_line(&cp_line, e);
	if (!(e->tab = (int **)malloc(sizeof(int *) * cp_line)))
		return (0);
	close(e->fd);
	if (!(e->fd = open(av, O_RDONLY, 0666)))
		FDF_ERROR;
	create_int_tab(e);
	close(e->fd);
	return (0);
}
