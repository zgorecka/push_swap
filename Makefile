# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zgorecka <zgorecka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/04 18:42:51 by zgorecka          #+#    #+#              #
#    Updated: 2026/02/04 18:42:51 by zgorecka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CFLAGS = -Wall -Wextra -Werror

CFILES = libft.c linked_list_utils.c input_checker.c push.c rotate.c swap.c reverse_rotate.c \
sort.c ft_split.c cost.c move_nodes.c sort_utils.c stack_utils.c

OFILES = $(CFILES:.c=.o)

all: $(NAME) clean

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)
	@echo "$(NAME) created"

$(OFILES): $(CFILES)
	cc -c $(CFLAGS) $(CFILES)
	@echo "$(CFILES) created"

clean:
	rm -f $(OFILES)

fclean: clean 
	rm -f $(NAME)