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
    int tick = 0;
    int tickPerSecond;
    std::vector<NAGENobject> NagenObjectList;
};

class myGame {
public:
    static scene gameInitialization();
    static scene gameLoop(scene & localScene);

    static std::string pathToIcon;
    static std::string nameOfWindow;

};

#endif //NAGEN_ENGINE_MYGAME_HPP
