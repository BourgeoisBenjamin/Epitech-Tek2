/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** test LittlePony
*/

#include "unittest.hpp"

Test(Wrap, tests_Wrap_00, .init = redirect_all_std)
{
    if (1) {
        Wrap wrap;
        wrap.wrapMeThat(nullptr);
    }
    cr_assert_stderr_eq_str("Nothing to wrap\n");
}

Test(Wrap, tests_Wrap_01, .init = redirect_all_std)
{
    if (1) {
        Wrap wrap;
        Teddy *ours = new Teddy("ourson");
        wrap.openMe();
        wrap.wrapMeThat(ours);
    }
    cr_assert_stdout_eq_str("tuuuut tuuut tuut\n");
}

Test(Wrap, tests_Wrap_02, .init = redirect_all_std)
{
    if (1) {
        Box wrap;
        Teddy *ours = new Teddy("ourson");
        wrap.closeMe();
        wrap.wrapMeThat(ours);
    }
    cr_assert_stderr_eq_str("The wrap must be empty and open\n");
}

Test(Wrap, tests_Wrap_03, .init = redirect_all_std)
{
    if (1) {
        Box wrap;
        Teddy *ours = new Teddy("ourson");
        wrap.closeMe();
        wrap.openMe();
        wrap.closeMe();
        wrap.openMe();
        wrap.wrapMeThat(ours);
    }
    cr_assert_stdout_eq_str("A box is created\n"
                            "The box is already closed\n"
                            "The box is now closed\n"
                            "tuuuut tuuut tuut\n"
                            "A box is destroyed\n");
}

Test(Wrap, tests_Wrap_04, .init = redirect_all_std)
{
    if (1) {
        Box wrap;
        Teddy *ours = new Teddy("ourson");
        wrap.isTaken();
        wrap.getOpen();
        wrap.closeMe();
        wrap.openMe();
        wrap.wrapMeThat(ours);
    }
    cr_assert_stdout_eq_str("A box is created\n"
                            "The box is already closed\n"
                            "tuuuut tuuut tuut\n"
                            "A box is destroyed\n");
}