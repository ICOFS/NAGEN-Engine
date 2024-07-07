#include "renderer.hpp"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

void renderer::renderScene(scene *localScene, sf::RenderWindow *window, Player *player) {
    window->clear(sf::Color::Black);

    sf::View camera(window->getDefaultView());
    std::vector<sf::Vector2f> projectedPoints;

    sf::Event event{};
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        } else if (event.type == sf::Event::Resized) {
            camera.setSize(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
            camera.setCenter(static_cast<float>(event.size.width) / 2, static_cast<float>(event.size.height) / 2);
            window->setView(camera);
        }
    }

    for (auto &object : localScene->NagenObjectList) {
        projectedPoints.clear();

        for (auto &vertex : object.vertices) {
            float x = object.xCoordinate + vertex.xCoordinate - player->x;
            float y = object.yCoordinate + vertex.yCoordinate - player->y;
            float z = object.zCoordinate + vertex.zCoordinate - player->z;

            float rx = x * std::cos(player->angle) + y * std::sin(player->angle);
            float ry = -x * std::sin(player->angle) + y * std::cos(player->angle);

            if (ry > 0) {
                float scale = 600 / ry;
                int sx = static_cast<int>(-rx * scale) + window->getSize().x / 2;
                int sy = static_cast<int>(-z * scale) + window->getSize().y / 2;
                projectedPoints.emplace_back(sx, sy);
            } else {
                projectedPoints.emplace_back(-1.0f, -1.0f);
            }
        }

        for (const auto &edge : object.edges) {
            float x1 = object.xCoordinate + edge.v1.xCoordinate - player->x;
            float y1 = object.yCoordinate + edge.v1.yCoordinate - player->y;
            float z1 = object.zCoordinate + edge.v1.zCoordinate - player->z;

            float rx1 = x1 * std::cos(player->angle) + y1 * std::sin(player->angle);
            float ry1 = -x1 * std::sin(player->angle) + y1 * std::cos(player->angle);

            sf::Vector2f projectedPoint1(-1.0f, -1.0f);
            if (ry1 > 0) {
                float scale1 = 600 / ry1;
                int sx1 = static_cast<int>(-rx1 * scale1) + window->getSize().x / 2;
                int sy1 = static_cast<int>(-z1 * scale1) + window->getSize().y / 2;
                projectedPoint1 = sf::Vector2f(sx1, sy1);
            }

            float x2 = object.xCoordinate + edge.v2.xCoordinate - player->x;
            float y2 = object.yCoordinate + edge.v2.yCoordinate - player->y;
            float z2 = object.zCoordinate + edge.v2.zCoordinate - player->z;

            float rx2 = x2 * std::cos(player->angle) + y2 * std::sin(player->angle);
            float ry2 = -x2 * std::sin(player->angle) + y2 * std::cos(player->angle);

            sf::Vector2f projectedPoint2(-1.0f, -1.0f);
            if (ry2 > 0) {
                float scale2 = 600 / ry2;
                int sx2 = static_cast<int>(-rx2 * scale2) + window->getSize().x / 2;
                int sy2 = static_cast<int>(-z2 * scale2) + window->getSize().y / 2;
                projectedPoint2 = sf::Vector2f(sx2, sy2);
            }

            /*
            if (projectedPoint1 != sf::Vector2f(-1.0f, -1.0f) && projectedPoint2 != sf::Vector2f(-1.0f, -1.0f)) {
                sf::Vertex line[] = {
                        sf::Vertex(projectedPoint1, sf::Color::Green),
                        sf::Vertex(projectedPoint2, sf::Color::Green)
                };
                window->draw(line, 2, sf::Lines);
            }
            */
        }

        for (const auto &polygon : object.polygons) {
            std::vector<sf::Vector2f> points;

            auto project = [&](const vertex& vert) -> sf::Vector2f {
                float x = object.xCoordinate + vert.xCoordinate - player->x;
                float y = object.yCoordinate + vert.yCoordinate - player->y;
                float z = object.zCoordinate + vert.zCoordinate - player->z;

                float rx = x * std::cos(player->angle) + y * std::sin(player->angle);
                float ry = -x * std::sin(player->angle) + y * std::cos(player->angle);

                if (ry > 0) {
                    float scale = 600 / ry;
                    int sx = static_cast<int>(-rx * scale) + window->getSize().x / 2;
                    int sy = static_cast<int>(-z * scale) + window->getSize().y / 2;
                    return sf::Vector2f(sx, sy);
                } else {
                    return sf::Vector2f(-1.0f, -1.0f);
                }
            };

            points.push_back(project(polygon.first));
            points.push_back(project(polygon.second));
            points.push_back(project(polygon.third));

            if (std::all_of(points.cbegin(), points.cend(), [](const sf::Vector2f& p) { return p != sf::Vector2f(-1.0f, -1.0f); })) {
                sf::ConvexShape shape(3);
                for (size_t i = 0; i < points.size(); ++i) {
                    shape.setPoint(i, points[i]);
                }
                shape.setFillColor(sf::Color(255, 0, 255, 80));
                shape.setOutlineColor(sf::Color::Magenta);
                shape.setOutlineThickness(1.0f);
                window->draw(shape);
            }
        }

        for (const auto &projectedPoint : projectedPoints) {
            if (projectedPoint != sf::Vector2f(-1.0f, -1.0f)) {
                sf::CircleShape shape(3);
                shape.setPosition(projectedPoint.x - shape.getRadius(), projectedPoint.y - shape.getRadius());
                shape.setFillColor(sf::Color::Red);
                window->draw(shape);
            }
        }
    }

    window->display();
}

renderer::~renderer() = default;
