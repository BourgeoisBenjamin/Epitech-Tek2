/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

Test(Picture, creation_without_parameter, .init=redirect_all_std)
{
    Picture test;
}

Test(Picture, creation_with_parameter, .init=redirect_all_std)
{
    Picture test("./sample/alien.txt");
}


Test(Picture, creation_file_no_exist, .init=redirect_all_std)
{
    Picture test("./sample/no_exist.txt");
}

Test(Picture, creation_file_no_exist_2, .init=redirect_all_std)
{
    Picture test("./sample/alien.txt");
    test.getPictureFromFile("no_exist.txt");
    cr_assert_str_eq(test.data.c_str(), "ERROR");
}

Test(Picture, test_assignement, .init=redirect_all_std)
{
    Picture test("./sample/alien.txt");
    Picture test2("./sample/bo_beep.txt");
    cr_assert_eq(test.data, "         _|_\n"
                                "   ,_.-_' _ '_-._,\n"
                                "    l (.)(.)(.) /\n"
                                " _,  `l_-===-_/`  ,_\n"
                                ">  |----\"\"\"\"\"----|  <\n"
                                "`\"\"`--/   _-@-l--`\"\"`\n"
                                "     |===L_I===|\n"
                                "      l       /\n"
                                "      _l__|__/_\n"
                                "     `\"\"\"\"`\"\"\"\"`\n");
    cr_assert_eq(test2.data, " ____\n"
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
    test2 = test;
    cr_assert_eq(test.data, "         _|_\n"
                            "   ,_.-_' _ '_-._,\n"
                            "    l (.)(.)(.) /\n"
                            " _,  `l_-===-_/`  ,_\n"
                            ">  |----\"\"\"\"\"----|  <\n"
                            "`\"\"`--/   _-@-l--`\"\"`\n"
                            "     |===L_I===|\n"
                            "      l       /\n"
                            "      _l__|__/_\n"
                            "     `\"\"\"\"`\"\"\"\"`\n");
    cr_assert_eq(test2.data, "         _|_\n"
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

Test(Picture, test_copy_constructor, .init=redirect_all_std)
{
    Picture test("./sample/alien.txt");
    Picture test2 = test;
    cr_assert_eq(test.data, "         _|_\n"
                            "   ,_.-_' _ '_-._,\n"
                            "    l (.)(.)(.) /\n"
                            " _,  `l_-===-_/`  ,_\n"
                            ">  |----\"\"\"\"\"----|  <\n"
                            "`\"\"`--/   _-@-l--`\"\"`\n"
                            "     |===L_I===|\n"
                            "      l       /\n"
                            "      _l__|__/_\n"
                            "     `\"\"\"\"`\"\"\"\"`\n");
    cr_assert_eq(test2.data, "         _|_\n"
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