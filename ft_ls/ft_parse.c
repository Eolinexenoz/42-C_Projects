/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <qdupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:29:04 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/18 14:49:05 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	ft_puterror_option(t_ls_list *list, char **av, int i)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(av[1][i]);
	ft_putstr("\nusage: ls [-lart] [file ...]\n");
}

void 	ft_parse_opt(t_ls_list *list, char **av, int k)
{
	const char	str[] = {'r', 't', 'a', 'l'};
	int					i;
	int					j;

	i = 0;
	j = 1;
	while (av[k][i])
	{
		if (ft_strchr(str, av[k][i]))
		{
			list->p_tab[j] = av[k][i];
			j++;
		}
		i++;
	}
}

void	ft_parse(t_ls_list *list, char **av, int k)
{
	const	char	str[] = {'r', 't', 'a', 'l'};
	int				i;

	i = 0;
	if (av[k] && av[k][i] == '-')
	{
		i = 1;
		while (av[k][i])
		{
			if (ft_strchr(str, av[k][i]))
				list->size++;
			else
				ft_puterror_option(list, av, i);
			i++;
		}
		list->p_tab = ft_strnew(list->size + 1);
		list->p_tab[0] = '-';
		ft_parse_opt(list, av, k);
	}
}
