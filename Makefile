NAME = push_swap.a

CFLAGS = -Wall -Wextra -Werror

CFILES = libft.c linked_list_utils.c input_checker.c push.c rotate.c swap.c reverse_rotate.c \
sort.c ft_split.c make_stack.c utils.c

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