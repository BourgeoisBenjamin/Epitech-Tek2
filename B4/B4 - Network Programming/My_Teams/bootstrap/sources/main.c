#include "step1.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct message_s
{
    char buff[MAX_COMMAND_LENGTH + 1];
    int write_pos;
    int read_pos;
} message_t;

int tcp_add_to_message(message_t *message, char *str)
{
    if (!message || !str)
        return (1);
    for (size_t i = 0; i < strlen(str); i++, message->write_pos++) {
        if (message->write_pos >= MAX_COMMAND_LENGTH)
            message->write_pos = 0;
        message->buff[message->write_pos] = str[i];
    }
    return (1);
}

char *tcp_getline_receive(message_t *receive)
{
    char buff[MAX_COMMAND_LENGTH];
    int i = 0;
    int j = 0;

    bzero(&buff, MAX_COMMAND_LENGTH);
    for (i = receive->read_pos, j = 0; i != receive->write_pos; i++, j++) {
        if (i >= MAX_COMMAND_LENGTH) {
            i = -1;
            j--;
            continue;
        }
        buff[j] = receive->buff[i];
        if (buff[j] == '\n')
            break;
    }
    if (i == receive->write_pos) return (NULL);
    bzero(&receive->buff[receive->read_pos], j);
    receive->read_pos = i + 1;
    return (strdup(buff));
}

message_t *tcp_new_message(void)
{
    message_t *message = malloc(sizeof(message_t));

    if (!message)
        return (NULL);
    bzero(message->buff, MAX_COMMAND_LENGTH + 1);
    message->write_pos = 0;
    message->read_pos = 0;
    return (message);
}

int tcp_receive_message(int socket, message_t *receive)
{
    int read_nb = 0;
    char buff[MAX_COMMAND_LENGTH + 1];

    bzero(&buff, MAX_COMMAND_LENGTH + 1);
    if ((read_nb = read(socket, buff, MAX_COMMAND_LENGTH)) == 0)
        return (0);
    for (size_t i = 0; i < strlen(buff); i++, receive->write_pos++) {
        if (receive->write_pos >= MAX_COMMAND_LENGTH)
            receive->write_pos = 0;
        receive->buff[receive->write_pos] = buff[i];
    }
    return (1);
}

int main(void) {
  // disable printf buffering for stdout.
  // do not remove please.
  setvbuf(stdout, NULL, _IONBF, 0);
  fd_set read_fd;
  /**
   * EXAMPLE CODE WHICH WILL NOT WORK ...
   * PLEASE PATCH IT ;-)
   */
  char buffer[MAX_COMMAND_LENGTH + 1] = {0};
  message_t *message = tcp_new_message();
  char *line = NULL;
  int status = 0;
  do {

    FD_ZERO(&read_fd);
    FD_SET(0, &read_fd);
    select(FD_SETSIZE, &read_fd, NULL, NULL, NULL);
    if (!FD_ISSET(0, &read_fd))
        continue;

    status = tcp_receive_message(0, message);

    if (status == 0)
        break;
    if (status == -1) {
        perror("read()");
        return EPI_EXIT_FAILURE;
    }
    while ((line = tcp_getline_receive(message)) != NULL) {
        memset(buffer, 0, MAX_COMMAND_LENGTH);
        strcpy(buffer, line);
        if (on_command(buffer) == false)
            return EPI_EXIT_FAILURE;
    }
  } while (status);
  return EPI_EXIT_SUCCESS;
}
