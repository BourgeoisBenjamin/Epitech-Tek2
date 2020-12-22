/*
** EPITECH PROJECT, 2019
** UNIT TEST
** File description:
** header UNIT TEST
*/

#ifndef UNITTEST_H
#define UNITTEST_H

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/theories.h>
#include <iostream>

void redirect_all_std(void);
int cat_error(int argc);
int my_cat(int argc, char **argv);
double convert_celsius(double degree);
double convert_fahrenheit(double degree);
void print_conversion(double convert_degree, std::string mode);
int sort_convert(std::string mode, double degree);
int my_convert_temp(void);

#endif
