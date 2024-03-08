//
// Created by Farmat on 2024-03-03.
//

#include <vector>

#include "myGame.hpp"
#include "../NAGEN Engine/include/engine.hpp"

scene myGame::gameInitialization() {
    scene localScene = {};

    localScene.id = 1;
    localScene.tickPerSecond = 1000;
//    double Tick = 0;


    NAGENobject Object1;

    Object1.mass = 1; // Kilogram

    Object1.xCoordinate = 0;
    Object1.yCoordinate = 0;
    Object1.zCoordinate = 1000;

    Object1.phiAngle = 0;
    Object1.thetaAngle = 0;

    Object1.xSpeed = 0;
    Object1.ySpeed = 0;
    Object1.zSpeed = 0;

    Object1.xSize = 0.5;
    Object1.ySize = 0.5;
    Object1.zSize = 0.5;

    localScene.NagenObjectList.push_back(Object1);

    NAGENobject Object2;

    Object2.mass = 1; // Kilogram

    Object2.xCoordinate = 0;
    Object2.yCoordinate = 0;
    Object2.zCoordinate = 10000;

    Object2.phiAngle = 0;
    Object2.thetaAngle = 0;

    Object2.xSpeed = 0;
    Object2.ySpeed = 0;
    Object2.zSpeed = 0;

    Object2.xSize = 0.5;
    Object2.ySize = 0.5;
    Object2.zSize = 0.5;

    localScene.NagenObjectList.push_back(Object2);

    return localScene;
}

int myGame::gameLoop(scene & localScene) {
    std::cout << "\n====================================\n";
    std::cout << "ID of scene:        " << localScene.id                            << std::endl;
    std::cout << "Tick number:        " << localScene.tick                          << std::endl;
    std::cout << "Seconds from start: " << localScene.tick/localScene.tickPerSecond << std::endl;

    // Physic for solid objects
    for (int idOfObject = 0; idOfObject < localScene.NagenObjectList.size(); idOfObject++)
    {
        localScene.NagenObjectList.at(idOfObject).gravityTick(localScene.tick, localScene.tickPerSecond, idOfObject);
    }

    localScene.tick++;

    return 0;
}