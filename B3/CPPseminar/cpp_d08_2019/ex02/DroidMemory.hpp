/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** TODO: add description
*/
#ifndef CPP_D08_2019_DROIDMEMORY_HPP
#define CPP_D08_2019_DROIDMEMORY_HPP

#include <ostream>
#include <iostream>
#include <cstddef>

class DroidMemory
{
    private:
        size_t _fingerprint;
        size_t _exp;

    public:
        DroidMemory();
        ~DroidMemory();
        size_t getFingerprint() const;
        size_t getExp() const;
        void setFingerprint(size_t fingerprint);
        void setExp(size_t exp);

        DroidMemory& operator<<(const DroidMemory &droidMemory);
        DroidMemory& operator>>(DroidMemory &droidMemory) const;
        DroidMemory& operator+=(const DroidMemory &droidMemory);
        DroidMemory& operator+=(size_t exp);
        DroidMemory& operator+(const DroidMemory &droidMemory) const;
        DroidMemory& operator+(const size_t exp) const;

        /* EX02 */
        DroidMemory(const DroidMemory &);
        bool operator==(const DroidMemory &droidMemory) const;
        bool operator!=(const DroidMemory &droidMemory) const;
        bool operator<(const DroidMemory &droidMemory) const;
        bool operator>(const DroidMemory &droidMemory) const;
        bool operator<=(const DroidMemory &droidMemory) const;
        bool operator>=(const DroidMemory &droidMemory) const;

        bool operator<(const size_t exp) const;
        bool operator>(const size_t exp) const;
        bool operator<=(const size_t exp) const;
        bool operator>=(const size_t exp) const;
        DroidMemory& operator=(const DroidMemory &droidMemory);
};

std::ostream& operator<<(std::ostream &os, const DroidMemory &memory);

#endif //CPP_D08_2019_DROIDMEMORY_HPP
