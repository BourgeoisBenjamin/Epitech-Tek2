/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** TODO: add description
*/

#include "ToyStory.hpp"
#include <ostream>
#include <iostream>
#include <fstream>

bool error(Toy::Error const &detectError)
{
    std::cout << detectError.where() << ": " << detectError.what() << std::endl;
    return false;
}

bool ToyStory::tellMeAStory(const std::string &filename, Toy &toy1, bool
(Toy::*func1)(const std::string &sentence), Toy &toy2, bool (Toy::*func2)
(const std::string &sentence))
{
    std::ifstream filestream(filename);
    std::string line;
    int rotate = 1;

    if (!filestream.is_open()) {
        std::cout << "Bad Story" << std::endl;
        return false;
    }
    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;

    while (std::getline(filestream, line)) {
        if (line.find("picture:") != std::string::npos) {
            if (rotate % 2) {
                if (!toy1.setAscii(line.substr(8))) {
                    filestream.close();
                    return (error(toy1.getLastError()));
                }
                std::cout << toy1.getAscii() << std::endl;
            } else {
                if (!toy2.setAscii(line.substr(8))) {
                    filestream.close();
                    return (error(toy2.getLastError()));
                }
                std::cout << toy2.getAscii() << std::endl;
            }
        } else {
            if (rotate % 2) {
                if (!(toy1.*func1)(line)) {
                    filestream.close();
                    return (error(toy1.getLastError()));
                }
            } else {
                if (!(toy2.*func2)(line)) {
                    filestream.close();
                    return (error(toy2.getLastError()));
                }
            }
        }
        rotate++;
    }
    filestream.close();
    return true;
}