##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## A simple Makefile to compile my lib list
##

NAME	=	libmy_list.a

SRC	=	src/list_add_elem_at_back.c	\
		src/list_add_elem_at_front.c	\
		src/list_add_elem_at_position.c	\
		src/list_clear.c	\
		src/list_create_node.c	\
		src/list_del_elem_at_back.c	\
		src/list_del_elem_at_front.c	\
		src/list_del_elem_at_position.c	\
		src/list_del_elem_at_value.c	\
		src/list_delete_node.c	\
		src/list_dump.c	\
		src/list_get_elem_at_back.c	\
		src/list_get_elem_at_front.c	\
		src/list_get_elem_at_position.c	\
		src/list_get_first_node_with_value.c	\
		src/list_get_size.c	\
		src/list_is_empty.c	\

CFLAGS = 	-Iinclude -W -Wall -Wshadow -Wextra -Werror

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ./../

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ./../$(NAME)

re: fclean all

.PHONY: all clean fclean re
