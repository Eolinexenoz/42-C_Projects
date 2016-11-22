/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:56:29 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/14 08:49:09 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			main(int ac, char **av)
{
	t_e		e;

	if (ac == 2 && av[1] && ft_strstr(av[1], ".fdf") \
		&& ft_memset(&e, 0, sizeof(e)))
	{
		if ((e.ret = check_validity(&e, av[1])))
			return (0);
		init_t_m(&e);
		create_img(&e);
		free_tab(&e);
		return (0);
	}
	else
		USAGE_ERROR;
}
