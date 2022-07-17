#pragma once
#include "GameObject.h"
#include <memory>
#include "Map.h"
#include "Camera.h"
#include <list>
#include "Player.h"

class World
{
public:
    World(std::shared_ptr<Map> _map, std::shared_ptr<Player> _player, std::shared_ptr<Camera> cam);

    //Renders EVERYTHING in the game but the map
    void Render(SDL_Renderer* renderer);

    //Renders map
    void RenderMap(SDL_Renderer* renderer);
    
    //Adds object to object list
    void AddObject(std::shared_ptr<GameObject> obj);

    //Removes object to object list
    void RemoveObject(std::shared_ptr<GameObject> obj);
    
private: 
    //Used to load map from file
    std::shared_ptr<Map> map;

    //List of diffrent kinds of objects that could be renderer based on a value in the level file
    std::vector<std::shared_ptr<GameObject>> objs;

    std::shared_ptr<GameObject> obj;
    //Player and camera
    std::shared_ptr<Player> player;
    std::shared_ptr<Camera> camera;

    //Map from file will be loaded into level
    std::vector<std::vector<char>> level;
};