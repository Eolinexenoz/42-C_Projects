/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <qdupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 04:33:33 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/22 22:23:51 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void  ft_parse_folder(t_ls_list *list, char **av)
{
  int   i;

  i = 1;
  list->size = 0;
  if (list->p_tab && av[2])
  {
    i = 2;
    while (av[i])
    {
      list->size++;
      i++;
    }
  }
}

void  ft_parse_folder2(t_ls_list *list, char **av)
{
  int   i;
  int   k;

  i = 2;
  k = 0;
  list->pf_tab = (char**)malloc(sizeof(char*) * list->size + 1);
  while (av[i])
  {
    list->pf_tab[k] = ft_strdup(av[i]);
    i++;
    k++;
  }
}

void  ft_ls_put(t_ls_list *list, char **av)
{
  ft_parse_folder(list, av);
}
