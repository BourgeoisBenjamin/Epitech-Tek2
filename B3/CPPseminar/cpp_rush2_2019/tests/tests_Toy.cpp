/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** test Toy
*/

#include "unittest.hpp"

Test(IsTaken, test__Toy_00, .init = redirect_all_std)
{
    Toy *chat = new Toy("chat");
    chat->isTaken();
    cr_assert_stdout_eq_str("chat is taken\n");
    delete chat;
}

Test(getTitle, Test_Toy01, .init = redirect_all_std)
{
    Toy *toy = new Toy ("oui");
    cr_assert_eq((*toy).getTitle(), "oui");
}

Test(Toy, TestToy03, .init = redirect_all_std)
{
    Toy *toy = new Toy("JUL");
    cr_assert_eq(toy->getType(), TOY);
}

Test(Toy, TestToy04, .init = redirect_all_std)
{
    Toy *toy = new Toy("JUL");
    cr_assert_eq(toy->getIsTaken(), false);
}