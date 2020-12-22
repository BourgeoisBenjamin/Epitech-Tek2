/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "generic_list.h"

void int_displayer(void *data);
void g_test_size(list_t list_head);
void g_test_del(list_t *list_head);

Test(generic_list, main_test, .init = redirect_all_std)
{
    list_t list_head = NULL;
    int i = 5;
    int j = 42;
    int k = 3;

    list_add_elem_at_back(&list_head, &i);
    list_add_elem_at_back(&list_head, &j);
    list_add_elem_at_back(&list_head, &k);
    g_test_size(list_head);
    g_test_del(&list_head);
    fflush(stdout);
    cr_assert_stdout_eq_str("There are 3 elements in the list\n5\n42\n3\n"
                            "There are 2 elements in the list\n5\n42\n");
}