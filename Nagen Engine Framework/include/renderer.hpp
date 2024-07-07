//
// Created by Farmat on 2024-05-10.
//

#ifndef NAGEN_ENGINE_RENDERER_HPP
#define NAGEN_ENGINE_RENDERER_HPP

#include "../../Game/myGame.hpp"

#include "player.hpp"

class renderer {
public:
    /// \brief Renders a 3D scene onto a 2D window using perspective projection.
    ///
    /// This function iterates through the objects in the scene, projects their
    /// vertices onto the screen based on the player's position and viewing angle,
    /// and draws the projected points and polygons.
    ///
    /// \param localScene A pointer to the scene object containing the objects to render.
    /// \param window A pointer to the SFML render window to draw the scene on.
    /// \param player A pointer to the player object, providing position and viewing angle.
    void renderScene(scene *localScene, sf::RenderWindow *window, Player *player);
    ~renderer();
};

#endif //NAGEN_ENGINE_RENDERER_HPP
