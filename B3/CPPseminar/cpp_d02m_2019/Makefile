##
## EPITECH PROJECT, 2020
## MAKEFILE FOR TEST
## File description:
## A simple Makefile to compile
##

NAME	=	unittest

all: $(NAME)

$(NAME)	:
	$(MAKE) -C ./tests

tests_run:
	$(MAKE) -C ./tests

clean:
	$(MAKE) -C ./tests clean

fclean:	clean
	$(MAKE) -C ./tests fclean

re:	fclean all

.PHONY: all clean fclean re tests_run
