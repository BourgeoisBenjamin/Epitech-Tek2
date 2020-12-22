##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A simple Makefiled
##

NAME	= libmy_malloc.so

SRC	=	src/calloc.c	\
		src/free.c	\
		src/malloc.c	\
		src/realloc.c	\
		src/reallocarray.c	\
		src/error.c	\
		src/get_mem_block.c	\
		src/init_malloc_session.c	\

NAME_TESTS	=	unit_test

SRC_TESTS =		tests/tests_redirect.c	\
				tests/tests_malloc.c	\
				tests/tests_free.c	\

CFLAGS += 	-W -Wall -Wextra -Wshadow -Werror -I include\

LDFLAGS =	-shared \

LDFLAGS_TESTS = -lcriterion --coverage	-ldl	\

OBJ	=	$(SRC:.c=.o)

OBJ_TESTS =	$(SRC_TESTS:.c=.o)

CC	=	gcc

all: CFLAGS += -fpic
all:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_TESTS)

fclean: clean
	rm -rf $(NAME)

rclean:
	rm -rf $(NAME_TESTS)
	find . -type f -name "*.gcno" -delete -or -name "*.gcda" -delete

tests_run: all $(OBJ_TESTS)
	$(CC) -o $(NAME_TESTS) $(OBJ_TESTS) $(LDFLAGS_TESTS) -fprofile-arcs -ftest-coverage
	./$(NAME_TESTS)

coverage:
	sudo gcovr -e tests/

debug : CFLAGS += -g
debug : re

re: fclean all

.PHONY: all clean fclean re tests_run rclean
