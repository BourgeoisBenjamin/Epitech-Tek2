/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** splits a string into an array
*/

#include "ftrace.h"

int find_token_count(const char *str, const char *separator)
{
    char *dup = strdup(str);
    int nb = 0;

    if (!dup)
        return (0);
    if (strtok(dup, separator)) {
        nb++;
        while (strtok(NULL, separator))
            nb++;
    }
    free(dup);
    return (nb);
}

char **split_str(const char *str, const char *separator)
{
    int tokens = find_token_count(str, separator);
    char **split = malloc(sizeof(char *) * (tokens + 1));
    char *dup = strdup(str);
    char *token = NULL;

    if (!split || !dup)
        return (NULL);
    split[tokens] = NULL;
    token = strtok(dup, separator);
    for (int i = 0; token; i++, token = strtok(NULL, separator)) {
        split[i] = strdup(token);
        if (!split[i])
            return (NULL);
    }
    return (split);
}
