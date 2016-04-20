# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thifranc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 19:24:34 by thifranc          #+#    #+#              #
#    Updated: 2016/04/20 12:30:53 by thifranc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

INC = lib.h

SRCS = get_arg get_type recur_me light_prtf sort_by sort_list option \
	   list_reverse get_date print lib_list no_segfault

SRCS:= $(addsuffix .c, $(SRCS))
OBJ = $(SRCS:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make re -C libft/
	make clean -C libft/
	gcc $(FLAGS) $(SRCS) libft/libft.a -o $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo "erasing all binary files"

fclean: clean
	@$(RM) $(NAME)
	@make clean -C libft/
	@echo "erasing $(NAME)"

re: fclean all
	@make fclean -C libft/
	@echo "fclean + all"

.PHONY: all clean fclean re
