/*
** EPITECH PROJECT, 2020
** cpp_d02m
** File description:
** ex01
*/

#ifndef MEM_PTR_H
#define MEM_PTR_H

typedef struct str_op_s
{
    const char *str1;
    const char *str2;
    char *res;
} str_op_t;

void add_str(const char *str1, const char *str2, char **res);
void add_str_struct(str_op_t *str_op);

#endif /* MEM_PTR_H */
