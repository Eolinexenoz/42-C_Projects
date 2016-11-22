/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <qdupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 05:44:54 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/11 05:59:38 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_ls_list	*list;
	int 			i;

	i = 0;
	list = NULL;
	list = ft_memalloc(sizeof(t_ls_list));
	list->p_tab = NULL;
	list->pf_tab = NULL;
	list->size = 0;
  if (ac > 0)
  {
	  if (av[1] && av[1][0] == '-')
      ft_parse(list, av);
    ft_ls_put(list, av);
    ft_putendl(list->p_tab);
    while (list->pf_tab[i])
    {
      ft_putendl(list->pf_tab[i]);
      i++;
    }
  }
	return (0);
}
