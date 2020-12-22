/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: display and inits elements
*/

#include "./OSModule.hpp"
#include "./RAMModule.hpp"
#include "./UserModule.hpp"
#include "./CPUModule.hpp"
#include "./DateModule.hpp"
#include "./NetworkModule.hpp"

class ModuleElements {
    UserModule _userM;
    RAMModule _ramM;
    OSModule _osM;
    DateModule _dateM;
    CPUModule _cpuM;
    public :
        ModuleElements();
        ~ModuleElements();
        const UserModule &getuserM() const;
        const RAMModule &getramM() const;
        const OSModule &getosM() const;
        const DateModule &getdateM() const;
        const CPUModule &getcpuM() const;
        bool refresh();
};