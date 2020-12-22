/*
** EPITECH PROJECT, 2019
** CPP POOL - RUSH3
** File description:
** launch_ncurses
*/

#include <ncurses.h>
#include "graphics/DisplayModules.hpp"
#include "graphics/NcursesMode.hpp"

int launch_ncurses()
{
    NcursesMode mode;

    initscr();
    curs_set(0);
    ModuleElements elements;
    mode.setWindow();
        while (1) {
            clear();
            if (LINES < 24 || COLS < 150) {
                mvprintw((LINES / 2), (COLS / 2) - (21 / 2), "window size too small");
            } else {
                mode.setWindow();
                displayModules(mode, elements);
            }
            doupdate();
            refresh();
        }
    endwin();
    return (0);
}