/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(Paladin, init_Paladin, .init = redirect_all_std)
{
    Paladin test("Doruto", 12);
    cr_assert_stdout_eq_str("Doruto Created\nI'm Doruto "
                            "KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\nDoruto teleported\n"
                            "Doruto enters in the order\n"
                            "the light falls on Doruto\n");
}

Test(CloseAttack, Paladin_check_close_attack, .init = redirect_all_std)
{
    Paladin test("Doruto", 12);
    test.CloseAttack();
    cr_assert_stdout_eq_str("Doruto Created\n"
                            "I'm Doruto KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\n"
                            "Doruto teleported\n"
                            "Doruto enters in the order\n"
                            "the light falls on Doruto\n"
                            "Doruto strikes with his hammer\n");
}

Test(CloseAttack, Paladin_check_close_attack_fail, .init = redirect_all_std)
{
    Paladin test("Doruto", 12);
    test.CloseAttack();
    test.CloseAttack();
    test.CloseAttack();
    test.CloseAttack();
    cr_assert_stdout_eq_str("Doruto Created\n"
    "I'm Doruto KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\n"
    "Doruto teleported\n"
    "Doruto enters in the order\n"
    "the light falls on Doruto\n"
    "Doruto strikes with his hammer\n"
    "Doruto strikes with his hammer\n"
    "Doruto strikes with his hammer\n"
    "Doruto out of power\n");
}

Test(RangeAttack, Paladin_check_range_attack, .init = redirect_all_std)
{
    Paladin test("Doruto", 12);
    test.Range = Paladin::RANGE;
    test.RangeAttack();
    cr_assert_stdout_eq_str("Doruto Created\n"
    "I'm Doruto KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\n"
    "Doruto teleported\n"
    "Doruto enters in the order\n"
    "the light falls on Doruto\n"
    "Doruto launches a fire ball\n");
}

Test(RangeAttack, Paladin_check_range_attack_fail, .init = redirect_all_std)
{
    Paladin test("Doruto", 12);
    test.Range = Paladin::RANGE;
    test.RangeAttack();
    test.RangeAttack();
    test.RangeAttack();
    test.RangeAttack();
    cr_assert_stdout_eq_str("Doruto Created\n"
    "I'm Doruto KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\n"
    "Doruto teleported\n"
    "Doruto enters in the order\n"
    "the light falls on Doruto\n"
    "Doruto launches a fire ball\n"
    "Doruto launches a fire ball\n"
    "Doruto launches a fire ball\n"
    "Doruto launches a fire ball\n");
}

Test(Paladin, Paladin_check_range)
{
    Paladin test("Doruto", 12);
    cr_assert_eq(test.Range, Paladin::CLOSE);
}

Test(getLvl, Paladin_check_lvl)
{
    Paladin test("Doruto", 12);
    cr_assert_eq(test.getLvl(), 12);
}

Test(getName, Paladin_check_name)
{
    Paladin test("Doruto", 12);
    cr_assert_eq(test.getName(), "Doruto");
}

Test(getpower, Paladin_check_power)
{
    Paladin test("Doruto", 12);
    cr_assert_eq(test.getPower(), 100);
}

Test(getPv, Paladin_check_life)
{
    Paladin test("Doruto", 12);
    cr_assert_eq(test.getPv(), 100);
}

Test(Heal, Paladin_check_heal)
{
    Paladin test("Doruto", 12);
    test.Heal();
    cr_assert_eq(test.getPv(), 100);
}

Test(Heal, Paladin_check_heal_output, .init = redirect_all_std)
{
    Paladin test("Doruto", 12);
    test.Heal();
    cr_assert_stdout_eq_str("Doruto Created\n"
        "I'm Doruto KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\n"
        "Doruto teleported\n"
        "Doruto enters in the order\n"
        "the light falls on Doruto\n"
        "Doruto casts a little heal spell\n");
}

Test(RestorePower, Paladin_check_restore_power)
{
    Paladin test("Doruto", 12);
    test.RestorePower();
    cr_assert_eq(test.getPower(), 100);
}

Test(Heal, Paladin_check_restore_power_output, .init = redirect_all_std)
{
    Paladin test("Doruto", 12);
    cr_assert_stdout_eq_str("Doruto Created\n"
    "I'm Doruto KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\n"
    "Doruto teleported\n"
    "Doruto enters in the order\n"
    "the light falls on Doruto\n");
}

Test(TakeDamage, Paladin_check_take_damage)
{
    Paladin test("Doruto", 12);
    test.TakeDamage(24);
    cr_assert_eq(test.getPv(), 76);
}

Test(Heal, Paladin_check_take_damage_output, .init = redirect_all_std)
{
    Paladin test("Doruto", 12);
    test.TakeDamage(24);
    cr_assert_stdout_eq_str("Doruto Created\n"
        "I'm Doruto KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\n"
        "Doruto teleported\n"
        "Doruto enters in the order\n"
        "the light falls on Doruto\n"
        "Doruto takes 24 damage\n");
}

Test(Heal, Paladin_check_take_damage_dead)
{
    Paladin test("Doruto", 12);
    test.TakeDamage(110);
    cr_assert_eq(test.getPv(), 0);
}

Test(Heal, Paladin_check_take_damage_dead_output, .init = redirect_all_std)
{
    Paladin test("Doruto", 12);
    test.TakeDamage(100);
    cr_assert_stdout_eq_str("Doruto Created\n"
    "I'm Doruto KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\n"
    "Doruto teleported\n"
    "Doruto enters in the order\n"
    "the light falls on Doruto\n"
    "Doruto out of combat\n");
}

Test(Heal, Paladin_check_intercept_output, .init = redirect_all_std)
{
    Paladin test("Doruto", 12);
    test.Intercept();
    cr_assert_stdout_eq_str("Doruto Created\n"
    "I'm Doruto KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\n"
    "Doruto teleported\n"
    "Doruto enters in the order\n"
    "the light falls on Doruto\n"
    "Doruto intercepts\n");
}