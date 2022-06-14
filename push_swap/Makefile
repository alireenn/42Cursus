NAME=push_swap

CHECKERNAME=checker

CC=gcc

FLAGS=-Wall -Werror -Wextra -g

SRC=utils/check_utils.c 		\
	utils/checks.c 				\
	decide.c 					\
	find_a_way.c 				\
	find.c 						\
	moves/move_utils.c 			\
	moves/moves_both.c 			\
	moves/moves.c 				\
	moves/moves2.c 				\
	utils/sort_utils.c 			\
	to_do.c 					\
	treat.c 					\
	utils/utils.c 				\
	utils/utils2.c 				\
	values.c					\

MAIN=push_swap.c

MAINBONUS=checker.c

BONUSSRC=checker_.c 							\
	checker_2.c 							\
	checker_3.c								\
	LIBFT/get_next_line/get_next_line.c			\
	LIBFT/get_next_line/get_next_line_utils.c 	\

OBJS=$(SRC:.c=.o)
MAINO=$(MAIN:.c=.o)
CHECKEROBJS=$(BONUSSRC:.c=.o)
CHECKO=$(MAINBONUS:.c=.o)

LIBFT=./LIBFT/libft.a

$(NAME): $(OBJS) $(LIBFT) $(MAINO)
	$(CC) $(FLAGS) $(SRC) $(MAIN) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./LIBFT/

all: $(NAME)

$(CHECKERNAME): $(OBJS) $(CHECKEROBJS) $(CHECKO) $(LIBFT)
	$(CC) $(FLAGS) $(CHECKO) $(CHECKEROBJS) $(OBJS) $(LIBFT) -o $(CHECKERNAME)

bonus: $(CHECKERNAME)

clean:
			make clean -C ./LIBFT/
			rm -f *.o
			rm -f ./*/*.o
			@echo "\033[33mPUSH_SWAP>> Deleted \".o\" files\033[0m"

fclean:		clean
			rm -rf $(NAME)
			rm -r $(CHECKERNAME)
			@echo "\033[33mPUSH_SWAP>> Project cleaned\033[0m"

re: fclean all
	@echo "\033[0;92mPUSH_SWAP>> Project cleaned and recompiled\033[0m"

.PHONY: all clean fclean re
