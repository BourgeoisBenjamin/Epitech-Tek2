##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## UNIT TEST
##

NAME	=	unit_tests

SRC	=	../ex00/add_mul.c	\
		../ex01/mem_ptr.c	\
		../ex02/tab_to_2dtab.c	\
		../ex03/func_ptr.c	\

SRC_TEST	=	tests_redirect.c	\
				tests_add_mul_2param.c	\
				tests_mem_ptr.c	\
				tests_tab_to_2dtab.c	\
				tests_func_ptr.c	\

OBJECTS	=	$(SRC:.c=.o) $(SRC_TEST:.c=.o)

CFLAGS	=	-W -Wall -Wshadow -Wextra -Werror -I. -fprofile-arcs -ftest-coverage

LDFLAGS	=	-lcriterion --coverage

CC	=	gcc

all:	$(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(LDFLAGS)
	./$(NAME)

clean:
	rm -rf $(OBJECTS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean	all

.PHONY: all clean fclean re
