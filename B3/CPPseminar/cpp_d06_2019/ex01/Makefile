##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A simple Makefile
##

NAME	=	my_convert_temp

SRC	=	main.cpp	\
		my_convert_temp.cpp	\

CXXFLAGS += 	-W -Wall -Wextra -Wshadow -Werror

LDFLAGS =	\

OBJ	=	$(SRC:.cpp=.o)

CC	=	g++

all:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

debug : CXXFLAGS += -g
debug : re

re: fclean all

.PHONY: all clean fclean re
