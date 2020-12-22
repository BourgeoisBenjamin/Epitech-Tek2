/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#include "../include/Object.hpp"
#include "../include/Teddy.hpp"
#include "../include/Box.hpp"
#include "../include/GiftPaper.hpp"
#include "../include/Santa.hpp"
#include "../include/PapaXmasElf.hpp"
#include "../include/PapaXmasTable.hpp"

void santaWelcome(void)
{
    std::cout << "********************" << std::endl;
    std::cout << "Welcome to the Santa's Workshop" << std::endl;
    std::cout << "********************" << std::endl << std::endl;
    std::cout << "[Santa] Elfs ! Come now!" << std::endl << std::endl;
}

PapaXmasElf& santaTest1(void)
{
    std::cout << "********************" << std::endl;
    std::cout << "Test 1 : Creation of elf" << std::endl;
    std::cout << "********************" << std::endl << std::endl;
    PapaXmasElf elf;
    std::cout << std::endl;
    return elf;
}

PapaXmasTable& santaTest2(void)
{
    std::cout << "********************" << std::endl;
    std::cout << "Test 2 : Creation of a table" << std::endl;
    std::cout << "********************" << std::endl << std::endl;
    PapaXmasTable table;
    return table;
}

Object** santaTest3(void)
{
    std::cout << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << "Test 3 : Now, create a Teddy with a box and a GiftPaper" <<
              std::endl;
    std::cout << "********************" << std::endl << std::endl;
    Object **object;
    object = new Object*[3];
    object[0] = new Teddy("cuddles");
    object[1] = new Box();
    object[2] = new GiftPaper();
    std::cout << std::endl;
    return object;
}

void santaTest3(Object**)


int main()
{
    santaWelcome();
    PapaXmasElf elf = santaTest1();
    PapaXmasTable table = santaTest2();
    Object **object = santaTest3();

    std::cout << "********************" << std::endl;
    std::cout << "Test 4 : Elf take the Teddy" << std::endl;
    std::cout << "********************" << std::endl << std::endl;
    object[0]->isTaken();
    std::cout << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << "Test 5 : Wrap a non-closed box" << std::endl;
    std::cout << "********************" << std::endl << std::endl;
    object[1]->wrapMeThat(object[0]);
    std::cout << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << "Test 6 : Put the toy in the box, close and wrap it" <<
    std::endl;
    std::cout << "********************" << std::endl << std::endl;
    std::cout << "[Elf] I have to open the box !" << std::endl;
    MyUnitTests(object);
    std::cout << "[Elf] The gift is wrap" << std::endl;
    std::cout << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << "Test 7 : Put 2 toy on the table" << std::endl;
    std::cout << "********************" << std::endl << std::endl;
    Toy *Teddy2 = new Teddy("KREOG");
    Toy *Teddy3 = new Teddy("I'M HERE");
    table.addToy(Teddy2);
    table.addToy(Teddy3);
    std::cout << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << "Test 8 : Consult the table" << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << std::endl;
    std::string *toyArray = table.look();
    std::cout << toyArray[0] << std::endl;
    std::cout << toyArray[1] << std::endl << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << "Christmas is over time now." << std::endl;
    std::cout << "********************" << std::endl;
    return 0;
}