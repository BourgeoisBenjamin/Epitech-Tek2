/*
** EPITECH PROJECT, 2020
** NanoTekSpice
** File description:
** TODO: add description
*/

#ifndef NANOTEKSPICE_COMPONENT_HPP
#define NANOTEKSPICE_COMPONENT_HPP

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class Component {
        public:
            Component();
            ~Component();
        private
            enum Tristate _state;

    };
}

#endif //NANOTEKSPICE_COMPONENT_HPP
