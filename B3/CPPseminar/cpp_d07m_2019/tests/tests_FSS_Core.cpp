/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(FSS_setupCore, Test00, .init=redirect_all_std)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);

    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);

    UssKreog.setupCore(&core);
    UssKreog.checkCore();

    fflush(stdout);
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\nIt is "
                            "289 m in length and 132 m in width.\nIt can go "
                            "to Warp 6!\nUSS Kreog: The core is set.\nUSS "
                            "Kreog: The core is stable at the time.\n");
}

Test(FSS_setupCore, Test01, .init=redirect_all_std)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);

    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);
    QR.setStability(false);
    UssKreog.setupCore(&core);
    UssKreog.checkCore();

    fflush(stdout);
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\nIt is "
    "289 m in length and 132 m in width.\nIt can go "
    "to Warp 6!\nUSS Kreog: The core is set.\nUSS "
    "Kreog: The core is unstable at the time.\n");
}