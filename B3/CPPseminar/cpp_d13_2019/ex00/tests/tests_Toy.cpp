/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

Test(Toy, creation_without_parameter, .init=redirect_all_std)
{
    Toy test;
    cr_assert_eq(test.getType(), Toy::BASIC_TOY);
    cr_assert_eq(test.getName(), "toy");
}

Test(Toy, creation_with_parameter, .init=redirect_all_std)
{
    Toy test(Toy::ALIEN, "Benjamin", "./sample/alien.txt");
    cr_assert_eq(test.getType(), Toy::ALIEN);
    cr_assert_eq(test.getName(), "Benjamin");
}

Test(Toy, set_get_name, .init=redirect_all_std)
{
    Toy test(Toy::ALIEN, "Benjamin", "./sample/alien.txt");
    test.setName("Chloé");
    cr_assert_eq(test.getName(), "Chloé");
}

Test(Toy, test_get_ascii, .init=redirect_all_std)
{
    Toy test(Toy::ALIEN, "Benjamin", "./sample/alien.txt");
    cr_assert_eq(test.getAscii(), "         _|_\n"
                                  "   ,_.-_' _ '_-._,\n"
                                  "    l (.)(.)(.) /\n"
                                  " _,  `l_-===-_/`  ,_\n"
                                  ">  |----\"\"\"\"\"----|  <\n"
                                  "`\"\"`--/   _-@-l--`\"\"`\n"
                                  "     |===L_I===|\n"
                                  "      l       /\n"
                                  "      _l__|__/_\n"
                                  "     `\"\"\"\"`\"\"\"\"`\n");
}

Test(Toy, test_set_ascii, .init=redirect_all_std)
{
    Toy test(Toy::ALIEN, "Benjamin", "./sample/alien.txt");
    test.setAscii("./sample/bo_beep.txt");
    cr_assert_eq(test.getAscii(), " ____\n"
                                    "//---ll\n"
                                    "||   ||\n"
                                    "//  ,//\n"
                                    "`  //'\n"
                                    "   ||    .-\"\"\"-.\n"
                                    "   ||   / .---. l\n"
                                    "   ||  | (///ll) |\n"
                                    "   ||   l( '.' )/\n"
                                    "   ||     l e /\n"
                                    "   ||   .,_) (_,.\n"
                                    "   (=l (_)     (_),/)\n"
                                    "   ||ll//(`---`)ll//\n"
                                    "   || l/  l   /  l/\n"
                                    "   ||    __l=/__\n"
                                    "   ||.-'` .-\"-. `'-.\n"
                                    "   ||`\"-'`     `'-\"``'.\n"
                                    "  /||)       ()       (l\n"
                                    " / ||   ()        ()    l\n"
                                    ";) ||       ()       ()  ;\n"
                                    "|  || ()         ()      |\n"
                                    "|  ||     ()        ()  (|\n"
                                    "|()||         ()         |\n"
                                    "|  ||  ()             () |\n"
                                    "| (||       ()    ()     |\n"
                                    "'--||'---'---'---'---'---'\n");
}