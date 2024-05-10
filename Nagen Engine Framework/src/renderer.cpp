//
// Created by Farmat on 2024-05-10.
//

#include "renderer.hpp"
#include <SFML/Graphics.hpp>

void renderer::renderScene(scene *localScene, sf::RenderWindow *window, sf::View *camera) {
    window->clear(sf::Color::Black);
    window->setView(*camera);

    // Iterate over each NAGENobject in the NagenObjectList
    for (auto &object : localScene->NagenObjectList) {
        sf::Event event = {};

        // Iterate over each vertex in the vertexes vector of the current NAGENobject
        for (auto &vertex : object.vertexes) {
            sf::CircleShape shape(1);  // Radius of 1 for visibility
            shape.setFillColor(sf::Color::Red);

            // Set the position of the shape based on the vertex coordinates
            shape.setPosition(
                    window->getSize().y - (object.xCoordinate + vertex.xCoordinate),
                    window->getSize().x - (object.zCoordinate + vertex.zCoordinate)

//                    window->getSize().y - object.xCoordinate,
//                    window->getSize().x - object.zCoordinate
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
    }
    window->display();
}
