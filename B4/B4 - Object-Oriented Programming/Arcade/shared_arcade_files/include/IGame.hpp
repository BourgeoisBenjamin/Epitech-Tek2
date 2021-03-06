/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "Utils.hpp"
#include <vector>
#include <map>
#include <functional>
#include <memory>

namespace arc {

    class IGame {
    public:
        virtual ~IGame() = default;

        virtual size_t getMapHeight() const = 0;
        virtual size_t getMapWidth() const = 0;
        virtual const std::string &getMusic() const = 0;
        virtual const std::string &getSound() const = 0;
        virtual const std::string &getScore() = 0;
        virtual const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &getControls() const = 0;

        virtual const std::vector<std::shared_ptr<Entity>> &getEntities() const = 0;

        virtual const std::vector<std::pair<std::string, std::string>> &getGameControls() const = 0;
        virtual const std::vector<std::pair<std::string, std::string>> &getGameStats() const = 0;

        virtual void restart() = 0;
        virtual void updateGame() = 0;

        virtual bool isGameOver() const = 0;

        virtual const std::string &getTitle() const = 0;
    };
}

#endif /* IGAME_HPP_ */
