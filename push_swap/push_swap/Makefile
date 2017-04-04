# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdupless <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/11 12:32:13 by qdupless          #+#    #+#              #
#    Updated: 2017/04/03 17:51:35 by qdupless         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ft_swap.c ft_newlst.c check.c cop_med.c reverse_rot.c rot.c swap_push.c \
	  tri.c

INCLUDE = ./libft/

PATH = Includes

OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc $(FLAGS) -c $(SRC)
	gcc $(OBJS) -L $(INCLUDE) -lft  -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
