# Generated on 2024-3-3 6:16:11 by version 0.9.1 of mulle-xcode-to-cmake
# Command line:
#    mulle-xcode-to-cmake -d -l c++ export NAGEN Engine.xcodeproj


cmake_minimum_required (VERSION 3.4)
project( "NAGEN Engine" CXX)

# ###
# Build for mulle-objc (https://mulle-objc.github.io/):
#
#    mulle-sde init -m foundation/objc-porter executable
#    mulle-sde craft
#
# [mulle-clang >= 8.0.0.0 and mulle-objc >= 0.15 required]
#

if( NOT DEPENDENCY_DIR)
   set( DEPENDENCY_DIR "$ENV{DEPENDENCY_DIR}")
endif()
if( NOT DEPENDENCY_DIR)
   set( DEPENDENCY_DIR "${PROJECT_SOURCE_DIR}/dependency")
endif()
if( EXISTS "${DEPENDENCY_DIR}")
   if( NOT ADDICTION_DIR)
      get_filename_component( ADDICTION_DIR "${DEPENDENCY_DIR}" DIRECTORY)
      set( ADDICTION_DIR "${ADDICTION_DIR}/addiction")
   endif()
   set( CMAKE_FIND_FRAMEWORK "LAST")
   include_directories( BEFORE SYSTEM
      ${DEPENDENCY_DIR}/include
      ${ADDICTION_DIR}/include
   )
   set( CMAKE_FRAMEWORK_PATH
      ${DEPENDENCY_DIR}/Frameworks
      ${ADDICTION_DIR}/Frameworks
      ${CMAKE_FRAMEWORK_PATH}
   )
   set( CMAKE_LIBRARY_PATH
           ${DEPENDENCY_DIR}/lib
      ${ADDICTION_DIR}/lib
      ${CMAKE_LIBRARY_PATH}
   )
   set( SKIP_FIND_FOUNDATION_LIBRARY ON)
   execute_process( COMMAND mulle-sde stash-dir
                    OUTPUT_VARIABLE MULLE_SOURCETREE_STASH_DIR)
   string( STRIP "${MULLE_SOURCETREE_STASH_DIR}" MULLE_SOURCETREE_STASH_DIR)
   execute_process( COMMAND mulle-sde linkorder --stash-dir "${MULLE_SOURCETREE_STASH_DIR}" --startup --simplify --output-format cmake
                    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
                    OUTPUT_VARIABLE MULLE_SDE_LINKER_FLAGS
                    RESULT_VARIABLE RVAL)
   if( NOT ${RVAL} EQUAL 0)
      message( FATAL_ERROR "Failed to procure linkorder from mulle-sde. Old version ?")
   endif()
   message( STATUS "MULLE_SDE_LINKER_FLAGS=\"${MULLE_SDE_LINKER_FLAGS}\"")
else()
   message( STATUS "Not a mulle-sde build (\"${DEPENDENCY_DIR}\" does not exist)")
endif()


#
# Platform specific definitions
#

if( APPLE)
   # # CMAKE_OSX_SYSROOT must be set for CMAKE_OSX_DEPLOYMENT_TARGET (cmake bug)
   # if( NOT CMAKE_OSX_SYSROOT)
   #    set( CMAKE_OSX_SYSROOT "/" CACHE STRING "SDK for OSX" FORCE)   # means current OS X
   # endif()
   #
   # # baseline set to 10.6 for rpath
   # if( NOT CMAKE_OSX_DEPLOYMENT_TARGET)
   #   set(CMAKE_OSX_DEPLOYMENT_TARGET "10.6" CACHE STRING "Deployment target for OSX" FORCE)
   # endif()

   set( CMAKE_POSITION_INDEPENDENT_CODE FALSE)
   set( CMAKE_INSTALL_RPATH "@rpath/../lib")

   set( BEGIN_ALL_LOAD "-all_load")
   set( END_ALL_LOAD)
else()
   set( CMAKE_POSITION_INDEPENDENT_CODE TRUE)

   if( WIN32)
   # windows
   else()
   # linux / gcc
      set( BEGIN_ALL_LOAD "-Wl,--whole-archive")
      set( END_ALL_LOAD "-Wl,--no-whole-archive")
      set( CMAKE_INSTALL_RPATH "\$ORIGIN/../lib")
   endif()
endif()


##
## NAGEN Engine Files
##

# uncomment this for mulle-objc to search libraries first
# set( CMAKE_FIND_FRAMEWORK "LAST")

set( SOURCES
        "NAGEN Engine/Blank.swift"
        "NAGEN Engine/src/NAGENobject.cpp"
        "NAGEN Engine/src/engine.cpp"
        "NAGEN Engine/src/render.cpp"
)

set( STATIC_DEPENDENCIES
)

if( NOT SKIP_FIND_FOUNDATION_LIBRARY)
   find_library( FOUNDATION_LIBRARY Foundation)
   message( STATUS "FOUNDATION_LIBRARY is ${FOUNDATION_LIBRARY}")
endif()
if( NOT SKIP_FIND_METAL_LIBRARY)
   find_library( METAL_LIBRARY Metal)
   message( STATUS "METAL_LIBRARY is ${METAL_LIBRARY}")
endif()
if( NOT SKIP_FIND_METAL_KIT_LIBRARY)
   find_library( METAL_KIT_LIBRARY MetalKit)
   message( STATUS "METAL_KIT_LIBRARY is ${METAL_KIT_LIBRARY}")
endif()

set( DEPENDENCIES
        ${FOUNDATION_LIBRARY}
        ${METAL_LIBRARY}
        ${METAL_KIT_LIBRARY}
)

add_library( NAGEN-Engine-lib STATIC
        ${SOURCES}
        ${PUBLIC_HEADERS}
        ${PROJECT_HEADERS}
        ${PRIVATE_HEADERS}
        ${RESOURCES}
)

add_executable( NAGEN-Engine
        ${SOURCES}
        ${PUBLIC_HEADERS}
        ${PROJECT_HEADERS}
        ${PRIVATE_HEADERS}
        ${RESOURCES}
        Game/myGame.cpp Game/myGame.hpp "NAGEN Engine/include/engine.hpp")

install( TARGETS NAGEN-Engine DESTINATION "lib")
install( FILES ${PUBLIC_HEADERS} DESTINATION "include/NAGEN-Engine")


##
## NAGEN Engine_shared
##
