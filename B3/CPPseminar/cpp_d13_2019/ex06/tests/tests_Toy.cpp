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

Test(Toy, test_get_Picture, .init=redirect_all_std)
{
    Toy test(Toy::ALIEN, "Benjamin", "./sample/alien.txt");
    test.getPicture();
}

Test(Toy, test_assignment, .init=redirect_all_std)
{
    Toy test(Toy::ALIEN, "Benjamin", "./sample/alien.txt");
    Toy test2(Toy::BASIC_TOY, "Chloé", "./sample/bo_beep.txt");
    test2 = test;
    cr_assert_eq(test.getName(), test2.getName());
}

Test(Toy, test_copyconstructor, .init=redirect_all_std)
{
    Toy test(Toy::ALIEN, "Benjamin", "./sample/alien.txt");
    Toy test2 = test;
    cr_assert_eq(test.getName(), test2.getName());
}

Test(Toy, test_speak, .init=redirect_all_std)
{
    Toy test(Toy::ALIEN, "Benjamin", "./sample/alien.txt");
    test.speak("I speak for a test");
    cr_assert_stdout_eq_str("Benjamin \"I speak for a test\"\n");
}

Test(Toy, test_cout, .init=redirect_all_std)
{
    Toy test(Toy::ALIEN, "Benjamin", "./sample/alien.txt");
    std::cout << test;
    cr_assert_stdout_eq_str("Benjamin\n         _|_\n"
                            "   ,_.-_' _ '_-._,\n"
                            "    l (.)(.)(.) /\n"
                            " _,  `l_-===-_/`  ,_\n"
                            ">  |----\"\"\"\"\"----|  <\n"
                            "`\"\"`--/   _-@-l--`\"\"`\n"
                            "     |===L_I===|\n"
                            "      l       /\n"
                            "      _l__|__/_\n"
                            "     `\"\"\"\"`\"\"\"\"`\n\n");
}

Test(Toy, test_change_ascii, .init=redirect_all_std)
{
    Toy test(Toy::ALIEN, "Benjamin", "./sample/alien.txt");
    test << "ASCIIII";
    std::cout << test;
    cr_assert_stdout_eq_str("Benjamin\nASCIIII\n");
}

Test(Toy, test_error_handling, .init=redirect_all_std)
{
    Toy test(Toy::ALIEN, "Benjamin", "./sample/no_exist.txt");
    test.setAscii("no_exist");
    cr_assert_eq(test.getLastError().type, Toy::Error::PICTURE);
    cr_assert_eq(test.getLastError().what(), "bad new illustration");
    cr_assert_eq(test.getLastError().where(), "setAscii");
}

Test(Toy, test_error_handling_2, .init=redirect_all_std)
{
    Toy test(Toy::ALIEN, "Benjamin", "./sample/no_exist.txt");
    test.speak_es("Moula");
    cr_assert_eq(test.getLastError().type, Toy::Error::SPEAK);
    cr_assert_eq(test.getLastError().what(), "wrong mode");
    cr_assert_eq(test.getLastError().where(), "speak_es");
}

Test(Toy, test_error_handling_3, .init=redirect_all_std)
{
    Toy test(Toy::ALIEN, "Benjamin", "./sample/alien.txt");
    cr_assert_eq(test.getLastError().type, Toy::Error::UNKNOWN);
    cr_assert_eq(test.getLastError().what(), "");
    cr_assert_eq(test.getLastError().where(), "");
}