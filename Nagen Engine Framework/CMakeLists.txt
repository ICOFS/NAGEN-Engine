cmake_minimum_required (VERSION 3.21)
project( "Nagen_Engine_Framework" CXX)

set(CMAKE_CXX_STANDARD 20)

add_library( Nagen_Engine_Framework STATIC
        "src/engine.cpp"
        "include/engine.hpp"

        "src/NAGENobject.cpp"
        "include/NAGENobject.hpp"

        "src/render.cpp"
        "include/render.hpp"

        "src/objc/keyboard.mm"
        "include/objc/button.hpp"
        "include/ui/keyboard.hpp"

        "include/globalConsts.h"

        "include/NAGEN Engine-Bridging-Header.h"

        "include/vertex.hpp"
)

target_include_directories( Nagen_Engine_Framework PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)