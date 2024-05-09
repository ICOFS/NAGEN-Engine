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
#include <SFML/Graphics.hpp>

void init(std::string PATH, std::string NAME);

int main() {
    myGame myGameEng;

    scene localSceneEng = myGameEng.gameInitialization();

    while (localSceneEng.tick <= 5 * localSceneEng.tickPerSecond) {
        myGameEng.gameLoop(localSceneEng);
    }

    init(myGameEng.pathtoicon, myGameEng.nameofwindow);
    return 0;
}




void init(std::string PATH, std::string NAME) {
    sf::RenderWindow window(sf::VideoMode(800, 600), NAME);

    // Load the icon
    sf::Image icon;
    if (!icon.loadFromFile(PATH)) {
        std::cerr << "Could not load icon" << std::endl;
        return;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }
}








