/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

Test(Ex00, test0, .init=redirect_all_std)
{
    int a = 2;
    int b = 3;
    int z = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "min(b, z) = " << ::min(b, z) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    std::cout << "max(b, z) = " << ::max(b, z) << std::endl;
    std::cout << "add(a, b) = " << ::add(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    std::string y = "chaine2";

    ::swap(c, d);

    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "min(y, d) = " << ::min(y, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    std::cout << "max(y, d) = " << ::max(y, d) << std::endl;
    std::cout << "add(c, d) = " << ::add(c, d) << std::endl;

    cr_assert_stdout_eq_str("a = 3, b = 2\n"
                            "min(a, b) = 2\n"
                            "min(b, z) = 2\n"
                            "max(a, b) = 3\n"
                            "max(b, z) = 3\n"
                            "add(a, b) = 5\n"
                            "c = chaine2, d = chaine1\n"
                            "min(c, d) = chaine1\n"
                            "min(y, d) = chaine1\n"
                            "max(c, d) = chaine2\n"
                            "max(y, d) = chaine2\n"
                            "add(c, d) = chaine2chaine1\n");
}