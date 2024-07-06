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
    localScene.tickPerSecond = 60;

//    NAGENobject Object1;
//    Object1.xCoordinate = 300;
//    Object1.yCoordinate = 0;
//    Object1.zCoordinate = 200;
//    Object1.phiAngle = 0;
//    Object1.thetaAngle = 0;
//    Object1.xSpeed = 0;
//    Object1.ySpeed = 0;
//    Object1.zSpeed = 100;
//    Object1.xSize = 1;
//    Object1.ySize = 1;
//    Object1.zSize = 1;
//
//    Object1.temperature = 1;
//
//    Object1.mass = 1;
//
//    Object1.coefOfRestitution = 0.1;
//
//
//    vertex v1 = {};
//    v1.xCoordinate = 2;
//    v1.yCoordinate = 2;
//    v1.zCoordinate = 2;
//
//    vertex v2 = {};
//    v1.xCoordinate = -2;
//    v1.yCoordinate = -2;
//    v1.zCoordinate = -2;
//
//
//    Object1.vertexes.push_back(v1);
//    Object1.vertexes.push_back(v2);
//
//    localScene.NagenObjectList.push_back(Object1);





    NAGENobject Coordinates;
    Coordinates.xCoordinate = 0;
    Coordinates.yCoordinate = 0;
    Coordinates.zCoordinate = 0;
    Coordinates.xSpeed = 0;
    Coordinates.ySpeed = 0;
    Coordinates.zSpeed = 1;
    Coordinates.xSize = 1;
    Coordinates.ySize = 1;
    Coordinates.zSize = 1;

    vertex v1_C = {};
    v1_C.xCoordinate = 0;
    v1_C.yCoordinate = 0;
    v1_C.zCoordinate = 0;

    vertex v1_Z = {};
    v1_Z.xCoordinate = 0;
    v1_Z.yCoordinate = 0;
    v1_Z.zCoordinate = 1;

    vertex v1_Y = {};
    v1_Y.xCoordinate = 0;
    v1_Y.yCoordinate = 1;
    v1_Y.zCoordinate = 0;

    vertex v1_X = {};
    v1_X.xCoordinate = 1;
    v1_X.yCoordinate = 0;
    v1_X.zCoordinate = 0;

    Coordinates.vertexes.push_back(v1_C);
    Coordinates.vertexes.push_back(v1_X);
    Coordinates.vertexes.push_back(v1_Y);
    Coordinates.vertexes.push_back(v1_Z);

    localScene.NagenObjectList.push_back(Coordinates);

    return localScene;
}


scene myGame::gameLoop(scene &localScene, sf::RenderWindow &window) {
    std::cout << "\n====================================\n";
    std::cout << "ID of scene:        " << localScene.id << std::endl;
    std::cout << "Tick number:        " << localScene.tick << std::endl;
    std::cout << "Seconds from start: " << localScene.tick / localScene.tickPerSecond << std::endl;

    // Physic for solid objects
    for (int idOfObject = 0; idOfObject < localScene.NagenObjectList.size(); idOfObject++) {
        localScene.NagenObjectList.at(idOfObject).update(localScene.tickPerSecond, idOfObject);
    }

    localScene.tick++;
    return localScene;
}