/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** TODO: add description
*/

#include "Picture.hpp"
#include <fstream>
#include <ostream>
#include <sstream>

Picture::Picture() : data("")
{

}

Picture::Picture(const std::string &filename) : data("")
{
    getPictureFromFile(filename);
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &filename)
{
    std::ifstream filestream(filename, std::ios::in);
    std::ostringstream contentFile;

    if (!filestream.is_open()) {
        this->data = std::string("ERROR");
        return false;
    }
    contentFile << filestream.rdbuf();
    this->data = contentFile.str();
    filestream.close();
    return true;
}

/* CANONICAL FORM */

Picture::Picture(Picture const &old) : data(old.data)
{
}

Picture& Picture::operator=(Picture const &picture)
{
    data = picture.data;
    return *this;
}