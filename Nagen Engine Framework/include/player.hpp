//
// Created by Farmat on 2024-07-06.
//

#ifndef NAGEN_ENGINE_PLAYER_HPP
#define NAGEN_ENGINE_PLAYER_HPP

#include <iostream>
#include <cmath>

class Player {
public:
    float x = 0, y = 0, z = 0, angle = 0;

    float pSpeed = 0;

    void move(float dx, float dy, float dz) {
        x += dx * std::cos(angle) - dy * std::sin(angle);
        y += dx * std::sin(angle) + dy * std::cos(angle);
        z += dz;
    }
};


#endif //NAGEN_ENGINE_PLAYER_HPP
