cmake_minimum_required (VERSION 3.21)
project( "Nagen_Engine_Framework" CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.6.1 COMPONENTS graphics window audio REQUIRED)
find_package(glm REQUIRED)

add_library( Nagen_Engine_Framework STATIC
        "src/engine.cpp"
        "include/engine.hpp"

        "src/NAGENobject.cpp"
        "include/NAGENobject.hpp"

        "include/globalConsts.h"

        "include/mesh.hpp"

        "src/renderer.cpp"
        "include/renderer.hpp"

        "src/controller.cpp"
        "src/controller.hpp"
        src/player.cpp
        include/player.hpp
        src/mesh.cpp
        src/mesh.cpp
)

target_include_directories( Nagen_Engine_Framework PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Nagen_Engine_Framework PUBLIC
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
        glm::glm
)
