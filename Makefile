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

SRCS    = fill.c fill_small.c fill_big.c attack.c init.c update.c remove.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "[CC] libft.a start:\n"
	@make -C $(LIB)
	@printf "[CC] libft.a finished successfull!\n"
	@$(CC) $(CFLAGS) $(SRCS) $(LIB)libft.a -o $(NAME)
	@cp $(NAME) resources/players/
	@printf "[CC] filler\n"

.c.o:
	@printf "[CC] %s\n" $<
	@$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@printf "[RM] objects\n"
	@rm -rf $(OBJS)
	@make -C $(LIB) clean

fclean: clean
	@printf "[RM] filler libft/libft.a\n"
	@rm -rf $(NAME)
	@make -C $(LIB) fclean

pre_re:
	@rm -rf $(DEL)
	@touch $(NAME)
	@mkdir $(DEL)
	@mv $(NAME) $(DEL)
 
post_re:
	@rm -rf $(DEL)

re: fclean pre_re all post_re
