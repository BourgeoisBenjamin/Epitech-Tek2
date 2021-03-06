/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <uuid/uuid.h>
#include "myteams_client.h"
#include "logging_client.h"

int reply_553(client_t *info, server_reply_t *header)
{
    unsigned char thread_uuid[16 + 1] = {0};
    char thread_unparse_uuid[36 + 1] = {0};
    (void)header;

    if (!smart_buffer_get_data(info->server_out, &thread_uuid, 16))
        return (CLIENT_ERROR);
    uuid_unparse(thread_uuid, thread_unparse_uuid);
    client_error_unknown_thread(thread_unparse_uuid);
    return (CLIENT_SUCCESS);
}