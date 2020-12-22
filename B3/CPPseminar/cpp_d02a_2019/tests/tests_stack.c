/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "stack.h"

Test(stack, main_test, .init = redirect_all_std)
{
    stack_t stack = NULL;
    int i = 5;
    int j = 4;
    int *data = NULL;

    stack_push(&stack, &i);
    stack_push(&stack, &j);
    data = (int *)stack_top(stack);
    printf("%d\n", *data);
    fflush(stdout);
    cr_assert_stdout_eq_str("4\n");
}