cmake_minimum_required(VERSION "3.15.3")

# Version Information ---------------------------------------------------------
project(gridlock)
SET (GRIDLOCK_MAJOR_VERSION 0)
SET (GRIDLOCK_MINOR_VERSION 0)
SET (GRIDLOCK_PATCH_VERSION 0)
SET (VERSION "${GRIDLOCK_MAJOR_VERSION}.${GRIDLOCK_MINOR_VERSION}.${GRIDLOCK_PATCH_VERSION}")
MESSAGE ("Version: ${VERSION}")

# Configure Source & Binary Directories ---------------------------------------
SET (PROJECT_ROOT "${PROJECT_SOURCE_DIR}")
MESSAGE ("Source path: ${PROJECT_SOURCE_DIR}")

SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY build/)

SET (CMAKE_CXX_STANDARD 14)
SET (CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ../libraries
    ../libraries/boost
    ../libraries/boost/libs

    ../libraries/nlohmann

    src/actions
    src/grid
    src/material
    src/objects
    src/utilities
    src/player
    src/items
    src/items/ammunitions
    src/player/shipModules
    src/webSocketServer
    )

# Local source files here
SET (TARGET_SRC
    src/main.cpp
    src/grid/grid.cpp
    src/grid/node.cpp
    src/material/blueprint.cpp
    src/material/material.cpp
    src/objects/deposit.cpp
    #src/items/ammunitions/bullet.cpp
    #src/items/ammunitions/rocket.cpp
    #src/player/shipModules/booster.cpp
    #src/player/shipModules/container.cpp
    #src/player/shipModules/generator.cpp
    #src/player/shipModules/gun.cpp
    #src/player/shipModules/shield.cpp
    src/items/item.cpp
    src/player/fabricator.cpp
    src/player/player.cpp
    src/player/slots.cpp
    src/utilities/util.cpp
    src/utilities/config.cpp
    src/webSocketServer/listener.cpp
    src/webSocketServer/webSocketSession.cpp src/player/Ship.cpp
    src/player/Ship.h

        )

add_executable("${PROJECT_NAME}" "${TARGET_SRC}")
