cmake_minimum_required (VERSION 3.21)
project( NAGEN-Engine CXX)

add_executable( NAGEN-Engine
        "Game/myGame.cpp"
        "Game/myGame.hpp"
)


add_subdirectory("Nagen Engine Framework")
target_link_libraries(NAGEN-Engine PUBLIC Nagen_Engine_Framework)


