##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A simple Makefiled
##

NAME	= strace

SRC	=	src/init.c	\
		src/strace.c	\
		src/parse_arg.c	\
		src/help.c	\
		src/error.c	\
		src/trace_pid.c		\
		src/trace_child.c	\
		src/trace_prog.c	\
		src/get_sys_name.c	\
		src/print_syscall.c	\
		src/getters_syscalls.c	\
		src/print_arg_details.c	\
		src/args/print_char_e.c	\
		src/args/print_void_e.c	\
		src/args/print_char_ee.c	\
		src/args/print_int.c	\
		src/args/print_unsigned_int.c	\
		src/args/print_size_t.c	\
		src/args/print_size_t_e.c	\
		src/args/print_ssize_t.c	\
		src/args/print_int_e.c	\
		src/args/print_struct_stat_e.c	\
		src/args/print_long.c	\
		src/args/print_long_e.c	\
		src/args/print_unsigned_long.c	\
		src/args/print_unsigned_int_e.c	\
		src/args/print_unsigned_long_e.c	\

SRC_MAIN	=	src/main.c	\

NAME_TESTS	=	unit_test

SRC_TESTS =		$(SRC)	\
				tests/tests_redirect.c	\

CFLAGS += 	-W -Wall -Wextra -Wshadow -Iinclude

LDFLAGS +=	\

LDFLAGS_TESTS = -lcriterion --coverage	\

OBJ	=	$(SRC:.c=.o) $(SRC_MAIN:.c=.o)

OBJ_TESTS =	$(SRC_TESTS:.c=.o)

CC	=	gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_TESTS)

fclean: clean
	rm -rf $(NAME)

rclean:
	rm -rf $(NAME_TESTS)
	find . -type f -name "*.gcno" -delete -or -name "*.gcda" -delete

tests_run: LDFLAGS += -lgcov --coverage
tests_run: CFLAGS += -fprofile-arcs -ftest-coverage
tests_run: re
	./tests/test.sh

coverage:
	sudo gcovr -e tests/

debug : CFLAGS += -g
debug : re

re: fclean all

.PHONY: all clean fclean re tests_run rclean
