/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(FS_Ship, Test00, .init=redirect_all_std)
{
    Federation::Ship Independent(150, 230, "Greok");
    fflush(stdout);
    cr_assert_stdout_eq_str("The independent ship Greok just finished "
                            "its construction.\nIt is 150 m in length and "
                            "230 m in width.\n");
}

Test(FS_Ship, Test01, .init=redirect_all_std)
{
    Federation::Ship Independent(150, 230, "Greok");
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);
    Independent.setupCore(&core);
    Independent.checkCore();

    Destination d = ROMULUS;
    Independent.move(1, d);
    Independent.move(20, d);
    Independent.move(1);
    Independent.move(20);
    Independent.move(d);
    QR.setStability(false);
    Independent.move(d);
    Independent.move();
    QR.setStability(true);
    Independent.move();
    fflush(stdout);
    cr_assert_stdout_eq_str("The independent ship Greok just finished its "
                            "construction.\nIt is 150 m in length and 230 m in "
                            "width.\nGreok: The core is set.\nGreok: The core "
                            "is stable at the time.\n");
}