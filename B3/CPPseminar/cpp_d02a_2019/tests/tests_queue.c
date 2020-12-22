/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "queue.h"

Test(queue, main_test, .init = redirect_all_std)
{
    queue_t queue = NULL;
    int i = 5;
    int j = 4;
    int *data = NULL;

    queue_push(&queue, &i);
    queue_push(&queue, &j);
    data = (int *)queue_front(queue);
    printf("%d\n", *data);
    fflush(stdout);
    cr_assert_stdout_eq_str("5\n");
}