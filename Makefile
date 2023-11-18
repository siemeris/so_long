# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 08:44:37 by issierra          #+#    #+#              #
#    Updated: 2023/11/18 10:11:51 by issierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
# NAME_BONUS=so_long_bonus
CC=gcc
CFLAGS=-Wall -Werror -Wextra
MLX_FLAGS=-framework OpenGL -framework Appkit
LIBFT=./libft/libft.a
MLX=./mlx/libmlx.a
H=./src/so_long.h
# H_BONUS=./src_bonus/so_long_bonus.h

SRC=	./src/main.c \
		# ./src/map.c \
		# ./src/exit.c \
		# ./src/map_check.c \
		# ./src/player.c \
		# ./src/check_path.c

OBJ=$(SRC:.c=.o)

# SRC_BONUS=	./src_bonus/main_bonus.c \
# 			./src_bonus/map_bonus.c \
# 			./src_bonus/exit_bonus.c \
# 			./src_bonus/map_check_bonus.c \
# 			./src_bonus/player_bonus.c \
# 			./src_bonus/movements_bonus.c \
# 			./src_bonus/monster_bonus.c \
# 			./src_bonus/check_path_bonus.c

# OBJ_BONUS= $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ)
	@make all -C ./libft
	@make all -C ./mlx
	$(CC) $(CFLAGS) $(OBJ) -I $(H) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

# $(NAME_BONUS): $(OBJ_BONUS)
# 	@make all -C ./libft
# 	@make all -C ./mlx
# 	$(CC) $(CFLAGS) $(OBJ_BONUS) -I $(H_BONUS) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME_BONUS)


all: $(NAME)

# bonus: $(NAME_BONUS)

clean:
	@make clean -C ./libft
	@make clean -C ./mlx
	@rm -f $(OBJ) 

fclean: clean
	@make clean -C ./libft
	@rm -f $(NAME) 

re: fclean all

# re_bonus: fclean bonus

.PHONY: all clean fclean re