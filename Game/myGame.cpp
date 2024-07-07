//
// Created by Farmat on 2024-03-03.
//

#include "myGame.hpp"
#include <iostream>

std::string myGame::pathtoicon = "../Game/icon.png";
std::string myGame::nameofwindow = "Nagen Engine";

scene myGame::gameInitialization() {
    scene localScene;
    localScene.id = 1;
    localScene.tick = 0;
    localScene.tickPerSecond = 60;

    NAGENobject Coordinates;
    Coordinates.xCoordinate = 0;
    Coordinates.yCoordinate = 0;
    Coordinates.zCoordinate = 0;
    Coordinates.xSpeed = 0;
    Coordinates.ySpeed = 0;
    Coordinates.zSpeed = 0;
    Coordinates.xSize = 0;
    Coordinates.ySize = 0;
    Coordinates.zSize = 0;

    vertex v1_C = {0, 0, 0};
    vertex v1_Z = {0, 0, 1};
    vertex v1_Y = {0, 1, 0};
    vertex v1_X = {1, 0, 0};

    Coordinates.vertices.push_back(v1_C);
    Coordinates.vertices.push_back(v1_X);
    Coordinates.vertices.push_back(v1_Y);
    Coordinates.vertices.push_back(v1_Z);

    edge e2 = {v1_C, v1_X};
    edge e3 = {v1_C, v1_Y};
    edge e4 = {v1_C, v1_Z};

    Coordinates.edges.push_back(e2);
    Coordinates.edges.push_back(e3);
    Coordinates.edges.push_back(e4);

    polygon p1_4 = {v1_C, v1_X, v1_Y};
    polygon p2_4 = {v1_C, v1_X, v1_Z};
    polygon p3_4 = {v1_C, v1_Y, v1_Z};
    polygon p4_4 = {v1_X, v1_Y, v1_Z};

    Coordinates.polygons.push_back(p1_4);
    Coordinates.polygons.push_back(p2_4);
    Coordinates.polygons.push_back(p3_4);
    Coordinates.polygons.push_back(p4_4);

    localScene.NagenObjectList.push_back(Coordinates);

    return localScene;
}

scene myGame::gameLoop(scene &localScene) {
    std::cout << "\n====================================\n";
    std::cout << "ID of scene:        " << localScene.id << std::endl;
    std::cout << "Tick number:        " << localScene.tick << std::endl;
    std::cout << "Seconds from start: " << localScene.tick / localScene.tickPerSecond << std::endl;

    for (int idOfObject = 0; idOfObject < localScene.NagenObjectList.size(); idOfObject++) {
        localScene.NagenObjectList.at(idOfObject).update(localScene.tickPerSecond, idOfObject);
    }

    localScene.tick++;
    return localScene;
}