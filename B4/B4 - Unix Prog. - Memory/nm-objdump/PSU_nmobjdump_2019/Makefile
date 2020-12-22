##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A simple Makefiled
##

NAME_NM	= my_nm

NAME_OBJDUMP	= my_objdump

SRC_NM	=	nm/src/my_nm.c	\
			nm/src/my_nm_init.c	\
			nm/src/my_nm_uninit.c	\
			nm/src/my_nm_process.c	\
			nm/src/my_nm_error.c	\
			nm/src/my_nm_open_file.c	\
			nm/src/my_nm_get_symtable.c	\
			nm/src/nm64/my_nm_init64.c	\
			nm/src/nm64/my_nm64.c	\
			nm/src/nm64/my_nm_save_symbol64.c	\
			nm/src/nm32/my_nm_init32.c	\
			nm/src/nm32/my_nm32.c	\
			nm/src/nm32/my_nm_save_symbol32.c	\
			nm/src/list/create_node.c	\
			nm/src/list/add_in_list.c	\
			nm/src/list/delete_list.c	\
			nm/src/list/compare_name.c	\
			nm/src/list/sort_list.c	\

SRC_OBJDUMP	=	objdump/src/my_objdump.c	\
				objdump/src/my_objdump_process.c	\
				objdump/src/my_objdump_init.c	\
				objdump/src/objdump32/my_objdump_init32.c	\
				objdump/src/objdump32/my_objdump32.c	\
				objdump/src/objdump32/my_objdump_header32.c	\
				objdump/src/objdump32/my_objdump_section32.c	\
				objdump/src/objdump64/my_objdump_init64.c	\
				objdump/src/objdump64/my_objdump64.c	\
				objdump/src/objdump64/my_objdump_header64.c	\
				objdump/src/objdump64/my_objdump_section64.c	\
				objdump/src/my_objdump_open_file.c	\
				objdump/src/my_objdump_error.c	\
				objdump/src/my_objdump_uninit.c	\

SRC_NM_MAIN	=	nm/src/main.c	\

SRC_OBJDUMP_MAIN	=	objdump/src/main.c	\

NAME_TESTS	=	unit_test

SRC_TESTS =		$(SRC_NM)	\
				$(SRC_OBJDUMP)	\
				tests/tests_redirect.c	\

CFLAGS += 	-W -Wall -Wextra -Wshadow -Werror

LDFLAGS +=	\

LDFLAGS_TESTS = -lcriterion --coverage	\

OBJ_NM	=	$(SRC_NM:.c=.o) $(SRC_NM_MAIN:.c=.o)

OBJ_OBJDUMP	=	$(SRC_OBJDUMP:.c=.o) $(SRC_OBJDUMP_MAIN:.c=.o)

OBJ_TESTS =	$(SRC_TESTS:.c=.o)

CC	=	gcc

all: nm objdump

nm:		$(OBJ_NM)
		$(CC) $(OBJ_NM) -o $(NAME_NM) $(LDFLAGS)

objdump:	$(OBJ_OBJDUMP)
			$(CC) $(OBJ_OBJDUMP) -o $(NAME_OBJDUMP) $(LDFLAGS)
clean:
	rm -rf $(OBJ_NM)
	rm -rf $(OBJ_OBJDUMP)
	rm -rf $(OBJ_TESTS)

fclean: clean
	rm -rf $(NAME_NM)
	rm -rf $(NAME_OBJDUMP)

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

.PHONY: all clean fclean re tests_run rclean nm objdump
