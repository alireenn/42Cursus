
SRC = client.c server.c 

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(SRC:.c=.o)

$(NAME):
		gcc -Wall -Werror -Wextra -c $(SRC)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

bonus: 
		gcc -Wall -Werror -Wextra -c $(BONUS_SRC)
		ar rc $(NAME) $(BONUS_OBJS)

all: $(NAME)

clean:
		rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
		rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re bonus