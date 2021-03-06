/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** TODO: add description
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor() : _stability(true)
{
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

bool WarpSystem::QuantumReactor::isStable()
{
    return (_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}

WarpSystem::Core::Core(QuantumReactor *reactor) : _coreReactor(reactor)
{
}

WarpSystem::Core::~Core()
{
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return (_coreReactor);
}