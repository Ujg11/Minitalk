# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 11:29:20 by ojimenez          #+#    #+#              #
#    Updated: 2023/07/19 15:55:04 by ojimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS_SERVER = server.c
OBJ_SERVER = $(SRCS_SERVER:.c=.o)

SRCS_CLIENT = client.c
OBJ_CLIENT = $(SRCS_CLIENT:.c=.o)

SRCS_SERVER_BONUS = server_bonus.c
OBJ_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

SRCS_CLIENT_BONUS = client_bonus.c
OBJ_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -s -C $(LIBFT_PATH)

$(SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $@ -L$(LIBFT_PATH) -lft

$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $@ -L$(LIBFT_PATH) -lft

$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) -o $@ -L$(LIBFT_PATH) -lft

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) -o $@ -L$(LIBFT_PATH) -lft

$(OBJ_SERVER): $(SRCS_SERVER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_CLIENT): $(SRCS_CLIENT)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_SERVER_BONUS): $(SRCS_SERVER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_CLIENT_BONUS): $(SRCS_CLIENT_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -s -C $(LIBFT_PATH)
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
	$(MAKE) fclean -s -C $(LIBFT_PATH)
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "Clean del Client i del Servidor"

re: fclean all

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)
