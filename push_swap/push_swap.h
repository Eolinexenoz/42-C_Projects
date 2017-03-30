#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "./libft/libft.h"

typedef struct 		s_push
{
	struct s_push	*next;
	int				name;
	int				med;
}					t_push;

typedef	struct 		s_var
{
	int				ope;
	int				min;
	int				max;
}					t_var;

void	ft_addlst(t_push **list, int d_name);

#endif
