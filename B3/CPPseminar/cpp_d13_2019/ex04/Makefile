##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A simple Makefile
##

NAME	=

SRC	=	Picture.cpp	\
		Toy.cpp	\
		Buzz.cpp	\
		Woody.cpp	\

NAME_TESTS	=	unit_test

SRC_TESTS =		$(SRC)	\
				tests/tests_redirect.cpp	\
				tests/tests_Picture.cpp	\
				tests/tests_Toy.cpp	\
				tests/tests_Buzz.cpp	\
				tests/tests_Woody.cpp	\

CXXFLAGS += 	-W -Wall -Wextra -Wshadow -Werror

LDFLAGS =	\

LDFLAGS_TESTS = -lcriterion --coverage	\

OBJ	=	$(SRC:.cpp=.o)

OBJ_TESTS =	$(SRC_TESTS:.cpp=.o)

CC	=	g++

all:	$(OBJ)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_TESTS)

fclean: clean
	rm -rf $(NAME)

rclean:
	rm -rf $(NAME_TESTS)
	find . -type f -name "*.gcno" -delete -or -name "*.gcda" -delete

tests_run: CXXFLAGS += -fprofile-arcs -ftest-coverage
tests_run: fclean $(OBJ_TESTS)
	$(CC) -o $(NAME_TESTS) $(OBJ_TESTS) $(LDFLAGS) $(LDFLAGS_TESTS)
	./$(NAME_TESTS)

coverage:
	sudo gcovr -e tests/

debug : CXXFLAGS += -g
debug : re

re: fclean all

.PHONY: all clean fclean re tests_run rclean
