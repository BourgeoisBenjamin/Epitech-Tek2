/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** TODO: add description
*/
#ifndef CPP_D07M_2019_WARPSYSTEM_HPP
#define CPP_D07M_2019_WARPSYSTEM_HPP

namespace WarpSystem
{
    class QuantumReactor
    {
        private:
            bool _stability;

        public:
            QuantumReactor();
            ~QuantumReactor();
            bool isStable();
            void setStability(bool stability);
    };

    class Core
    {
        private:
            QuantumReactor *_coreReactor;

        public:
            Core(QuantumReactor *reactor);
            ~Core();
            QuantumReactor *checkReactor();
    };
}

#endif //CPP_D07M_2019_WARPSYSTEM_HPP
