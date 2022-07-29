cmake_minimum_required(VERSION 3.23.2)
project(SDL2Game)

add_subdirectory(core)
add_subdirectory(graphics)

add_executable(${PROJECT_NAME} main.cpp Game.cpp)

target_link_libraries(${PROJECT_NAME} graphics core)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer)

include_directories(SDL2Game ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
target_link_libraries(SDL2Game ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES})
