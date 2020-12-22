/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "mem_ptr.h"

Test(mem_ptr, test00, .init = redirect_all_std)
{
    char *str1 = "Hey, ";
    char *str2 = "it works !";
    char *res;
    add_str(str1, str2, &res);
    printf("%s\n", res);
    fflush(stdout);
    cr_assert_stdout_eq_str("Hey, it works !\n");
}

Test(mem_ptr, test01, .init = redirect_all_std)
{
    char *str1 = "Hey, ";
    char *str2 = "it works !";
    str_op_t str_op;
    str_op.str1 = str1;
    str_op.str2 = str2;
    add_str_struct(&str_op);
    printf("%s\n", str_op.res);
    fflush(stdout);
    cr_assert_stdout_eq_str("Hey, it works !\n");
}