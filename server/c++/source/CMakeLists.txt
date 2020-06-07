cmake_minimum_required(VERSION "3.17.3")

project("gridlock")

include_directories(grid)
include_directories(utilities)
include_directories(objects)
include_directories(player/items)
include_directories(player/items/shipItems)

add_executable("${PROJECT_NAME}" "main.cpp")
