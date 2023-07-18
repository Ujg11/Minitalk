# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 11:29:20 by ojimenez          #+#    #+#              #
#    Updated: 2023/07/18 19:35:49 by ojimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
FLAGS = -Wall -Wextra -Werror -I$(LIBFT)/headers -L$(LIBFT) -lft

LIBFT = libft

SRCS_SERVER = server.c
SRCS_CLIENT = client.c
SRCS_SERVER_BONUS = server_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c

all:
	@make -s -C $(LIBFT)
	$(CC) $(FLAGS) $(SRCS_SERVER) -o $(SERVER)
	$(CC) $(FLAGS) $(SRCS_CLIENT) -o $(CLIENT)
	@echo "Servidor i Client creats"

clean:
	@make clean -s -C $(LIBFT)

fclean: clean
		@make fclean -s -C $(LIBFT)
		$(RM) $(SERVER) $(CLIENT)
		@echo "Clean del Client i del Servidor"

bonus:
	@make -s -C $(LIBFT)
	$(CC) $(FLAGS) $(SRCS_SERVER_BONUS) -o $(SERVER)
	$(CC) $(FLAGS) $(SRCS_CLIENT_BONUS) -o $(CLIENT)
	@echo "Servidor i Client de bonus creats"


re: fclean all

.PHONY: all client server clean fclean re bonus