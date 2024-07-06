//
// Created by Farmat on 2024-05-10.
//

#include "renderer.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

// Function to render the scene
void renderer::renderScene(scene *localScene, sf::RenderWindow *window, Player *player) {
    // Clear the window with a black color
    window->clear(sf::Color::Black);

    // Create a camera view that matches the window size
    sf::View camera(window->getDefaultView());

    // Vector to store the projected points
    std::vector<sf::Vector2f> projectedPoints;

    // Handle window events
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            // Close the window if the close event is triggered
            window->close();
        } else if (event.type == sf::Event::Resized) {
            // Adjust the camera view if the window is resized
            camera.setSize(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
            camera.setCenter(static_cast<float>(event.size.width) / 2, static_cast<float>(event.size.height) / 2);
            window->setView(camera);
        }
    }

    // Iterate over each object in the scene
    for (auto &object : localScene->NagenObjectList) {
        // Iterate over each vertex of the current object
        for (auto &vertex : object.vertexes) {
            // Calculate the relative position of the vertex from the player
            float x = object.xCoordinate + vertex.xCoordinate - player->x;
            float y = object.yCoordinate + vertex.yCoordinate - player->y;
            float z = object.zCoordinate + vertex.zCoordinate - player->z;

            // Apply rotation based on the player's angle
            float rx = x * std::cos(player->angle) + y * std::sin(player->angle);
            float ry = -x * std::sin(player->angle) + y * std::cos(player->angle);

            // Perform projection only if the point is in front of the camera (positive ry)
            if (ry > 0) {
                float scale = 600 / ry; // Adjust the scale factor for perspective
                int sx = static_cast<int>(-rx * scale) + window->getSize().x / 2; // Invert the x-axis
                int sy = static_cast<int>(-z * scale) + window->getSize().y / 2; // Invert the z-axis

                // Store the projected point
                projectedPoints.emplace_back(sx, sy);

                // Draw the vertex as a small circle
                sf::CircleShape shape(3); // Radius of 3 for better visibility
                shape.setPosition(sx - shape.getRadius(), sy - shape.getRadius()); // Center the circle at the projected point
                shape.setFillColor(sf::Color::Red); // Set the color to red for the vertex
                window->draw(shape);
            } else {
                // Point is behind the camera
                projectedPoints.emplace_back(-1, -1);
            }
        }
    }

    // Display the rendered frame
    window->display();
}

// Destructor for the renderer class
renderer::~renderer() = default;
