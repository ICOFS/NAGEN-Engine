//
// Created by Farmat on 2024-05-10.
//

#ifndef NAGEN_ENGINE_RENDERER_HPP
#define NAGEN_ENGINE_RENDERER_HPP

#include "../../Game/myGame.hpp"

class renderer {
public:
    void renderScene(scene *localScene, sf::RenderWindow *window, sf::View *camera);
    ~renderer();
};

#endif //NAGEN_ENGINE_RENDERER_HPP
