cmake_minimum_required(VERSION "3.17.3")

project("gridlock")


include_directories(actions)

include_directories(grid)

include_directories(objects)

include_directories(utilities)

include_directories(player)
include_directories(player/items)
include_directories(player/items/shipItems)
include_directories(player/items/ammunitions)


add_executable("${PROJECT_NAME}" "main.cpp")
