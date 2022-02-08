# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 16:02:33 by mpatrini          #+#    #+#              #
#    Updated: 2022/02/05 19:37:20 by mpatrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
LIBC	= ar rc
CFLAGS	+= -Wall -Werror -Wextra
SRC = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_memchr.c \
	   get_next_line.c \
	   get_next_line_utils.c \
	   ft_printf.c \
	   ft_utility.c \
	   ft_utility2.c \
       ft_print_fun.c \
	   ft_print_fun2.c \
	   ft_print_fun3.c \
	   ft_lstnew.c \
	   ft_lstadd_front.c \
	   ft_lstsize.c \
       ft_lstlast.c \
	   ft_lstadd_back.c \
	   ft_lstdelone.c \
	   ft_lstclear.c \
	   ft_lstiter.c \
	   ft_lstmap.c \

OBJS	= $(SRC:.c=.o)

NAME	= libft.a

.PHONY: all clean fclean re

.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: $(NAME)

bonus: all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f *~ $(NAME)

re: fclean all

