/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(FS_setupCore, Test00, .init=redirect_all_std)
{
    Federation::Ship Independent(150, 230, "Greok");

    WarpSystem::QuantumReactor QR2;
    WarpSystem::Core core2(&QR2);

    Independent.setupCore(&core2);
    Independent.checkCore();

    QR2.setStability(false);
    Independent.checkCore();

    fflush(stdout);
    cr_assert_stdout_eq_str("The independent ship Greok just finished "
                            "its construction.\nIt is 150 m in length and "
                            "230 m in width.\nGreok: The core is set.\n"
                            "Greok: The core is stable at the time.\n"
                            "Greok: The core is unstable at the time.\n");
}