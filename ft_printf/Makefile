NAME = libftprintf.a
SRC = ft_printf.c ft_utilis.c ft_utils2.c ft_utils3.c ft_utils4.c

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

$(NAME):
		gcc -Wall -Werror -Wextra -c $(SRC)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all: $(NAME)

bonus: 
		all


clean:
		rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
		rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re bonus