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

LIB     = libft/
NAME    = filler
DEL     = deleted_folder_everrr
CFLAGS  = -Wall -Wextra -Werror
CC      = gcc

SRCS    = filler.c init.c update.c remove.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@$(CC) $(CFLAGS) $(SRCS) $(LIB)libft.a -o $(NAME)
	@cp $(NAME) resources/players/

.c.o:
	@printf "[CC] %s                                                  \r" $<
	@$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@make -C $(LIB) clean

fclean: clean
	@make -C $(LIB) fclean

pre_re:
	@rm -rf $(DEL)
	@touch $(NAME)
	@mkdir $(DEL)
	@mv $(NAME) $(DEL)
 
post_re:
	@rm -rf $(DEL)

re: fclean pre_re all post_re
