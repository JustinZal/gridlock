cmake_minimum_required(VERSION "3.17.3")

# Version Information ---------------------------------------------------------
project(gridlock)
SET (VERSION_MAJOR 0)
SET (VERSION_MINOR 0)
SET (VERSION_FEATURE 0)
SET (VERSION_PATCH 0)
SET (VERSION "${VERSION_MAJOR}.${VERSION_MINOR}")
SET (VERSION "${VERSION}.${VERSION_FEATURE}.${VERSION_PATCH}")
MESSAGE ("Version: ${VERSION}")

# Configure Source & Binary Directories ---------------------------------------
SET (PROJECT_ROOT "${PROJECT_SOURCE_DIR}")
SET (PROJECT_BINARY_DIR "${PROJECT_BINARY_DIR}/bin")
MESSAGE ("Source path: ${PROJECT_SOURCE_DIR}")
MESSAGE ("Binary path: ${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(
"${CMAKE_SOURCE_DIR}/src/actions",
"${CMAKE_SOURCE_DIR}/src/grid",
"${CMAKE_SOURCE_DIR}/src/material",
"${CMAKE_SOURCE_DIR}/src/objects",
"${CMAKE_SOURCE_DIR}/src/utilities",
"${CMAKE_SOURCE_DIR}/src/player",
"${CMAKE_SOURCE_DIR}/src/player/items",
"${CMAKE_SOURCE_DIR}/src/player/items/shipItems",
"${CMAKE_SOURCE_DIR}/src/player/items/ammunitions")


# Local source files here
SET(TARGET_SRC
    src/main.cpp
    src/grid/grid.cpp
    src/grid/node.cpp
    src/material/blueprint.cpp
    src/material/material.cpp
    src/objects/deposit.cpp
    src/player/items/ammunitions/bullet.cpp
    src/player/items/ammunitions/rocket.cpp
    src/player/items/shipItems/booster.cpp
    src/player/items/shipItems/container.cpp
    src/player/items/shipItems/generator.cpp
    src/player/items/shipItems/gun.cpp
    src/player/items/shipItems/shield.cpp
    src/player/items/item.cpp
    src/player/player.cpp
    src/player/slots.cpp
    src/utilities/util.cpp
    )


add_executable("${PROJECT_NAME}" "${TARGET_SRC}")
