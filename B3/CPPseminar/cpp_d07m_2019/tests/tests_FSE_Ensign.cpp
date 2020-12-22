/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(FSE_Ensign, Test00, .init=redirect_all_std)
{
    Federation::Starfleet::Ensign Ensign("Pavel Chekov");

    fflush(stdout);
    cr_assert_stdout_eq_str("Ensign Pavel Chekov, awaiting orders.\n");
}