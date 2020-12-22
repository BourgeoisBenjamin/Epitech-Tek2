##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A simple Makefile
##

NAME	= santa

SRC	=	src/Box.cpp	\
		src/GiftPaper.cpp	\
		src/LittlePony.cpp	\
		src/Object.cpp	\
		src/Teddy.cpp	\
		src/Toy.cpp	\
		src/Wrap.cpp	\
		src/IElf.cpp	\
		src/ITable.cpp	\
		src/PapaXmasConveyorBelt.cpp	\
		src/PapaXmasTable.cpp	\
		src/UnitsFile.cpp	\
		src/PapaXmasElf.cpp \

SRC_MAIN	=	src/main.cpp	\

NAME_TESTS	=	unit_test

SRC_TESTS =		$(SRC)	\
				tests/tests_redirect.cpp	\
				tests/tests_Toy.cpp			\
				tests/tests_Teddy.cpp		\
				tests/tests_LittlePony.cpp	\
				tests/tests_Boxes.cpp		\
				tests/tests_Wrap.cpp

CXXFLAGS += 	-W -Wall -Wextra -Wshadow -Werror -I include/

LDFLAGS =	\

LDFLAGS_TESTS = -lcriterion --coverage	\

OBJ	=	$(SRC:.cpp=.o) $(SRC_MAIN:.cpp=.o)

OBJ_TESTS =	$(SRC_TESTS:.cpp=.o)

CC	=	g++

all:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
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
