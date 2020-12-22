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