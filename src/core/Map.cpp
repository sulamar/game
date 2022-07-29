#include "Map.h"

namespace engine
{
    Map::Map()
    {
        
    }


    std::vector<std::vector<char>> Map::LoadMap(const char* path)
    {
        std::string line;
        std::ifstream file(path);

        std::vector<std::vector<char>> map;

        int lines = 0;

        while(std::getline(file, line))
        {
            std::vector<char> row;

            for(char& c : line)
            {
                if(c == ',')
                    continue;
                if(c != ' ')
                    row.push_back(c);   
            }


            map.push_back(row);

            lines++;
        }

        //std::cout << map.size() << std::endl;
        
        return map;
    }

}