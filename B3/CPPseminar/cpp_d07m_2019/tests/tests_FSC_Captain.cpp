/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(FSC_Captain, Test00, .init=redirect_all_std)
{
    Federation::Starfleet::Captain James("James T. Kirk");
    std::string name = "James T. Kirk";

    fflush(stdout);
    cr_assert_eq(James.getName(), name);
}

Test(FSC_Captain, Test01, .init=redirect_all_std)
{
    Federation::Starfleet::Captain James("James T. Kirk");
    int age = 18;
    James.setAge(age);

    fflush(stdout);
    cr_assert_eq(James.getAge(), age);
}

Test(FSC_Captain, Test02, .init=redirect_all_std)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
    Federation::Starfleet::Captain James("James T. Kirk");

    UssKreog.promote(&James);
    fflush(stdout);
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\n"
    "It is 289 m in length and 132 m in width.\n"
    "It can go to Warp 6!\nJames T. Kirk: I'm glad to be the "
    "captain of the USS Kreog.\n");
}