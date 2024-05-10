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
    localScene.tickPerSecond = 1000;

    NAGENobject Object1;
    Object1.xCoordinate = 0;
    Object1.yCoordinate = 300;
    Object1.zCoordinate = 100;
    Object1.xSpeed = 0;
    Object1.ySpeed = 0;
    Object1.zSpeed = 0;
    Object1.xSize = 1;
    Object1.ySize = 1;
    Object1.zSize = 1;

    localScene.NagenObjectList.push_back(Object1);

    return localScene;
}


int myGame::gameLoop(scene &localScene, sf::RenderWindow &window, sf::View &camera) {
    std::cout << "\n====================================\n";
    std::cout << "ID of scene:        " << localScene.id << std::endl;
    std::cout << "Tick number:        " << localScene.tick << std::endl;
    std::cout << "Seconds from start: " << localScene.tick / localScene.tickPerSecond << std::endl;

    // Physic for solid objects
    for (int idOfObject = 0; idOfObject < localScene.NagenObjectList.size(); idOfObject++)
    {
        localScene.NagenObjectList.at(idOfObject).gravityTick(localScene.tick, localScene.tickPerSecond, idOfObject);
    }

    sf::Event event = {};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    // Control the camera with keyboard
    float cameraSpeed = 0.5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        camera.move(-cameraSpeed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        camera.move(cameraSpeed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        camera.move(0, -cameraSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        camera.move(0, cameraSpeed);
    }

    // Zoom the camera with Q and E
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        camera.zoom(1.001f); // Zoom out
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        camera.zoom(0.999f); // Zoom in
    }

    // Render the scene
    window.clear(sf::Color::Black);
    window.setView(camera);

    // Draw all NAGENobjects as points
    for (auto &object : localScene.NagenObjectList) {
        sf::CircleShape shape(5);  // Radius of 5 for visibility
        shape.setFillColor(sf::Color::Red);

        // Set the position of the shape based on the object's coordinates
        shape.setPosition(object.xCoordinate, object.zCoordinate);

        // Draw the shape
        window.draw(shape);
    }

    window.display();

    localScene.tick++;

    return 0;
}