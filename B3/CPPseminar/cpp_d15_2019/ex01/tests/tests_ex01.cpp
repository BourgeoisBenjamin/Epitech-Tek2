/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"
#include "toto.hh"
#include "../ex01.hpp"

Test(Ex01, test0, .init=redirect_all_std)
{
    {
    std::string		v1 = "parapluie";
    std::string		v2 = "pluie";
    std::string		v3 = "volcan";
    std::string const	v4 = "météo";

    std::cout << ::compare(v1, v2) << std::endl;
    std::cout << ::compare(v2, v3) << std::endl;
    std::cout << ::compare(v1, v4) << std::endl;
    std::cout << ::compare(v1, v3) << std::endl;
    }

    std::cout << std::endl;

    {
    int		v1 = 42;
    int		v2 = 1337;
    int		v3 = -666;
    int const	v4 = 42;

    std::cout << ::compare(v1, v2) << std::endl;
    std::cout << ::compare(v2, v3) << std::endl;
    std::cout << ::compare(v1, v4) << std::endl;
    std::cout << ::compare(v1, v3) << std::endl;
    }

    std::cout << std::endl;

    {
    toto	v1;
    toto	v2;
    toto const	v3;

    std::cout << ::compare(v1, v2) << std::endl;
    std::cout << ::compare(v2, v3) << std::endl;
    std::cout << ::compare(v3, v1) << std::endl;
    }

    std::cout << std::endl;

    {
    const char	s1[8] = "chaineZ";
    const char	s2[10] = "chaineA42";
    const char	*s3 = "42";
    const char	*s4 = "lulz";
    const char	*s5 = "lulz";

    std::cout << ::compare<const char *>(s1, s2) << std::endl;
    std::cout << ::compare(s3, s4) << std::endl;
    std::cout << ::compare(s4, s5) << std::endl;
    }
    cr_assert_stdout_eq_str("-1\n"
                            "-1\n"
                            "1\n"
                            "-1\n"
                            "\n"
                            "-1\n"
                            "1\n"
                            "0\n"
                            "1\n"
                            "\n"
                            "0\n"
                            "0\n"
                            "0\n"
                            "\n"
                            "1\n"
                            "-1\n"
                            "0\n");
}