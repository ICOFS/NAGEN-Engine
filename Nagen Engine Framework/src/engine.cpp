//
//  main.cpp
//  Nagen Engine Framework
//
// Copyright 2023 Farmat team
//
// Licensed under the FOSL (the "LICENSE.md");
//
//  Created by Farmat on 2023-11-23.
//

#include "../../Game/myGame.hpp"
#include "renderer.hpp"
#include <SFML/Graphics.hpp>

int main() {
    // Initialize the game scene
    scene localSceneEng = myGame::gameInitialization();
    renderer render;

    // Create a window for rendering
    sf::RenderWindow window(sf::VideoMode(800, 600), myGame::nameofwindow);
    sf::View camera(sf::FloatRect(0.f, 0.f, 800.f, 600.f));

    // MAIN LOOP
    while (window.isOpen()) {
        localSceneEng = myGame::gameLoop(localSceneEng, window, camera);
        render.renderScene(&localSceneEng, &window, &camera);
    }

    return 0;
}
