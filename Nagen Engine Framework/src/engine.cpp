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

int main() {
    myGame myGameEng;

    scene localSceneEng = myGameEng.gameInitialization();

    while (localSceneEng.tick <= 5 * localSceneEng.tickPerSecond) {
        myGameEng.gameLoop(localSceneEng);
    }
    return 0;
}
