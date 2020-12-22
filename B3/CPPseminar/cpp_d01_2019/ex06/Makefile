##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A simple Makefile to compile
##

SRC	=	menger.c		\
		main.c	\
		drawing.c	\
		bitmap_header.c	\

NAME	=	menger_face

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