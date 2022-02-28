NAME = libftprintf.a
SRC = *.c

OBJS = $(SRC:.c=.o)

$(NAME):
		gcc -Wall -Werror -Wextra -c $(SRC)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all: $(NAME)

clean:
		rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
		rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re