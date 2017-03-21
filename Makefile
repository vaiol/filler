# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astepano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 15:03:21 by astepano          #+#    #+#              #
#    Updated: 2017/03/21 23:38:52 by astepano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/
NAME = astepano.filler
DEL = deleted_folder_everrr

all: $(NAME)

$(NAME):
	make -C $(LIB)

clean:
	make -C $(LIB) clean

fclean: clean
	make -C $(LIB) fclean

pre_re:
	rm -rf $(DEL)
	touch $(NAME)
	mkdir $(DEL)
	mv $(NAME) $(DEL)
 
post_re:
	rm -rf $(DEL)

re: fclean pre_re all post_re
