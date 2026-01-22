# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 14:05:17 by antcamar          #+#    #+#              #
#    Updated: 2026/01/20 15:22:00 by antcamar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = 
OBJS = $(SRCS:.c=.o)

GNL_DIR = GNL
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

MLX_DIR = mlx_linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(MLX_FLAGS) -o $(NAME)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(GNL_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(GNL_OBJS)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

