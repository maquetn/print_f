# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaquet <nmaquet@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 10:18:29 by nmaquet           #+#    #+#              #
#    Updated: 2023/05/04 10:18:29 by nmaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =	ft_printf.c \
		ft_print_hex.c \
		ft_print_ptr.c \
		ft_print_uns_dcm.c \
		ft_print_int.c \
		ft_print_char.c \
		ft_print_per.c \
		ft_print_str.c \


CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re