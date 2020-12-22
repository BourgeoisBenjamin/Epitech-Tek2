##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## build
##

SRC	=	./new.c					\
		./player.c					\
		./point.c					\
		./vertex.c					\
		./char.c					\
		./float.c					\
		./int.c

SRC_TEST=	./tests/test_redirect.c				\
			./tests/test_new.c					\
			./tests/test_point_str.c			\
			./tests/test_eq.c					\
			./tests/test_gt.c					\
			./tests/test_lt.c					\
			./tests/test_add.c					\
			./tests/test_mul.c					\
			./tests/test_div.c					\
			./tests/test_sub.c

NAME	=	unit_tests

OBJ	=	$(SRC_TEST:.c=.o) $(SRC:.c=.o)

CFLAGS	=	-I ./tests/include -fprofile-arcs -ftest-coverage

LDFLAGS	=	-lcriterion --coverage

CC = gcc

LDFLAGS	=	-lcriterion --coverage -fprofile-arcs -ftest-coverage

tests_run:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	./$(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all

rclean: fclean
	find -name '*.gcda' -delete
	find -name '*.gcno' -delete

.PHONY: all clean fclean re
