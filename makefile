# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vandre <vandre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 04:09:52 by vandre            #+#    #+#              #
#    Updated: 2023/12/13 03:49:00 by vandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=			client server

client_src		=			client.c
server_src		=			server.c

OBJ = $(client_src:.c=.o) $(server_src:.c=.o)

INCLUDE 		=			minitalk.h

LIBFT 			=			libft/libft.a

CC				=			cc

CFLAGS			=			-Wextra -Werror -Wall

all: $(NAME)

client: $(client_src:.c=.o) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(client_src:.c=.o) $(LIBFT)

server: $(server_src:.c=.o) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(server_src:.c=.o) $(LIBFT)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
