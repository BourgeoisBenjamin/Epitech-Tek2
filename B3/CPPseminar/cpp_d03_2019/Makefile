##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A simple Makefile
##

NAME	=	libstring.a

SRC	=	string_init.c	\
		string_destroy.c	\
		assign.c	\
		append.c	\
		at.c	\
		clear.c	\
		size.c	\
		compare.c	\
		copy.c	\
		c_str.c	\
		empty.c	\
		find.c	\
		insert.c	\
		to_int.c	\

NAME_TESTS	=	unit_test

SRC_TESTS =		$(SRC)	\
				tests/tests_string_init.c	\
				tests/tests_append.c	\
				tests/tests_at.c	\
				tests/tests_clear.c	\
				tests/tests_size.c	\
				tests/tests_compare.c	\
				tests/tests_copy.c	\
				tests/tests_c_str.c	\
				tests/tests_empty.c	\
				tests/tests_find.c	\
				tests/tests_insert.c	\
				tests/tests_to_int.c	\

CFLAGS += 	-std=gnu11 -W -Wall -Wextra -Wshadow -Werror

LDFLAGS =	\

LDFLAGS_TESTS = -lcriterion --coverage	\

OBJ	=	$(SRC:.c=.o)

OBJ_TESTS =	$(SRC_TESTS:.c=.o)

CC	=	gcc

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_TESTS)

fclean: clean
	rm -rf $(NAME)

rclean:
	rm -rf $(NAME_TESTS)
	find . -type f -name "*.gcno" -delete -or -name "*.gcda" -delete

tests_run: CFLAGS += -fprofile-arcs -ftest-coverage
tests_run: $(OBJ_TESTS)
	$(CC) -o $(NAME_TESTS) $(OBJ_TESTS) $(LDFLAGS) $(LDFLAGS_TESTS)
	./$(NAME_TESTS)

coverage:
	sudo gcovr -e tests/

debug : CFLAGS += -g
debug : re

re: fclean all

.PHONY: all clean fclean re tests_run rclean coverage
