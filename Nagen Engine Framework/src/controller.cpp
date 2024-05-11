//
// Created by Farmat on 2024-05-10.
//

#include "controller.hpp"
#include "SFML/Graphics.hpp"

void controller::control(sf::View *camera) {
    // Control the camera with keyboard
    float cameraSpeed = 0.5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    camera->move(-cameraSpeed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    camera->move(cameraSpeed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    camera->move(0, -cameraSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    camera->move(0, cameraSpeed);
    }

    // Zoom the camera with Q and E
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
    camera->zoom(1.001f); // Zoom out
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
    camera->zoom(0.999f); // Zoom in
    }
}
