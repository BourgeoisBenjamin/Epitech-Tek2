#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <zconf.h>
#include <stdlib.h>

int main()
{
    struct sockaddr_in address;
    int new_client;
    int opt = 1;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    int addrlen = sizeof(address);
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        return (84);
    }
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        return (84);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        return (84);
    }
    while (1) {
        if ((new_client = accept(server_fd, (struct sockaddr *) &address,
                                 (socklen_t *) &addrlen)) < 0) {
            perror("accept");
            return (84);
        }
        switch (fork()) {
            case -1:
                perror("fork");
                exit(84);
            case 0:
                printf("Connection from %s:%i\n", inet_ntoa(address.sin_addr),
                       ntohs(address.sin_port));
                send(new_client, "Hello World!!!\n", strlen("Hello World!!!\n"), 0);
            default:
                close(new_client);
        }
    }
    return 0;
}
