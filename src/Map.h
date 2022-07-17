#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
class Map
{
public:
    Map();

    //Loads map from file
    std::vector<std::vector<char>> LoadMap(const char* path);
};