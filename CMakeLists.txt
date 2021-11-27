cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)# -stdlib=libc++)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})# ${SDL2_IMAGE_INCLUDE_DIRS} src)
message ([STATUS] "SDL2_INCLUDE_DIRS" ${SDL2_INCLUDE_DIR})
message ([STATUS] "SDL2_LIBRARY" ${SDL2_LIBRARY})
message ([STATUS] "SDL2_IMAGE_INCLUDE_DIRS" ${SDL2_IMAGE_INCLUDE_DIR})
message ([STATUS] "SDL2_IMAGE_LIBRARY" ${SDL2_IMAGE_LIBRARY})

add_executable(UnicornRunGame src/main.cpp src/game.cpp src/controller.cpp src/renderer.cpp src/player.cpp src/terrain.cpp)
#string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
target_link_libraries(UnicornRunGame ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} stdc++fs)