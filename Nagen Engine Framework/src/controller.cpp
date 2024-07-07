//
// Created by Farmat on 2024-05-10.
//

#include "controller.hpp"
#include "SFML/Graphics.hpp"

void controller::control(Player *player, scene *localScene) {

    // Control the camera with keyboard
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player->move(0, player->pSpeed, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player->move(0, -player->pSpeed, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player->move(player->pSpeed, 0, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player->move(-player->pSpeed, 0, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) player->move(0, 0, player->pSpeed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) player->move(0, 0, -player->pSpeed);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) player->angle += 0.02;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) player->angle -= 0.02;
}