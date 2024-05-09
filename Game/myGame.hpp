//
// Created by Farmat on 2024-03-03.
//

#pragma once

#ifndef NAGEN_ENGINE_MYGAME_HPP
#define NAGEN_ENGINE_MYGAME_HPP

#include <vector>

#include "include/engine.hpp"

struct scene {
    int id;
    int tick;
    double tickPerSecond;
    std::vector<class NAGENobject> NagenObjectList;
};

class myGame {
public:
    static scene gameInitialization();
    static int gameLoop(scene & localScene);

};

#endif //NAGEN_ENGINE_MYGAME_HPP
