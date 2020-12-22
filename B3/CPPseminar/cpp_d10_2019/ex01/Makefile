##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A simple Makefile
##

NAME	=

SRC	=	AEnemy.cpp	\
		AWeapon.cpp	\
		Character.cpp	\
		PlasmaRifle.cpp	\
		PowerFist.cpp	\
		RadScorpion.cpp	\
		SuperMutant.cpp	\

NAME_TESTS	=	unit_test

SRC_TESTS =		$(SRC)	\
				tests/tests_redirect.cpp	\
				tests/tests_SuperMutant.cpp	\
				tests/tests_RadScorpion.cpp	\
				tests/tests_AWeapon.cpp	\
				tests/tests_PowerFist.cpp	\
				tests/tests_PlasmaRifle.cpp	\
				tests/tests_AEnemy.cpp	\
				tests/tests_Character.cpp	\

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
