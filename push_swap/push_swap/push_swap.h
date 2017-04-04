/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:42:09 by qdupless          #+#    #+#             */
/*   Updated: 2017/04/01 13:45:19 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "./libft/libft.h"

typedef	struct		s_push
{
	struct s_push	*next;
	int				name;
	int				med;
}					t_push;

typedef	struct		s_var
{
	int				ope;
	int				min;
	int				max;
	int				med;
	int				ac;
}					t_var;

void				ft_addlst(t_push **list, int d_name);
void				ft_push_b_to_a(t_push **lb, t_push **la, t_var *test);
void				ft_push_a_to_b(t_push **la, t_push **lb, t_var *test);
void				ft_swap_b(t_push **lb, t_var *test);
void				ft_swap_a(t_push **la, t_var *test);
void				ft_swap_ab(t_push *la, t_push *lb, t_var *test);
void				ft_reverse_rot_b(t_push **lb, t_var *test);
void				ft_reverse_rot_a(t_push **la, t_var *test);
void				ft_reverse_rot_ab(t_push *la, t_push *lb, t_var *test);
void				ft_rot_ab(t_push *la, t_push *lb, t_var *test);
void				ft_rot_a(t_push **la, t_var *test);
void				ft_rot_b(t_push **lb, t_var *test);
void				ft_tri_lb(t_push **lb, t_var *test);
void				ft_tri_la(t_push **la, t_var *test);
int					ft_check_lb(t_push **lb);
int					ft_check(t_push **cop);
int					ft_list_size(t_push **list);
void				ft_tri(t_push **cop, t_var *test, t_push **la, t_push **lb);
void				ft_separate_to_tri(t_push **la, t_push **lb, t_var *test);
int					ft_calc_med(t_push **cop, t_var *test);
void				ft_tri_2(t_push **la, t_var *test);

#endif
