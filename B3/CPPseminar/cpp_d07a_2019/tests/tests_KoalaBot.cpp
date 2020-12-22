/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(KoalaBot, Test00, .init=redirect_all_std)
{
    KoalaBot kb;
    std::cout << std::boolalpha << kb.status() << std::endl;
    kb.informations();
    fflush(stdout);
    cr_assert_stdout_eq_str("true\n[KoalaBot] Bob-01\n\t[Parts] Arms A-01 "
                            "status : OK\n\t[Parts] Legs L-01 status : OK\n"
                            "\t[Parts] Head H-01 status : OK\n");
}

Test(KoalaBot, Test01, .init=redirect_all_std)
{
    KoalaBot kb;
    Legs legs("1", false);
    Arms arms("2", true);
    Head head("3", true);
    kb.setParts(head);
    kb.setParts(arms);
    kb.setParts(legs);
    std::cout << std::boolalpha << kb.status() << std::endl;
    kb.informations();
    fflush(stdout);
    cr_assert_stdout_eq_str("false\n[KoalaBot] Bob-01\n\t[Parts] Arms 2 "
    "status : OK\n\t[Parts] Legs 1 status : KO\n"
    "\t[Parts] Head 3 status : OK\n");
}

Test(KoalaBot, Test02, .init=redirect_all_std)
{
    KoalaBot kb;
    Legs legs("1", false);
    Arms arms("2", true);
    Head head("3", true);
    Legs legs2("1", false);
    Arms arms2("2", false);
    Head head2("3", true);
    kb.swapParts(head2);
    kb.swapParts(arms2);
    kb.swapParts(legs2);
    std::cout << std::boolalpha << kb.status() << std::endl;
    kb.informations();
    fflush(stdout);
    cr_assert_stdout_eq_str("false\n[KoalaBot] Bob-01\n\t[Parts] Arms 2 "
    "status : KO\n\t[Parts] Legs 1 status : KO\n"
    "\t[Parts] Head 3 status : OK\n");
}

Test(KoalaBot, Test03, .init=redirect_all_std)
{
    Legs legs("1", false);
    Arms arms("2", false);
    Head head("3", true);
    std::cout << legs.serial() << arms.serial() << head.serial() << std::endl;
    fflush(stdout);
    cr_assert_stdout_eq_str("123\n");
}