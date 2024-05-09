//
// Created by Farmat on 2024-03-03.
//

#include "myGame.hpp"
#include <SFML/Graphics.hpp>

std::string myGame::pathtoicon = "../Game/icon.png";
std::string myGame::nameofwindow = "Nagen Engine";

scene myGame::gameInitialization() {

    scene localScene = {};

    localScene.id = 1;
    localScene.tickPerSecond = 1000;
//    double Tick = 0;


    NAGENobject Object1;

    Object1.mass = 1;

    Object1.xCoordinate = 0;
    Object1.yCoordinate = 0;
    Object1.zCoordinate = 100;

    Object1.phiAngle = 0;
    Object1.thetaAngle = 0;

    Object1.xSpeed = 0;
    Object1.ySpeed = 0;
    Object1.zSpeed = 0;

    Object1.xSize = 1;
    Object1.ySize = 1;
    Object1.zSize = 1;

    poligon po1;
    po1.xCoordinate1 = 0;
    po1.yCoordinate1 = 0;
    po1.zCoordinate1 = 1;
    po1.xCoordinate2 = 1;
    po1.yCoordinate2 = 0;
    po1.zCoordinate2 = 0;
    po1.xCoordinate3 = 0;
    po1.yCoordinate3 = 0;
    po1.zCoordinate3 = 1;

    Object1.poligons.push_back(po1);

    localScene.NagenObjectList.push_back(Object1);

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
