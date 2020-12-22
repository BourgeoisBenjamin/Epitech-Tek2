/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.h"

Test(memmove, test00, .init=redirect_all_std)
{
    int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };

    for (int i = 0; i < 10; i++) {
        printf("%d ", data[i]);
    }

    cr_assert_eq(data[0], 20);
    cr_assert_eq(data[1], 30);
    cr_assert_eq(data[2], 40);
    cr_assert_eq(data[3], 50);
    cr_assert_eq(data[4], 60);
    cr_assert_eq(data[5], 70);
    cr_assert_eq(data[6], 80);
    cr_assert_eq(data[7], 90);
    cr_assert_eq(data[8], 100);
    cr_assert_eq(data[9], 0);

    void *source = (void *)data;
    void *destination = (void *)(data + 1);
    size_t size = 10 * sizeof(int);
    memmove(destination, source, size);

    data[0] = 10;

    cr_assert_eq(data[0], 10);
    cr_assert_eq(data[1], 20);
    cr_assert_eq(data[2], 30);
    cr_assert_eq(data[3], 40);
    cr_assert_eq(data[4], 50);
    cr_assert_eq(data[5], 60);
    cr_assert_eq(data[6], 70);
    cr_assert_eq(data[7], 80);
    cr_assert_eq(data[8], 90);
    cr_assert_eq(data[9], 100);

}

Test(memmove, test01, .init=redirect_all_std)
{
    int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };

    for (int i = 0; i < 10; i++) {
    printf("%d ", data[i]);
    }

    cr_assert_eq(data[0], 20);
    cr_assert_eq(data[1], 30);
    cr_assert_eq(data[2], 40);
    cr_assert_eq(data[3], 50);
    cr_assert_eq(data[4], 60);
    cr_assert_eq(data[5], 70);
    cr_assert_eq(data[6], 80);
    cr_assert_eq(data[7], 90);
    cr_assert_eq(data[8], 100);
    cr_assert_eq(data[9], 0);

    void *source = (void *)data;
    void *destination = (void *)(data);
    size_t size = 10 * sizeof(int);
    memmove(destination, source, size);

    data[0] = 10;

    cr_assert_eq(data[0], 10);
    cr_assert_eq(data[1], 30);
    cr_assert_eq(data[2], 40);
    cr_assert_eq(data[3], 50);
    cr_assert_eq(data[4], 60);
    cr_assert_eq(data[5], 70);
    cr_assert_eq(data[6], 80);
    cr_assert_eq(data[7], 90);
    cr_assert_eq(data[8], 100);
    cr_assert_eq(data[9], 0);

}