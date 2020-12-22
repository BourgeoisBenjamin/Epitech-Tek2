/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** finds file with PATH env variable
*/

#include "ftrace.h"
#include <fcntl.h>

static bool executable_exists(const char *filepath)
{
    if (!access(filepath, X_OK | R_OK))
        return (true);
    return (false);
}

static bool is_relative_path(const char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '/')
            return (true);
    }
    return (false);
}

static char *find_executable_file(char **paths, const char *filename)
{
    char *complete_path = NULL;
    int len = 0;

    for (int i = 0; paths[i]; i++) {
        len = strlen(paths[i]) + strlen(filename) + 2;
        complete_path = malloc(sizeof(char) * len);
        if (!complete_path)
            return (NULL);
        strcpy(complete_path, paths[i]);
        complete_path[strlen(paths[i])] = '/';
        strcpy(&complete_path[strlen(paths[i]) + 1], filename);
        if (executable_exists(complete_path))
            return (complete_path);
        free(complete_path);
    }
    return (NULL);
}

int find_and_open_file(const char *name)
{
    char *path = getenv("PATH");
    char **paths = NULL;
    char *real_path = NULL;
    int fd = -1;

    if (!path || is_relative_path(name))
        return (open(name, O_RDONLY));
    paths = split_str(path, ":");
    if (!paths)
        return (-1);
    real_path = find_executable_file(paths, name);
    if (real_path) {
        fd = open(real_path, O_RDONLY);
        free(real_path);
    }
    for (int i = 0; paths[i]; free(paths[i++]));
    free(paths);
    return (fd);
}
