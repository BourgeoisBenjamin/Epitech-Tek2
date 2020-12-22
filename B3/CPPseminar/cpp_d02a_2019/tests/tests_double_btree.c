/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "double_btree.h"

void btree_populate_left(double_btree_t tree);
void btree_populate_tree(double_btree_t *tree);
void btree_test_size(double_btree_t tree);
void btree_test_values(double_btree_t tree);
void btree_final_test(double_btree_t tree);

Test(double_btree_get_values, test1, .init = redirect_all_std)
{
    double_btree_t tree = NULL;
    btree_populate_tree(&tree);
    btree_test_size(tree);
    btree_test_values(tree);
    btree_final_test(tree);
    fflush(stdout);
    cr_assert_stdout_eq_str("The tree's size is 5\nThe tree's depth is 3\n"
                            "The tree's values range from 5.000000 to"
                            " 100.000000\nList is not empty\nList is empty\n");
}