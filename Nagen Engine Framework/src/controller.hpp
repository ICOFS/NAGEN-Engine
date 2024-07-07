//
// Created by Farmat on 2024-05-10.
//

#ifndef NAGEN_ENGINE_CONTROLLER_HPP
#define NAGEN_ENGINE_CONTROLLER_HPP

#include <SFML/Graphics.hpp>

#include <../include/player.hpp>

#include "../../Game/myGame.hpp"

class controller {
public:
    /// \brief Controls the player's movement and viewing angle based on keyboard input.
    ///
    /// This function checks for specific keyboard keys being pressed and updates
    /// the player's position and orientation within the game scene accordingly.
    ///
    /// \param player A pointer to the player object, allowing modification of its position and angle.
    /// \param localScene  A pointer to the scene object (currently unused, but could be used for collision detection in the future).
    static void control(Player *player, scene *localScene);
};


#endif //NAGEN_ENGINE_CONTROLLER_HPP
