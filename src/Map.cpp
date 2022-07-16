#include "Map.h"

Map::Map()
{

}

std::vector<std::vector<char>> Map::LoadMap(const char* path)
{
    std::string line;
    std::ifstream file(path);

    std::vector<std::vector<char>> map;

    while(std::getline(file, line))
    {
        std::vector<char> row;

        for(char& c : line)
        {
            row.push_back(c);
        }

        map.push_back(row);
    }

    for(std::vector<char>& row : map)
    {
        for(char& c : row)
        {
            std::cout << c;
        }
        
        std::cout << "\n";
    }

    return map;
}