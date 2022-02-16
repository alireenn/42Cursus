NAME = libftprintf.a

SRC = *.c

OBJS = $(SRC:.c=.o)

$(NAME):
		gcc -Wall -Werror -Wextra -c $(SRC)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all: $(NAME)

bonus: all

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re bonus