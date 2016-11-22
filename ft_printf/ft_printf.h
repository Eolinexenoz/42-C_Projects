/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 17:21:41 by qdupless          #+#    #+#             */
/*   Updated: 2016/11/06 21:36:10 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <locale.h>
# include <wchar.h>
# include "libft/libft.h"

typedef	struct			s_list_printf
{
	va_list				ap;
	void				*ptr;
	unsigned int		ud;
	long				val;
	wint_t				win;
	wchar_t				*wstr;
	int					boobool;
	int					bobo;
	int					i;
	int					j;
	int					k;
	int					l;
	int					prec;
	int					res;
	int					mod;
	int					size;
	int					ret;
	int					num;
	int					ps;
	int					b;
	int					precwchar;
	int					len;
	char				has_mod;
	int					*tab;
	short int			shor;
	intmax_t			max;
	char				*fl_size;
	char				c;
	char				*fl_opt;
	char				*fl;
	char				*str;
	char				*tab_c;
}						t_list_printf;

int						ft_printf(const char *format, ...);
void					ft_parse_size(t_list_printf *list);
void					ft_parse_prec(t_list_printf *list);
void					ft_parse_width(t_list_printf *list);
void					ft_parse_opt(t_list_printf *list);
void					ft_fl_tab(const char *format, t_list_printf *list);
void					ft_printf_solve(va_list ap, t_list_printf *list);
int						ft_printf_u(va_list ap, t_list_printf *list);
int						ft_printf_ld(va_list ap, t_list_printf *list);
int						ft_printf_p(va_list ap, t_list_printf *list);
int						ft_printf_lx(va_list ap, t_list_printf *list);
int						ft_printf_x(va_list ap, t_list_printf *list);
int						ft_printf_lu(va_list ap, t_list_printf *list);
int						ft_printf_lo(va_list ap, t_list_printf *list);
int						ft_printf_o(va_list ap, t_list_printf *list);
void					ft_printf_o2(t_list_printf *list);
int						ft_printf_char(va_list ap, t_list_printf *list);
int						ft_printf_di(va_list ap, t_list_printf *list);
void					ft_printf_di2(t_list_printf *list);
int						ft_printf_s(va_list ap, t_list_printf *list);
int						ft_printf_s2(t_list_printf *list);
void					ft_parse_0(t_list_printf *list);
void					ft_parse_less(t_list_printf *list);
void					ft_parse_diez(t_list_printf *list);
void					ft_parse_special(t_list_printf *list);
void					ft_parse_sp(t_list_printf *list);
void					ft_printf_solve2(va_list ap, t_list_printf *list);
void					ft_parse_sp_s(t_list_printf *list);
void					ft_parse_more(t_list_printf *list);
void					ft_prec(t_list_printf *list);
void					ft_parse_space(t_list_printf *list);
int						ft_printf_percent(t_list_printf *list);
void					ft_get_modif(va_list ap, t_list_printf *list);
void					ft_init(t_list_printf *list);
int						ft_utfchar(va_list ap, t_list_printf *list);
void					ft_printf_utfchar(t_list_printf *list);
int						ft_put_wchar(va_list ap, t_list_printf *list);
int						ft_put_wchar2(t_list_printf *list, int len);
int						ft_put_wchar3(t_list_printf *list, int len, int i);
int						ft_put_wchar4(t_list_printf *list, int len, int i);
int						ft_count_wint_t(t_list_printf *list);
void					ft_wcharlen(t_list_printf *list);
void					ft_wcharlen2(t_list_printf *list, int i);
void					ft_wcharlen3(t_list_printf *list, int i);
void					ft_printf_solve3(va_list ap, t_list_printf *list);

#endif
