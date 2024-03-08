//
// Created by Farmat on 2024-03-03.
//

#ifndef NAGEN_ENGINE_MYGAME_HPP
#define NAGEN_ENGINE_MYGAME_HPP

struct scene {
    float i;
};

class myGame {
public:
    static scene gameInitialization();
    static int gameLoop(scene localScene);

};

#endif //NAGEN_ENGINE_MYGAME_HPP
