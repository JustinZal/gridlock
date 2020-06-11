cmake_minimum_required(VERSION "3.17.3")

# Version Information ---------------------------------------------------------
project(gridlock_client)
SET (GRIDLOCK_CLIENT_MAJOR_VERSION 0)
SET (GRIDLOCK_CLIENT_MINOR_VERSION 8)
SET (GRIDLOCK_CLIENT_PATCH_VERSION 2)
SET (VERSION "${GRIDLOCK_CLIENT_MAJOR_VERSION}.${GRIDLOCK_CLIENT_MINOR_VERSION}.${GRIDLOCK_CLIENT_PATCH_VERSION}")
MESSAGE ("Version: ${VERSION}")

# Configure Source & Binary Directories ---------------------------------------
SET (PROJECT_ROOT "${PROJECT_SOURCE_DIR}")
MESSAGE ("Source path: ${PROJECT_SOURCE_DIR}")

SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY build/)

SET (CMAKE_CXX_STANDARD 11)
SET (CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ../libraries
    ../libraries/boost
    ../libraries/boost/libs
    )

# Local source files here
SET (TARGET_SRC
    src/main.cpp
    )

add_executable("${PROJECT_NAME}" "${TARGET_SRC}")
