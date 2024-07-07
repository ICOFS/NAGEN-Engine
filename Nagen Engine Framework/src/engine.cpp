//
//  main.cpp
//
//  Nagen Engine Framework
//
//  Copyright 2023 — 2024 ICOFS
//
//  Licensed under the FOSL (the "LICENSE.md");
//
//  Created by Farmat on 2023-11-23.
//

#include "../../Game/myGame.hpp"

#include "renderer.hpp"
#include "controller.hpp"

#include <SFML/Graphics.hpp>

int main() {
    // Initialize the game scene
    scene localSceneEng = myGame::gameInitialization();

    renderer render;

    // Create a window for rendering
    sf::ContextSettings settings;
    sf::RenderWindow window(sf::VideoMode(800, 600), myGame::nameOfWindow, sf::Style::Fullscreen, settings);
    window.setFramerateLimit(localSceneEng.tickPerSecond);


    // Create player
    Player player;

    player.pSpeed = (1.3f / float(localSceneEng.tickPerSecond));
    player.x = 0;
    player.y = -10;
    player.z = 0;

    // Main loop
    while (window.isOpen()) {
        localSceneEng = myGame::gameLoop(localSceneEng);
        controller::control(&player, &localSceneEng);
        render.renderScene(&localSceneEng, &window, &player);
    }

    return 0;
}
