/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(Character, pv_character_1, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.TakeDamage(50);
    cr_assert_eq(test.getPv(), 50);
}

Test(Character, pv_character_2, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.TakeDamage(100);
    cr_assert_eq(test.getPv(), 0);
}

Test(Character, pv_character_3, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.TakeDamage(-100);
    cr_assert_eq(test.getPv(), 100);
}

Test(Character, pv_character_4, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.TakeDamage(200);
    cr_assert_eq(test.getPv(), 0);
}

Test(Character, pv_character_5, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.TakeDamage(90);
    test.Heal();
    cr_assert_eq(test.getPv(), 60);
}

Test(Character, pv_character_7, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.TakeDamage(200);
    test.Heal();
    cr_assert_eq(test.getPv(), 50);
}

Test(Character, pv_character_8, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.TakeDamage(10);
    test.Heal();
    cr_assert_eq(test.getPv(), 100);
}

Test(Character, Energy_character_1, .init=redirect_all_std)
{
    Character test("Test", 0);
    cr_assert_eq(test.getPower(), 100);
}

Test(Character, Energy_character_2, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.RangeAttack();
    cr_assert_eq(test.getPower(), 90);
}

Test(Character, Energy_character_3, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.CloseAttack();
    cr_assert_eq(test.getPower(), 90);
}

Test(Character, Energy_character_4, .init=redirect_all_std)
{
    Character test("Test", 0);
    for (int i = 0; i <= 10; ++i)
        test.CloseAttack();
    cr_assert_eq(test.getPower(), 0);
}

Test(Character, Energy_character_5, .init=redirect_all_std)
{
    Character test("Test", 0);
    for (int i = 0; i <= 30; ++i)
        test.CloseAttack();
    cr_assert_eq(test.getPower(), 0);
}

Test(Character, Energy_character_6, .init=redirect_all_std)
{
    Character test("Test", 0);
    for (int i = 0; i <= 30; ++i)
        test.CloseAttack();
    test.RestorePower();
    cr_assert_eq(test.getPower(), 100);
}

Test(Character, Energy_character_7, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.CloseAttack();
    test.RestorePower();
    cr_assert_eq(test.getPower(), 100);
}

Test(Character, Range_Attack_1, .init=redirect_all_std)
{
    Character test("Test", 0);
    for (int i = 0; i <= 30; ++i)
    test.RangeAttack();
    cr_assert_eq(test.RangeAttack(), 0);
}

Test(Character, Range_Attack_2, .init=redirect_all_std)
{
    Character test("Test", 0);
    cr_assert_eq(test.RangeAttack(), 10);
}

Test(Character, Close_Attack_1, .init=redirect_all_std)
{
    Character test("Test", 0);
    for (int i = 0; i <= 30; ++i)
    test.CloseAttack();
    cr_assert_eq(test.CloseAttack(), 0);
}

Test(Character, Close_Attack_2, .init=redirect_all_std)
{
    Character test("Test", 0);
    cr_assert_eq(test.CloseAttack(), 15);
}

Test(Character, Get_Name_1, .init=redirect_all_std)
{
    Character test("Test", 0);
    cr_assert_eq(test.getName(), "Test");
}

Test(Character, Get_Name_2, .init=redirect_all_std)
{
    Character test("tesT", 0);
    cr_assert_eq(test.getName(), "tesT");
}

Test(Character, Get_Name_3, .init=redirect_all_std)
{
    Character test("", 0);
    cr_assert_eq(test.getName(), "");
}

Test(Character, Get_Level_1, .init=redirect_all_std)
{
    Character test("Test", 0);
    cr_assert_eq(test.getLvl(), 0);
}

Test(Character, Get_Level_2, .init=redirect_all_std)
{
    Character test("Test", -74);
    cr_assert_eq(test.getLvl(), -74);
}