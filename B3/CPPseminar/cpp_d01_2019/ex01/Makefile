##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A simple Makefile to compile
##

SRC	=	main.c		\
		menger.c	\

NAME	=	menger

CFLAGS	=	-std=gnu11 -Wall -Wextra -I .

LDFLAGS	=	-lm

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(LDFLAGS)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all