##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A simple Makefile
##

NAME	=	libasm.so

NAME_TESTS	=	unit_test

SRC	=	src/strlen.asm	\
		src/strchr.asm	\
		src/memset.asm	\
		src/memcpy.asm	\
		src/strcmp.asm	\
		src/strncmp.asm	\
		src/rindex.asm	\
		src/strcasecmp.asm	\
		src/memmove.asm	\
		src/strstr.asm	\
		src/strpbrk.asm	\
		src/strcspn.asm	\

SRC_TESTS	=	tests/tests_redirect.c	\
				tests/tests_strlen.c	\
				tests/tests_strchr.c	\
				tests/tests_memset.c	\
				tests/tests_memcpy.c	\
				tests/tests_strcmp.c	\
				tests/tests_strncmp.c	\
				tests/tests_rindex.c	\
				tests/tests_strcasecmp.c	\
				tests/tests_memmove.c	\
				tests/tests_strstr.c	\
				tests/tests_strcspn.c	\
				tests/tests_strpbrk.c	\

ASMFLAGS	=	-f elf64

CFLAGS	+=	\

LDFLAGS	=	-shared

LDFLAGS_TESTS	=	-lasm -lcriterion --coverage -L./ \

OBJ	=	$(SRC:.asm=.o)

OBJ_TESTS =	$(SRC_TESTS:.c=.o)

ASM	=	nasm

CC	=	gcc

LD	=	ld

%.o: %.asm
		$(ASM) -o $@ $< $(ASMFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
		$(LD) $(LDFLAGS) -o $(NAME) $(OBJ) -fPIC

clean:
		rm -rf $(OBJ)
		rm -rf $(OBJ_TESTS)

fclean: clean
		rm -rf $(NAME)
		rm -rf $(NAME_TESTS)

tests_run: all
tests_run: CFLAGS += -W -Wall -Wextra -Wshadow -Werror -fno-builtin
tests_run: clean $(OBJ_TESTS)
	$(CC) -o $(NAME_TESTS) $(OBJ_TESTS) $(LDFLAGS_TESTS)
	./$(NAME_TESTS)

re: fclean all

.PHONY: all clean fclean re