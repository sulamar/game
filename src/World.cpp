#include "World.h"

World::World(std::shared_ptr<Map> _map, std::shared_ptr<Player> _player, std::shared_ptr<Camera> cam)
{
    map = _map;
    camera = cam;
    player = _player;

    level = map->LoadMap("../files/levels/level1.txt");

}

void World::Render(SDL_Renderer* renderer)
{
    //Clears renderer and sets background color
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
  
    //RENDER MAP
    RenderMap(renderer);


    //Translates player world coords into screen coords
    int dst_screen_x_player = player->transform.position.x - camera->transform.position.x;
    int dst_screen_y_player = player->transform.position.y - camera->transform.position.y;

    SDL_Rect playerDst = {dst_screen_x_player, dst_screen_y_player, player->sprite.dst.w, player->sprite.dst.h};

    SDL_RenderCopy(renderer, player->sprite.texture, &player->sprite.src, &playerDst);


    //Renders everything
    SDL_RenderPresent(renderer);

}

void World::RenderMap(SDL_Renderer* renderer)
{
    char type;

    for(int row = 0; row < level.size(); row++)
    {
        for(int column = 0; column < level[row].size(); column++)
        {
           
            obj->transform.position.y = obj->transform.scale.y * row;
            obj->transform.position.x = obj->transform.scale.x * column;

            //Translates objects world coords into screen coords
            int dst_screen_x_obj = obj->transform.position.x - camera->transform.position.x;
            int dst_screen_y_obj = obj->transform.position.y - camera->transform.position.y;

            SDL_Rect objDst = {dst_screen_x_obj, dst_screen_y_obj, obj->sprite.dst.w, obj->sprite.dst.h};

            type = level[row][column];

            switch(type)
            {
                case '0':     
                    SDL_RenderCopy(renderer, obj->sprite.texture, &obj->sprite.src, &objDst);
                    break;

                default:
                    break;
            }
            
           
        }

    }
}

void World::AddObject(std::shared_ptr<GameObject> obj)
{
    this->obj = obj;
}

void World::RemoveObject(std::shared_ptr<GameObject> obj)
{
    //objs.remove(obj);
}

 