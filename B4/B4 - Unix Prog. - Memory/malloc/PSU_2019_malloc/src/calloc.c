/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** TODO: add description
*/

#include "../include/calloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = NULL;

    if ((ptr = malloc(nmemb * size)) == NULL)
        return (NULL);
    memset(ptr, 0, nmemb * size);
    return (ptr);
}