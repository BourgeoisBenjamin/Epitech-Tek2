##
## EPITECH PROJECT, 2020
## ftrace
## File description:
## Makefile for tests
##

NAME	=	ftrace

SRC	=	src/main.c	\
		src/syscalls.c	\
		src/get_name_symbol.c	\
		src/linked_list/generic_list_del_elem.c	\
		src/linked_list/stack.c	\
		src/linked_list/generic_list_add_elem.c	\
		src/linked_list/generic_list_utils.c	\
		src/linked_list/generic_list.c	\
		src/linked_list/generic_list_get_elem.c	\
		src/signal_handler.c	\
		src/read_from_pid.c	\
		src/display.c	\
		src/my_ftrace.c	\
		src/display/display_stat.c	\
		src/display/display_function_call.c	\
		src/display/display_basics.c	\
		src/display/display_string.c	\
		src/signals.c	\
		src/trace_signal.c	\
		src/utils.c	\
		src/ftrace_info_utils.c	\
		src/my_split.c	\
		src/find_and_open_file.c	\
		src/map/map.c	\
		src/get_lib_path.c	\
		src/utils/free_array.c	\
		src/utils/get_size_array.c	\
		src/utils/my_strtok.c	\
		src/is_between_addr.c		\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-W -Wall -Wextra -Wshadow		\
			-Iinclude

LDFLAGS	=	-lelf

RM	=	rm -f

CC	=	gcc


all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

debug: CFLAGS += -g
debug: re

.PHONY: clean fclean re
