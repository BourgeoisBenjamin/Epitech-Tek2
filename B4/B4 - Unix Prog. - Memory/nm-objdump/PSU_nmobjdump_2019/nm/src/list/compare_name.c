/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../../include/nm.h"
#include <ctype.h>

int compare_name(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    while (i < len1 && j < len2) {
        while (i < len1 && (!isalpha(str1[i]) && !isdigit(str1[i])))
            i++;
        while (j < len2 && (!isalpha(str2[j]) && !isdigit(str2[j])))
            j++;
        if (tolower(str1[i]) != tolower(str2[j]))
            return (tolower(str1[i]) - tolower(str2[j]));
        else {
            i++;
            j++;
        }
    }
    if (i == len1 && j == len2)
        return (len2 - len1);
    return (tolower(str1[i]) - tolower(str2[j]));
}