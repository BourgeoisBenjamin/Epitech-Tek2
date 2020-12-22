/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** TODO: add description
*/

#include <string.h>
#include <unistd.h>

int prout = 1;

void toto(void)
{
    char *str = "Bonjour";
    write(1, str, sizeof(str));
}

int main(void)
{
    toto();
    return (0);
}