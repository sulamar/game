#include "World.h"

World::World(std::shared_ptr<Map> _map, std::shared_ptr<Player> _player, std::shared_ptr<Camera> cam)
{
    map = _map;
    camera = cam;
    player = _player;

    level = map->LoadMap("../files/Levels/level1.txt");
}

void World::Render(SDL_Renderer* renderer)
{
    auto dst_world_x_player = camera->transform.position.x - player->transform.position.x;
    auto dst_world_y_player = camera->transform.position.y - player->transform.position.y;

    SDL_Rect playerDst = {dst_world_x_player, dst_world_y_player, player->sprite.dst.w, player->sprite.dst.h};

    SDL_RenderCopy(renderer, player->sprite.texture, &player->sprite.src, &playerDst);

    int type;

    for(int row = 0; row < level.size(); row++)
    {
        for(int column = 0; column < level[0].size(); column++)
        {
            for(auto obj : objs)
            {
                obj->transform.position.y = obj->transform.scale.y * row;
                obj->transform.position.x = obj->transform.scale.x * column;

                auto dst_world_x_obj = camera->transform.position.x - obj->transform.position.x;
                auto dst_world_y_obj = camera->transform.position.y - obj->transform.position.y;

                SDL_Rect objDst = {dst_world_x_obj, dst_world_y_obj, obj->sprite.dst.w, obj->sprite.dst.h};

                type = level[row][column];

                switch(type)
                {
                    case 0:
                        SDL_RenderCopy(renderer, obj->sprite.texture, &obj->sprite.src, &objDst);
                        break;
                }
            }

        }
    }

}


void World::AddObject(std::shared_ptr<GameObject> obj)
{
    objs.push_back(obj);
}

 