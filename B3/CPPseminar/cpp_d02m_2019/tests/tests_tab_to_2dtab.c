/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** TODO: add description
*/

#include "unittest.h"

void tab_to_2dtab(const int *tab, int length, int width, int ***res);

Test(tab_to_2dtab, test00, .init = redirect_all_std)
{
    int **tab_2d;
    const int tab[42] = {
    0, 1, 2, 3, 4, 5,
    6, 7, 8, 9, 10, 11,
    12, 13, 14, 15, 16, 17,
    18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 25,
    36, 37, 38, 39, 40, 41
    };
    tab_to_2dtab(tab, 7, 6, &tab_2d);
    printf ("tab2[%d][%d] = %d\n", 0, 0, tab_2d[0][0]);
    printf ("tab2[%d][%d] = %d\n", 6, 5, tab_2d[6][5]);
    printf ("tab2[%d][%d] = %d\n", 4, 4, tab_2d[4][4]);
    printf ("tab2[%d][%d] = %d\n", 0, 3, tab_2d[0][3]);
    printf ("tab2[%d][%d] = %d\n", 3, 0, tab_2d[3][0]);
    printf ("tab2[%d][%d] = %d\n", 4, 2, tab_2d[4][2]);
    fflush(stdout);
    cr_assert_stdout_eq_str("tab2[0][0] = 0\ntab2[6][5] = 41\n"
                            "tab2[4][4] = 28\ntab2[0][3] = 3\n"
                            "tab2[3][0] = 18\ntab2[4][2] = 26\n");
}