##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## UNIT TEST
##

NAME	=	unit_tests

SRC	=	double_btree_create_node.c	\
		double_btree_delete.c	\
		double_btree_get_depth.c	\
		double_btree_get_max_value.c	\
		double_btree_get_min_value.c	\
		double_btree_get_size.c	\
		double_btree_is_empty.c	\
		double_list_add_elem_at_back.c	\
		double_list_add_elem_at_front.c	\
		double_list_add_elem_at_position.c	\
		double_list_create_node.c	\
		double_list_del_elem_at_back.c	\
		double_list_del_elem_at_front.c	\
		double_list_del_elem_at_position.c	\
		double_list_del_node.c	\
		double_list_dump.c	\
		double_list_get_elem_at_back.c	\
		double_list_get_elem_at_front.c	\
		double_list_get_elem_at_position.c	\
		double_list_get_first_node_with_value.c	\
		double_list_get_size.c	\
		double_list_is_empty.c	\
		list_add_elem_at_back.c	\
		list_add_elem_at_front.c	\
		list_add_elem_at_position.c	\
		list_clear.c	\
		list_create_node.c	\
		list_del_elem_at_back.c	\
		list_del_elem_at_front.c	\
		list_del_elem_at_position.c	\
		list_del_node.c	\
		list_dump.c	\
		list_get_elem_at_back.c	\
		list_get_elem_at_front.c	\
		list_get_elem_at_position.c	\
		list_get_size.c	\
		list_is_empty.c	\
		list_get_first_node_with_value.c	\
		stack_get_size.c	\
		stack_is_empty.c	\
		stack_pop.c	\
		stack_push.c	\
		stack_top.c	\
		queue_front.c	\
		queue_get_size.c	\
		queue_is_empty.c	\
		queue_pop.c	\
		queue_push.c	\

SRC_TEST	=	tests/tests_redirect.c	\
				tests/tests_double_list_get_size.c	\
				tests/tests_double_list_is_empty.c	\
				tests/tests_double_list_get_elem_at_front.c	\
				tests/tests_double_btree.c	\
				tests/btree_ft.c	\
				tests/double_list_ft.c	\
				tests/tests_double_list.c	\
				tests/tests_generic_list.c	\
				tests/generic_list_ft.c	\
				tests/tests_stack.c	\
				tests/tests_queue.c	\

OBJECTS	=	$(SRC:.c=.o) $(SRC_TEST:.c=.o)

CFLAGS	=	-W -Wall -Wshadow -Wextra -Werror -I./tests/ -fprofile-arcs \
-ftest-coverage

LDFLAGS	=	-lcriterion --coverage

CC	=	gcc

all:	$(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(LDFLAGS)
	./$(NAME)

tests_run: $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(LDFLAGS)
	./$(NAME)

clean:
	rm -rf $(OBJECTS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean	all

.PHONY: all tests_run clean fclean re
