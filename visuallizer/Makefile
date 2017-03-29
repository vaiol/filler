# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astepano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 15:03:21 by astepano          #+#    #+#              #
#    Updated: 2017/03/22 22:22:56 by astepano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB     = ../libft/
NAME    = visualizer
CFLAGS  = -Wall -Wextra -Werror
CC      = gcc

SRCS    = main.c init.c remove.c print.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRCS) $(LIB)libft.a -o $(NAME)

.c.o:
	@printf "[CC] %s\n" $<
	@$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@printf "[RM] objects\n"
	@rm -rf $(OBJS)

fclean: clean
	@printf "[RM] visualizer\n"
	@rm -rf $(NAME)

re: fclean all
