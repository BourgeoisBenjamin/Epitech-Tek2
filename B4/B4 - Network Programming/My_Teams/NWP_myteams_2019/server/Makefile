##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
## File description:
## Makefile
##

NAME	= 	myteams_server

LIB_NAME	=	utils

SRCS	=	src/main.c												\
			src/my_teams.c											\
			src/help/help.c											\
			src/server/init_server.c								\
			src/server/launch_server.c								\
			src/server/translate_select.c							\
			src/server/new_connection.c								\
			src/server/read_data_client.c							\
			src/server/write_data_client.c							\
			src/server/delete_server.c								\
			src/server/translate_data_client.c						\
			src/signal/sig_handler.c								\
			src/signal/terminate.c									\
			src/message/message_create.c							\
			src/message/delete_message.c							\
			src/client/create_client.c								\
			src/client/delete_client.c								\
			src/client/client_utils.c								\
			src/buffer/concat_buffer.c								\
			src/buffer/erase_buffer.c								\
			src/utils/send_response.c								\
			src/utils/send_error_arguments.c						\
			src/utils/send_error_already_exist.c					\
			src/user/create_user.c									\
			src/user/user_utils.c									\
			src/user/delete_user.c									\
			src/utils/get_args_command.c							\
			src/uuid/get_uuid.c										\
			src/team/create_team.c									\
			src/team/delete_team.c									\
			src/team/user_is_in_team.c								\
			src/channel/create_channel.c							\
			src/thread/create_thread.c								\
			src/reply/create_reply.c								\
			src/channel/delete_channel.c							\
			src/thread/delete_thread.c								\
			src/reply/delete_reply.c								\
			src/server/commands/help/command_help.c					\
			src/server/commands/login/command_login.c				\
			src/server/commands/logout/command_logout.c				\
			src/server/commands/user/command_user.c					\
			src/server/commands/users/command_users.c				\
			src/server/commands/messages/command_messages.c			\
			src/server/commands/create/command_create.c				\
			src/server/commands/create/command_create_team.c		\
			src/server/commands/create/command_create_channel.c		\
			src/server/commands/create/command_create_thread.c		\
			src/server/commands/create/command_create_reply.c		\
			src/server/commands/send/command_send.c					\
			src/server/commands/use/command_use.c					\
			src/server/commands/subscribe/command_subscribe.c		\
			src/server/commands/unsubscribe/command_unsubscribe.c	\
			src/server/commands/subscribed/command_subscribed.c		\
			src/server/commands/info/command_info.c					\
			src/server/commands/list/command_list.c					\
			src/load/users/load_users.c								\
			src/load/users/read_user_data.c							\
			src/load/teams/load_teams.c								\
			src/load/teams/load_team_data.c							\
			src/load/teams/load_channel.c							\
			src/load/teams/load_thread.c							\
			src/load/load_utils.c									\
			src/saving/saving_utils.c								\
			src/saving/save_users.c									\
			src/saving/save_server.c								\
			src/saving/prepare_saving_directory.c					\
			src/saving/save_teams.c									\
			src/saving/save_channels.c								\
			src/saving/save_threads.c								\

CFLAGS += 	-W -Wall -Wextra -Wshadow -I include/ -I ../lib/include -I ../include -I ./../libs/myteams/

LDFLAGS +=  -l $(LIB_NAME) -L ./../lib/ -luuid -lmyteams -L ./../libs/myteams

OBJS	=	$(SRCS:.c=.o)

OBJS_TESTS =	$(SRCS:.c=.gcda) $(SRCS:.c=.gcno)

CC	=	gcc

RM		=	rm -f

MV 	=	mv

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	$(MV) $(NAME) ../

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_TESTS)

fclean: clean
	$(RM) ../$(NAME)

tests_run: LDFLAGS += -lgcov --coverage
tests_run: CFLAGS += -fprofile-arcs -ftest-coverage
tests_run: re
			./tests/tests.sh

debug: CFLAGS += -g
debug: all

re: fclean all

.PHONY: all clean fclean re tests_run debug
