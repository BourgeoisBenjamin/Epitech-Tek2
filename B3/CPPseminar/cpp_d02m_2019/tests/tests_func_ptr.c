/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "func_ptr.h"

void print_normal(const char *str);
void print_reverse(const char *str);
void print_upper(const char *str);
void print_42(const char *str);
void do_action(action_t action, const char *str);

Test(func_ptr, test00, .init = redirect_all_std)
{
    const char *str = "I'm using function pointers !";
    do_action(PRINT_NORMAL, str);
    do_action(PRINT_REVERSE, str);
    do_action(PRINT_UPPER, str);
    do_action(PRINT_42, str);
    fflush(stdout);
    cr_assert_stdout_eq_str("I'm using function pointers !\n"
                            "! sretniop noitcnuf gnisu m'I\n"
                            "I'M USING FUNCTION POINTERS !\n42\n");
}