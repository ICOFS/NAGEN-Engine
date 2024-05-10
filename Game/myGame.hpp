//
// Created by Farmat on 2024-03-03.
//

#pragma once

#ifndef NAGEN_ENGINE_MYGAME_HPP
#define NAGEN_ENGINE_MYGAME_HPP

#include <engine.hpp>
#include <SFML/Graphics.hpp>

struct scene {
    int id;
    int tick;
    int tickPerSecond;
    std::vector<NAGENobject> NagenObjectList;
};

class myGame {
public:
    static scene gameInitialization();
    static scene gameLoop(scene & localScene, sf::RenderWindow &window, sf::View &camera);

    static std::string pathtoicon;
    static std::string nameofwindow;

};

#endif //NAGEN_ENGINE_MYGAME_HPP
