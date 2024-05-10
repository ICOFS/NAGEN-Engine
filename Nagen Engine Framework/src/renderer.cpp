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
        sf::Event event = {};

        sf::CircleShape shape(5);  // Radius of 5 for visibility
        shape.setFillColor(sf::Color::Red);

        // Set the position of the shape based on the object's coordinates
        shape.setPosition(
            window->getSize().y - object.xCoordinate,
            window->getSize().x - object.zCoordinate
        );


        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            } else if (event.type == sf::Event::Resized) {
                // resize my view
                camera->setSize({
                                        static_cast<float>(event.size.width),
                                        static_cast<float>(event.size.height)
                                });
                window->setView(*camera);
                // and align shape
                shape.setPosition(window->mapPixelToCoords(sf::Vector2i{window->getSize() / 2u}));
            }
        }

        // Draw the shape
        window->draw(shape);
    }

    window->display();
}