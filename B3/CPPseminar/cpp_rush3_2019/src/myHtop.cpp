/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** myHtop.cpp
*/

#include <string>
#include <iostream>

int launch_ncurses();
int launch_sfml();

int printUsage()
{
    std::cout << "Usage :" << std::endl;
     std::cout << "To launch ncurses : ./myGKerllem" << std::endl;
     std::cout << "To launch sfml : ./myGKerllem -g" << std::endl;
     std::cout << "To get usage : ./myGKerllem -h/--help" << std::endl;
     std::cout << "To quit ncurses : q" << std::endl;
     return 0;
}

int myHtop(int ac, char **av)
{
    std::string grafical ("-g");
    std::string h ("-h");
    std::string help ("--help");

    if (ac == 1) {
        std::cout << "launchNcurses" << std::endl;
        return launch_ncurses();
    } else if (ac == 2 && grafical.compare(av[1]) == 0) {
        std::cout << "launchSfml" << std::endl;
        return launch_sfml();
    } else if (ac == 2 && (h.compare(av[1]) == 0 || help.compare(av[1]) == 0)) {
        return printUsage();
    } else {
        return printUsage();
    }
    return 0;
}
