//
// Created by Farmat on 2024-05-10.
//

#ifndef NAGEN_ENGINE_RENDERER_HPP
#define NAGEN_ENGINE_RENDERER_HPP

#include "../../Game/myGame.hpp"

#include "../include/player.hpp"

class renderer {
public:
    void renderScene(scene *localScene, sf::RenderWindow *window, Player *player);
    ~renderer();
};

#endif //NAGEN_ENGINE_RENDERER_HPP
