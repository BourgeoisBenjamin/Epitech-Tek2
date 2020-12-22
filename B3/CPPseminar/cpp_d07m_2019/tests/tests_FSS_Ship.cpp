/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(FSS_Ship, Test00, .init=redirect_all_std)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
    fflush(stdout);
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n");
}

Test(FSS_Ship, Test01, .init=redirect_all_std)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6, 10);
    fflush(stdout);
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\n"
    "It is 289 m in length and 132 m in width.\n"
    "It can go to Warp 6!\nWeapons are set: 10 torpedoes ready.\n");
}

Test(FSS_Ship, Test02, .init=redirect_all_std)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6, 10);
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);
    UssKreog.setupCore(&core);
    UssKreog.checkCore();

    Destination d = VULCAN;
    UssKreog.move(2, d);
    UssKreog.move(20, d);
    UssKreog.move(2);
    UssKreog.move(20);
    UssKreog.move(d);
    QR.setStability(false);
    UssKreog.move(d);
    UssKreog.move();
    QR.setStability(true);
    UssKreog.move();
    fflush(stdout);
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\nIt can go to Warp 6!\n"
        "Weapons are set: 10 torpedoes ready.\n"
        "USS Kreog: The core is set.\n"
        "USS Kreog: The core is stable at the time.\n");
}

Test(FSS_Ship, Test03, .init=redirect_all_std)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6, 10);
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);
    UssKreog.setupCore(&core);
    UssKreog.checkCore();

    UssKreog.setShield(20);
    cr_assert_eq(UssKreog.getShield(), 20);
    UssKreog.setTorpedo(67);
    cr_assert_eq(UssKreog.getTorpedo(), 67);
}

Test(FSS_Ship, Test04, .init=redirect_all_std)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6, 10);
    Federation::Starfleet::Captain James("James T. Kirk");
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);
    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    UssKreog.promote(&James);

    Borg::Ship *Independent = new Borg::Ship();

    UssKreog.setShield(20);
    cr_assert_eq(UssKreog.getShield(), 20);
    UssKreog.setTorpedo(67);
    cr_assert_eq(UssKreog.getTorpedo(), 67);
    UssKreog.fire(2, Independent);
    UssKreog.fire(Independent);
    UssKreog.fire(80, Independent);
    UssKreog.setTorpedo(0);
    UssKreog.fire(0, Independent);
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "Weapons are set: 10 torpedoes ready.\n"
        "USS Kreog: The core is set.\n"
        "USS Kreog: The core is stable at the time.\n"
        "James T. Kirk: I'm glad to be the captain of the USS Kreog.\n"
        "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
        "Kreog: Firing on target. 65 torpedoes remaining.\n"
        "Kreog: Firing on target. 64 torpedoes remaining.\n"
        "Kreog: No enough torpedoes to fire, James T. Kirk!\n"
        "Kreog: No more torpedo to fire, James T. Kirk!\n");
}