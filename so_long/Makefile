NAME	=	so_long

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

SRC	=	so_long.c 					\
		map/fileread.c 				\
		utils/map_and_chu.c			\
		utils/get_next_line.c		\
		utils/errors.c				\
		utils/memory.c 				\
		images.c					\
		utils/key_manager.c 		\
		utils/key_manager_helper.c 	\
		utils/enemy_mv.c 			\
		utils/int_utils.c 			\
		
OBJ	=	$(SRC:.c=.o)

%.o: %.c
			$(CC) ${CFLAGS} -g -c $< -o $@ 

MLX		=	./libmlx.dylib


RM		=	rm -fr


$(NAME):	$(OBJ)
#			make -C ./mlx
#			@mv mlx/libmlx.dylib ./ 
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX)
			@(echo "\033[32mSO_LONG>> Compiled\033[0m")

all:		$(NAME)

norme:		
		norminette $(SRC)

clean:
			make clean -C mlx
			rm -f *.o
			rm -f ./*/*.o
			@echo "\033[33mSO_LONG>> Deleted \".o\" files\033[0m"

fclean:		clean
			rm -rf $(NAME)
			@echo "\033[33mSO_LONG>> Project cleaned\033[0m"

re:			fclean all
			@echo "\033[0;92mSO_LONG>> Project cleaned and recompiled\033[0m"

re.all:		fclean

.PHONY:		all clean fclean re