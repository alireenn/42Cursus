NAME	=	push_swap

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

SRC	=	push_swap.c				\
		check/check.c			\
		rules/rules.c			\
		rules/rules2.c			\
		rules/rules3.c			\
		rules/fill_stacks.c		\
		utils/ft_split.c		\
		utils/int_utils.c 		\
		utils/utils_string.c 	\
		order/small_swap.c 		\
		order/big_soreta.c 		\
		order/big_soreta2.c		\

OBJ	=	$(SRC:.c=.o)

%.o: %.c
			$(CC) ${CFLAGS} -g -c $< -o $@ 


RM		=	rm -fr


$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ)
			@(echo "\033[32mPUSH_SWAP>> Compiled\033[0m")

all:		$(NAME)

norme:		
		norminette $(SRC)

normehead:		
		norminette -R CheckForbiddenSourceHeader $(SRC)

clean:
			rm -f *.o
			rm -f ./*/*.o
			@echo "\033[33mPUSH_SWAP>> Deleted \".o\" files\033[0m"

fclean:		clean
			rm -rf $(NAME)
			@echo "\033[33mPUSH_SWAP>> Project cleaned\033[0m"

re:			fclean all
			@echo "\033[0;92mPUSH_SWAP>> Project cleaned and recompiled\033[0m"

re.all:		fclean

.PHONY:		all clean fclean re