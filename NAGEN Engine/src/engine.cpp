//
//  main.cpp
//  NAGEN Engine
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

    myGameEng.gameLoop(localSceneEng);

    return 0;
}
