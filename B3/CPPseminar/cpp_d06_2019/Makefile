##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A simple Makefile
##

NAME	=

SRC	=	ex00/my_cat.cpp	\
		ex01/my_convert_temp.cpp	\
		hospital/SickKoala.cpp	\
		hospital/KoalaNurse.cpp	\
		hospital/KoalaDoctor.cpp	\

NAME_TESTS	=	unit_test

SRC_TESTS =		$(SRC)	\
				tests/tests_redirect.cpp	\
				tests/tests_cat_error.cpp	\
				tests/tests_convert_celsius.cpp	\
				tests/tests_convert_fahrenheit.cpp	\
				tests/tests_sickkoalaPoke.cpp	\
				tests/tests_sickkoalaTakeDrug.cpp	\
				tests/tests_KoalaNurseTimeCheck.cpp	\
				tests/tests_KoalaNurseReadReport.cpp	\
				tests/tests_print_conversion.cpp	\
				tests/tests_sort_convert.cpp	\
				tests/tests_my_cat.cpp	\
				tests/tests_sickkoalaDelete.cpp	\
				tests/tests_sickkoalaOverDrive.cpp	\
				tests/tests_sickkoalaGetName.cpp	\
				tests/tests_koalanurseDelete.cpp	\
				tests/tests_koalanurseGetID.cpp	\

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
