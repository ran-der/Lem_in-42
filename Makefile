# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/11 14:44:06 by rvan-der          #+#    #+#              #
#    Updated: 2017/03/24 23:17:16 by rvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC = find_paths.c main_lem_in.c read_map.c set_flow_info.c get_room.c \
	  path_list.c read_rooms.c set_tools.c check.c path_tools.c room_list.c \
	  delete_ft.c play.c select_paths.c error_ft.c link_tools.c read_links.c \
	  select_tools.c

OBJ = $(SRC:.c=.o)

.SUFFIXES:

all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	$(CC) $(CFLAG) -c $(SRC)
	$(CC) $(OBJ) -Llibft -lft -g -o $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all
