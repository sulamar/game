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
    void Render(SDL_Renderer* renderer);

    void AddObject(std::shared_ptr<GameObject> obj);

private:
    std::shared_ptr<Map> map;
    std::list<std::shared_ptr<GameObject>> objs;
    std::shared_ptr<Player> player;
    std::shared_ptr<Camera> camera;

    std::vector<std::vector<char>> level;
};