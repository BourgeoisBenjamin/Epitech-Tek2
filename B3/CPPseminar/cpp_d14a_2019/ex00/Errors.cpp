/*
** EPITECH PROJECT, 2020
** cpp_d14a_2019
** File description:
** TODO: add description
*/

#include "Errors.hpp"

NasaError::NasaError(const std::string &message, const std::string
&component) throw() : _message(message), _component(component)
{
}

NasaError::~NasaError() throw()
{
}

const std::string & NasaError::getComponent() const throw()
{
    return _component;
}

const char* NasaError::what() const throw()
{
    return _message.c_str();
}

MissionCriticalError::MissionCriticalError(const std::string &message,
                                           const std::string &component) :
                                           NasaError(message, component)
{
}

MissionCriticalError::~MissionCriticalError()
{
}

LifeCriticalError::LifeCriticalError(const std::string &message,
                                     const std::string &component) :
                                     NasaError(message, component)
{
}

LifeCriticalError::~LifeCriticalError()
{
}

UserError::UserError(const std::string &message, const std::string
&component) : NasaError(message, component)
{
}

UserError::~UserError()
{
}

CommunicationError::CommunicationError(const std::string &message) :
NasaError(message, "CommunicationDevice")
{
}

CommunicationError::~CommunicationError()
{
}