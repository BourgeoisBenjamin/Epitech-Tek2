/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** TODO: add description
*/

#include <unistd.h>
#include <stdio.h>

int myputchar(char c)
{
    return (write(1, &c, 1));
}

int my_strlen(char *str)
{
    return (*str) ? my_strlen(str + 1) + 1 : 0;
}

int my_putstr(char *str)
{
    return (write(1, str, my_strlen(str)));
}

void *malloc(size_t size)
{
    fprintf(stderr, "Flying cats are the best!!!\n");
    return (NULL);
}