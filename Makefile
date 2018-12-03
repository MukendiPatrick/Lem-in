# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_2                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/15 16:22:58 by mtshisw           #+#    #+#              #
#    Updated: 2018/09/17 18:15:43 by mtshisw          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

LIBFT_A     = libft/libft.a

LIBFT_DIR   =   ./libft

INCLUDES    =   ./includes

CC = gcc

FLAGS = -Wextra -Werror -Wall  -I./includes

SRCS_DIR    =	./srcs/initialize.c ./srcs/gen_order.c ./srcs/error_detection.c \
				./srcs/get_info.c ./srcs/navigate.c ./srcs/ants_motion_prt.c ./srcs/get_list_info.c

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIBFT_DIR) all
	@$(CC) -o $(NAME) $(FLAGS) $(SRCS_DIR) $(LIBFT_A)
	@echo "\x1B[36m              lem-in compiled successfully\x1B[3m"

clean:
	@make clean -C libft
	@echo "\x1B[36m                 clean:\x1B[0m"
	@echo "\x1B[31m                       - Object files\x1B[0m"

fclean:
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\x1B[36m                 clean:\x1B[0m"
	@echo "\x1B[31m                       - Object files\x1B[0m"
	@echo "\x1B[31m                       - Execution file\x1B[0m"
	@echo "\x1B[31m                       - libft.a\x1B[0m"

re: fclean all
