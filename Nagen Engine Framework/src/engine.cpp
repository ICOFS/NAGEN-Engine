//
//  main.cpp
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
    controller control;

    // Create a window for rendering
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    sf::RenderWindow window(sf::VideoMode(800, 600), myGame::nameofwindow, sf::Style::Default, settings);


    /*

    sf::Image icon;
    if (!icon.loadFromFile(myGame::pathtoicon)) {
        std::cout << "ERROR: ICON\n";
    }// else {
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    //}

     */

//    sf::View camera(sf::FloatRect(0, 0, 800, 600));

    Player player;

    player.x = 0;
    player.y = -10;
    player.z = 0;

    window.setFramerateLimit(localSceneEng.tickPerSecond);

    // MAIN LOOP
    while (window.isOpen()) {
        localSceneEng = myGame::gameLoop(localSceneEng);
        control.control(&player, &localSceneEng);
        render.renderScene(&localSceneEng, &window, &player);
    }

    return 0;
}
