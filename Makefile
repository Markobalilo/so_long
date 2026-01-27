# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 14:05:17 by antcamar          #+#    #+#              #
#    Updated: 2026/01/27 03:00:28 by antcamar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = utils.c check_map.c check_map2.c main.c graphics.c
OBJS = $(SRCS:.c=.o)

GNL_DIR = GNL
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(GNL_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(GNL_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

