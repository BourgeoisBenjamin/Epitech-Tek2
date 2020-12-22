/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** TODO: add description
*/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("%i\n", sbrk(4));
    printf("%i\n", sbrk(0));
    printf("%i\n", sbrk(-4));
    return 0;
}