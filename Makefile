NAME = push_swap.a

CFLAGS = -Wall -Wextra -Werror

CFILES = libft.c linked_list_utils.c swap.c input_checker.c push.c sort.c ft_split.c \
rotate.c reverse_rotate.c

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