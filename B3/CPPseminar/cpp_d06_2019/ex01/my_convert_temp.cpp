/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>

double convert_celsius(double degree)
{
    return ((9.0 / 5.0 * degree) + 32.0);
}

double convert_fahrenheit(double degree)
{
    return (5.0 / 9.0 * (degree - 32.0));
}

void print_conversion(double convert_degree, std::string mode)
{
    std::cout.width(16);
    std::cout << std ::right << std::fixed << std::setprecision(3) << convert_degree;
    std::cout.width(16);
    std::cout << mode << std::endl;
}

int sort_convert(std::string mode, double degree)
{
    double convert_degree = -1;
    std::string convert_mode;

    if (strcmp(mode.c_str(), "Celsius") == 0) {
        convert_degree = convert_celsius(degree);
        convert_mode = "Fahrenheit";
    }
    if (strcmp(mode.c_str(), "Fahrenheit") == 0) {
        convert_degree = convert_fahrenheit(degree);
        convert_mode = "Celsius";
    }
    print_conversion(convert_degree, convert_mode);
    return (0);
}

int my_convert_temp(void)
{
    std::string mode;
    double degree = -1;

    std::cin >> degree >> mode;
    return (sort_convert(mode, degree));
}