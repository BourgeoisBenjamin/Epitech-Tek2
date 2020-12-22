/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

int cat_error(int argc)
{
    if (argc < 2) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (0);
    }
    return (1);
}

int my_cat(int argc, char **argv)
{
    std::ifstream file;

    if (!cat_error(argc)) return (0);

    for (int i = 1; i < argc; i++) {
        file.open(argv[i], std::ios::in);
        if (!file.is_open()) {
            std::cerr << "my_cat: " << argv[i] <<": No such file or "
                                                 "directory" << std::endl;
            continue;
        }
        std::cout << file.rdbuf();
        file.close();
    }
    return (0);
}