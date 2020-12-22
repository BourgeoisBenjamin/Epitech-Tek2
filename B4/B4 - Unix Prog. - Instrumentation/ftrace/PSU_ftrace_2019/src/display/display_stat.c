/*
** EPITECH PROJECT, 2020
** strace
** File description:
** display stat struct
*/

#include "ftrace.h"
#include <sys/stat.h>

void display_stat(unsigned long long arg, pid_t child)
{
    struct stat stat;

    if (read_from_pid(child, (void *)arg, sizeof(struct stat), &stat)) {
        dprintf(2, "?");
        return;
    }
    stat.st_mode &= 0777;
    dprintf(2, "{st_mode=0%o, st_size=%lu, ...}", stat.st_mode, stat.st_size);
}
