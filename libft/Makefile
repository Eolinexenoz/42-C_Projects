# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdupless <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 12:38:55 by qdupless          #+#    #+#              #
#    Updated: 2015/12/08 16:28:24 by qdupless         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putchar.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c \
	  ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	  ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
	  ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
	  ft_strcpy.c ft_strdup.c ft_strequ.c ft_strlen.c ft_strncat.c \
	  ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnstr.c ft_strrchr.c \
	  ft_strstr.c ft_tolower.c ft_toupper.c ft_striter.c  \
	  ft_strlcat.c ft_memalloc.c ft_itoa.c ft_strtrim.c ft_strsub.c \
	  ft_strnew.c ft_strmapi.c ft_strsplit.c ft_strmap.c ft_strjoin.c \
	  ft_striteri.c ft_strdel.c ft_memdel.c ft_lstnew.c ft_lstmap.c \
	  ft_lstiter.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_strtolow.c \
	  ft_strtoupp.c ft_strrev.c ft_power.c ft_isspace.c

INCLUDES = libft.h

OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc -c $(FLAGS) $(SRC) $(INCLUDES)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME) libft.h.gch

re : fclean all
