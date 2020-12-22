/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D13_2019_PICTURE_HPP
#define CPP_D13_2019_PICTURE_HPP

#include <string>

class Picture
{
    public:
        Picture();
        Picture(const std::string &);
        ~Picture();
        bool getPictureFromFile(const std::string &file);

        std::string data;
};

#endif //CPP_D13_2019_PICTURE_HPP
