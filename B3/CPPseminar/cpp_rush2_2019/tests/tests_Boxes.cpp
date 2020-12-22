/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** test Boxes
*/

#include "unittest.hpp"

Test(closeMe, tests_Boxe_open, .init = redirect_all_std)
{
    if (1) {
        Box box;
        box.setOpen(true);
        box.closeMe();
    }
    cr_assert_stdout_eq_str("A box is created\n"
                            "The box is now closed\n"
                            "A box is destroyed\n");
}

Test(closeMe, tests_Boxe_close, .init = redirect_all_std)
{
    if (1) {
        Box box;
        box.setOpen(false);
        box.closeMe();
    }
    cr_assert_stdout_eq_str("A box is created\n"
                            "The box is already closed\n"
                            "A box is destroyed\n");
}

Test(Wrap, test_box_03, .init = redirect_all_std)
{
    Wrap *toy = new Wrap();
    cr_assert_eq(toy->getType(), WRAP);
}

Test(Wrap, TestBox04, .init = redirect_all_std)
{
    Wrap *toy = new Wrap();
    cr_assert_eq(toy->getIsTaken(), false);
}

Test(Box, test_box_05, .init = redirect_all_std)
{
    Box *toy = new Box();
    cr_assert_eq(toy->getType(), BOX);
}

Test(Box, test_box_06, .init = redirect_all_std)
{
    Box *toy = new Box();
    cr_assert_eq(toy->getIsTaken(), false);
}

Test(GiftPaper, test_box_07, .init = redirect_all_std)
{
    GiftPaper *toy = new GiftPaper();
    cr_assert_eq(toy->getType(), GIFTPAPER);
}

Test(GiftPaper, test_box_08, .init = redirect_all_std)
{
     if (1) {
        GiftPaper *toy = new GiftPaper();
        toy->setOpen(true);
    }
    cr_assert_stdout_eq_str("Here a new GiftPaper\n"
    "The GiftPaper is torn\n");
}