NAME1 = ./server
NAME2 = ./client

SRC1 = ./server.c utils.c
SRC2 = ./client.c utils.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

RM = rm -f

CC = gcc -Wall -Wextra -Werror

.c.o = ${CC}-c $< -o ${<:.c=.o}

all: $(NAME1) $(NAME2)

$(NAME1): ${OBJ1}

$(NAME2): $(OBJ2)

clean:
	${RM} $(OBJ1)
	$(RM) $(OBJ2)

fclean: clean
	${RM} $(NAME1)
	$(RM) $(NAME2)

re: fclean all

.PHONY: all bonus clean fclean re