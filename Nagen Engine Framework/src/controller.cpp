//
// Created by Farmat on 2024-05-10.
//

#include "controller.hpp"
#include "SFML/Graphics.hpp"


void controller::control(Player *player, scene *localScene) {
    // Control the camera with keyboard
    float cameraSpeed = 1.0f/localScene->tickPerSecond;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) or sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player->move(cameraSpeed, 0, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) or sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player->move(-cameraSpeed, 0, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) or sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        player->move(0, 0, cameraSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) or sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
        player->move(0, 0, -cameraSpeed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player->move(0, cameraSpeed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        player->move(0, -cameraSpeed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) player->angle += 0.05;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) player->angle -= 0.05;
}
