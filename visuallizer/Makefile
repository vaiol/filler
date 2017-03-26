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
DEL     = deleted_folder_everrr
CFLAGS  = -Wall -Wextra -Werror
CC      = gcc

SRCS    = main.c init.c remove.c print.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRCS) $(LIB)libft.a -o $(NAME)
	@cp visualizer ../resources

.c.o:
	@printf "[CC] %s\n" $<
	@$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@printf "[RM] objects\n"
	@rm -rf $(OBJS)

fclean: clean
	@printf "[RM] filler ../libft/libft.a\n"
	@rm -rf $(NAME)

pre_re:
	@rm -rf $(DEL)
	@touch $(NAME)
	@mkdir $(DEL)
	@mv $(NAME) $(DEL)

post_re:
	@rm -rf $(DEL)

re: fclean pre_re all post_re
