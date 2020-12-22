/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** TODO: add description
*/

#include "func_ptr.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; str[i]; i++) {
        printf("%c", toupper(str[i]));
    }
    printf("\n");
}

void print_42(const char *str)
{
    (void)str;
    printf("%i\n", 42);
}

void do_action(action_t action, const char *str)
{
    action_function_t all[] = {
        {PRINT_NORMAL, &print_normal},
        {PRINT_REVERSE, &print_reverse},
        {PRINT_UPPER, &print_upper},
        {PRINT_42, &print_42},
    };

    for (int i = 0; i < 5; i++) {
        if (action == all[i].action) {
            (*all[i].function)(str);
            break;
        }
    }
}