cmake_minimum_required (VERSION 3.21)
project( Nagen_Engine CXX)

add_executable( Nagen_Engine
        "Game/myGame.cpp"
        "Game/myGame.hpp"
)

include_directories(${SFML_INCLUDE_DIR})
add_definitions(${SFML_DEFINITIONS})


add_subdirectory("Nagen Engine Framework")
target_link_libraries(Nagen_Engine PUBLIC Nagen_Engine_Framework)
