//
// Created by Farmat on 2024-05-10.
//

#include "renderer.hpp"
#include <SFML/Graphics.hpp>

void renderer::renderScene(scene *localScene, sf::RenderWindow *window, sf::View *camera) {
    window->clear(sf::Color::Black);
    window->setView(*camera);

    // Draw all NAGENobjects as points
    for (auto &object : localScene->NagenObjectList) {
        sf::CircleShape shape(5);  // Radius of 5 for visibility
        shape.setFillColor(sf::Color::Red);

        // Set the position of the shape based on the object's coordinates
        shape.setPosition(object.xCoordinate, object.zCoordinate);

        // Draw the shape
        window->draw(shape);
    }

    window->display();
}