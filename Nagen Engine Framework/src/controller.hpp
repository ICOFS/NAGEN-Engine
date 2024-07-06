//
// Created by Farmat on 2024-05-10.
//

#ifndef NAGEN_ENGINE_CONTROLLER_HPP
#define NAGEN_ENGINE_CONTROLLER_HPP

#include <SFML/Graphics.hpp>

#include <../include/player.hpp>

#include "../../Game/myGame.hpp"

class controller {
public:
    static void control(Player *player, scene *localScene);
};


#endif //NAGEN_ENGINE_CONTROLLER_HPP
