#include "step1.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <zconf.h>

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
    int status = 0;
    do {

        FD_ZERO(&read_fd);
        FD_SET(0, &read_fd);
        select(FD_SETSIZE, &read_fd, NULL, NULL, NULL);
        if (!FD_ISSET(0, &read_fd))
            continue;

        memset(buffer, 0, MAX_COMMAND_LENGTH);
        status = read(0, buffer, MAX_COMMAND_LENGTH);

        if (status == 0)
            break;
        if (status == -1) {
            perror("read()");
            return EPI_EXIT_FAILURE;
        }

        char * line = strtok(strdup(buffer), "\n");
        char buffer[MAX_COMMAND_LENGTH + 1] = {0};
        while (line) {
            strcat(line, "\n");
            if (on_command(line) == false)
                return EPI_EXIT_FAILURE;
            line = strtok(NULL, "\n");
        }
    } while (status);
    return EPI_EXIT_SUCCESS;
}
