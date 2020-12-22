/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** TODO: add description
*/

#include <stdio.h>
#include "castmania.h"

void print_result(instruction_t *temp)
{
    if (((division_t*)temp->operation)->div_type == DECIMALE)
        printf("%f\n", (((decimale_op_t*)((division_t*)temp->operation)
            ->div_op)->res));
    else
        printf("%i\n", (((integer_op_t*)((division_t*)temp->operation)
            ->div_op)->res));
}

void exec_operation(instruction_type_t instruction_type, void *data)
{
    if (instruction_type == ADD_OPERATION) {
        exec_add((addition_t*)((instruction_t*)data)->operation);
        if (((instruction_t*)data)->output_type == VERBOSE)
            printf("%i\n", ((addition_t*)((instruction_t*)data)->operation)
            ->add_op.res);
    }

    if (instruction_type == DIV_OPERATION) {
        exec_div((division_t*)((instruction_t*)data)->operation);
        if (((instruction_t*)data)->output_type == VERBOSE) {
            print_result((instruction_t*)data);
        }
    }
}

void exec_instruction(instruction_type_t instruction_type, void *data)
{
    if (instruction_type == PRINT_INT) {
        printf("%i\n", (int)*((int*)data));
    } else if (instruction_type == PRINT_FLOAT) {
        printf("%f\n", (float)*((float*)data));
    } else {
        exec_operation(instruction_type, data);
    }
}