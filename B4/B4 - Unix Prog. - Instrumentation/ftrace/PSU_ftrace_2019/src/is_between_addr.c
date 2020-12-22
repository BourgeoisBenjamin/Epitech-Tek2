/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** is_between_addr
*/

#include <stdbool.h>
#include <stdlib.h>

bool is_between_addr(char *s1, char *s2, unsigned long long addr, \
unsigned long long *lib_addr)
{
    unsigned long long n1 = strtol(s1, NULL, 16);
    unsigned long long n2 = strtol(s2, NULL, 16);

    *lib_addr = n1;
    return (n1 <= addr && n2 >= addr);
}