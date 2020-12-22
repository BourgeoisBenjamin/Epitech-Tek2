/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** TODO: add description
*/

#include "../include/reallocarray.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if (nmemb > 0 && SIZE_MAX / nmemb < size) {
        errno = ENOMEM;
        return (NULL);
    }
    return (realloc(ptr, nmemb * size));
}