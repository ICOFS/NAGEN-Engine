//
// Created by Farmat on 2024-03-03.
//

#include "myGame.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

std::string myGame::pathtoicon = "../Game/icon.png";
std::string myGame::nameofwindow = "Nagen Engine";

scene myGame::gameInitialization() {
    scene localScene;
    localScene.id = 1;
    localScene.tick = 0;
    localScene.tickPerSecond = 1000;

    NAGENobject Object1;
    Object1.xCoordinate = 300;
    Object1.yCoordinate = 0;
    Object1.zCoordinate = 1000;
    Object1.xSpeed = 0;
    Object1.ySpeed = 0;
    Object1.zSpeed = 0;
    Object1.xSize = 1;
    Object1.ySize = 1;
    Object1.zSize = 1;

    localScene.NagenObjectList.push_back(Object1);


    NAGENobject Object2;
    Object2.xCoordinate = 400;
    Object2.yCoordinate = 0;
    Object2.zCoordinate = 1000;
    Object2.xSpeed = 0;
    Object2.ySpeed = 0;
    Object2.zSpeed = 0;
    Object2.xSize = 1;
    Object2.ySize = 1;
    Object2.zSize = 1;

    localScene.NagenObjectList.push_back(Object2);

    return localScene;
}


scene myGame::gameLoop(scene &localScene, sf::RenderWindow &window, sf::View &camera) {
    std::cout << "\n====================================\n";
    std::cout << "ID of scene:        " << localScene.id << std::endl;
    std::cout << "Tick number:        " << localScene.tick << std::endl;
    std::cout << "Seconds from start: " << localScene.tick / localScene.tickPerSecond << std::endl;

    // Physic for solid objects
    for (int idOfObject = 0; idOfObject < localScene.NagenObjectList.size(); idOfObject++)
    {
        localScene.NagenObjectList.at(idOfObject).gravityTick(localScene.tick, localScene.tickPerSecond, idOfObject);
    }

    localScene.tick++;
    return localScene;
}