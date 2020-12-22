/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "double_list.h"

void dl_populate_list(double_list_t *list_head);
void dl_test_size(double_list_t list_head);
void dl_test_del(double_list_t *list_head);

Test(double_list_get_values, test1, .init = redirect_all_std)
{
    double_list_t list_head = NULL;
    dl_populate_list(&list_head);
    dl_test_size(list_head);
    dl_test_del(&list_head);
    fflush(stdout);
    cr_assert_stdout_eq_str("3.000000\n""There are 3 elements in the list\n"
                            "1.000000\n2.000000\n3.000000\n"
                            "There are 2 elements in the list\n"
                            "1.000000\n2.000000\n");
}