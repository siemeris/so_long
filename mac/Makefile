# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 08:44:37 by issierra          #+#    #+#              #
#    Updated: 2023/12/01 11:26:37 by issierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
NAME_BONUS=so_long_bonus
CC=gcc
# CC=gcc -g
# CC = clang -fsanitize=address -g
CFLAGS=-Wall -Werror -Wextra
MLX_FLAGS=-framework OpenGL -framework Appkit
LIBFT=./libft/libft.a
MLX=./mlx/libmlx.a
H=./src/so_long.h
H_BONUS=./src_bonus/so_long_bonus.h

SRC=	./src/so_long.c \
		./src/read_map.c \
		./src/check_map.c \
		./src/render.c \
		./src/movements.c \
		./src/errors.c \


OBJ=$(SRC:.c=.o)

SRC_BONUS=	./src_bonus/so_long_bonus.c \
			./src_bonus/read_map_bonus.c \
			./src_bonus/check_map_bonus.c \
			./src_bonus/render_bonus.c \
			./src_bonus/movements_bonus.c \
			./src_bonus/errors_bonus.c \
			./src_bonus/extras_bonus.c \

OBJ_BONUS= $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ)
	@make all -C ./libft
	@make all -C ./mlx
	$(CC) $(CFLAGS) $(OBJ) -I $(H) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME)
#	$(CC) $(CFLAGS) $(OBJ) -L ../LeakSanitizer/LeakSanitizer -llsan -I $(H) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME)
#	$(CC) $(CFLAGS) $(OBJ) -g3 -fsanitize=address -I $(H) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME)


$(NAME_BONUS): $(OBJ_BONUS)
	@make all -C ./libft
	@make all -C ./mlx
	$(CC) $(CFLAGS) $(OBJ_BONUS) -I $(H_BONUS) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME_BONUS)


all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	@make clean -C ./libft
	@make clean -C ./mlx
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@make clean -C ./libft
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re