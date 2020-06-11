cmake_minimum_required(VERSION "3.17.3")

# Version Information ---------------------------------------------------------
project(gridlock)
SET (GRIDLOCK_MAJOR_VERSION 0)
SET (GRIDLOCK_MINOR_VERSION 8)
SET (GRIDLOCK_PATCH_VERSION 2)
SET (VERSION "${GRIDLOCK_MAJOR_VERSION}.${GRIDLOCK_MINOR_VERSION}.${GRIDLOCK_PATCH_VERSION}")
MESSAGE ("Version: ${VERSION}")

# Configure Source & Binary Directories ---------------------------------------
SET (PROJECT_ROOT "${PROJECT_SOURCE_DIR}")
SET (PROJECT_BINARY_DIR "${PROJECT_BINARY_DIR}/bin")
MESSAGE ("Source path: ${PROJECT_SOURCE_DIR}")
MESSAGE ("Binary path: ${PROJECT_BINARY_DIR}")

SET (CMAKE_CXX_STANDARD 11)
SET (CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(
<<<<<<< HEAD
    src/libraries
    src/libraries/boost
    src/libraries/boost/libs

    src/actions
    src/grid
    src/material
    src/objects
    src/utilities
    src/player
    src/items
    src/shipModules
    src/items/ammunitions
    )
=======
"${CMAKE_SOURCE_DIR}/src/actions",
"${CMAKE_SOURCE_DIR}/src/grid",
"${CMAKE_SOURCE_DIR}/src/material",
"${CMAKE_SOURCE_DIR}/src/objects",
"${CMAKE_SOURCE_DIR}/src/utilities",
"${CMAKE_SOURCE_DIR}/src/player",
"${CMAKE_SOURCE_DIR}/src/items",
"${CMAKE_SOURCE_DIR}/src/shipModules",
"${CMAKE_SOURCE_DIR}/src/items/ammunitions")

>>>>>>> 4ae54e7aedd27cdea6ba6a120862cb09dc924c7a

# Local source files here
SET (TARGET_SRC
    src/main.cpp
<<<<<<< HEAD
    #src/grid/grid.cpp
    #src/grid/node.cpp
    #src/material/blueprint.cpp
    #src/material/material.cpp
    #src/objects/deposit.cpp
    #src/items/ammunitions/bullet.cpp
    #src/items/ammunitions/rocket.cpp
    #src/shipModules/booster.cpp
    #src/shipModules/container.cpp
    #src/shipModules/generator.cpp
    #src/shipModules/gun.cpp
    #src/shipModules/shield.cpp
    #src/items/item.cpp
    #src/player/fabricator.cpp
    #src/player/player.cpp
    #src/player/slots.cpp
    #src/utilities/util.cpp
=======
    src/grid/grid.cpp
    src/grid/node.cpp
    src/material/blueprint.cpp
    src/material/material.cpp
    src/objects/deposit.cpp
    src/items/ammunitions/bullet.cpp
    src/items/ammunitions/rocket.cpp
    src/shipModules/booster.cpp
    src/shipModules/container.cpp
    src/shipModules/generator.cpp
    src/shipModules/gun.cpp
    src/shipModules/shield.cpp
    src/items/item.cpp
    src/player/fabricator.cpp
    src/player/player.cpp
    src/player/slots.cpp
    src/utilities/util.cpp
>>>>>>> 4ae54e7aedd27cdea6ba6a120862cb09dc924c7a
    )


add_compile_definitions(ASIO_STANDALONE)


add_executable("${PROJECT_NAME}" "${TARGET_SRC}" build/)
