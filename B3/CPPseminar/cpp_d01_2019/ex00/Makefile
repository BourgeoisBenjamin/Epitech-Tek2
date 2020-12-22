##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A simple Makefile to compile
##

SRC	=	z.c		\

NAME	=	z

CFLAGS	=	-std=gnu11 -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all