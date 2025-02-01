# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 22:28:21 by rbardet-          #+#    #+#              #
#    Updated: 2025/01/31 03:54:58 by rbardet-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = sources/check_content.c \
	sources/check_corner.c \
	sources/check_fill.c \
	sources/check_map.c \
	sources/map_reader.c \
	sources/open_map.c \
	sources/open_map2.c \
	sources/error_message.c \
	sources/so_long_utils.c \
	sources/check_type.c \
	sources/mouvement.c \
	sources/mouvement2.c \
	sources/get_texture.c \
	sources/get_item_nbr.c \
	sources/check_form.c \
	sources/ft_free.c \
	sources/error_message2.c \
	sources/check_path.c \
	sources/so_long.c \

INCLUDE = -I SOURCES -I minilibx-linux -I libft

LIBXPATH = minilibx-linux
LIBX = $(LIBXPATH)/libmlx.a

LIBFTPATH = LIBFT_V2
LIBFT = $(LIBFTPATH)/libft.a

OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g $(INCLUDE)
CFLAGS2 = -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(LIBX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) $(LIBX) $(CFLAGS2)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


