#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

namespace engine
{
    class Map
    {
    public:
        Map(); 
        std::vector<std::vector<char>> LoadMap(const char* path);

    private:
        //Loads map from file

        std::vector<std::vector<char>> map;
    };
}
