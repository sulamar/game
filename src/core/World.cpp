#include "World.h"
#include "Camera.h"
#include "GameObject.h"
#include "Player.h"
#include "Tile.h"
#include <memory>
#include <ostream>
#include <vector>

namespace engine
{
    class PhysicsWorld;

    World::World(Map& _map, Camera& cam, std::shared_ptr<PhysicsWorld> pWorld)
        : map(_map), camera(&cam), physicsWorld(pWorld)
    { 
    }

    void World::Update()
    {
    }
    
    void World::LoadMap(const char *path)
    {
        level = map.LoadMap(path);
    }

    void World::Render(SDL_Renderer* renderer)
    {
        //Clears renderer and sets background color
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, earthColor[0], earthColor[1], earthColor[2], 255);
        
        //RENDER MAP
        RenderMap(renderer);

        //Renders the player
        SDL_Rect playerDst = WorldToScreen(*physicsWorld->player);
        physicsWorld->player->Render(renderer, playerDst);


        //Renders objects
        for(std::shared_ptr<GameObject> obj : physicsWorld->objs)
        {
            SDL_Rect objDst = WorldToScreen(*obj);
            obj->Render(renderer, objDst);
        }

        //Renders everything
        SDL_RenderPresent(renderer);

    }


    void World::AddTileImages(std::unordered_map<char, TileImage>& map)
    {
        tileImages = map;
    }

    SDL_Rect World::WorldToScreen(GameObject& obj)
    {
        int dstScreenX = obj.transform.position.x - camera->transform.position.x;
        int dstScreenY = obj.transform.position.y - camera->transform.position.y;
        SDL_Rect dst = {dstScreenX, dstScreenY, obj.sprite.dst.w, obj.sprite.dst.h};

        return dst;
    }

    void World::LoadTiles()
    {
        char type;

        for(int row = 0; row < level.size(); row++)
        {
            for(int column = 0; column < level[row].size(); column++)
            {
                type = level[row][column];  

                switch(type)
                {
                    case '1':
                    {
                        TileImage& tile = tileImages[1];
                        physicsWorld->AddTile(std::make_shared<Tile>(tile.sprite.texture, 
                        Vector2<float>(tile.transform.scale.x * column, tile.transform.scale.y * row),
                        Vector2<int>(tile.transform.scale.x, tile.transform.scale.y)));

                        break;       
                    }
                    case '2':
                    {
                        TileImage& tile = tileImages[2];
                        physicsWorld->AddTile(std::make_shared<Tile>(tile.sprite.texture, 
                        Vector2<float>(tile.transform.scale.x * column, tile.transform.scale.y * row),
                        Vector2<int>(tile.transform.scale.x, tile.transform.scale.y)));
                        break;       
                    }
                    case '3':
                    {
                        TileImage& tile = tileImages[3];
                        physicsWorld->AddTile(std::make_shared<Tile>(tile.sprite.texture, 
                        Vector2<float>(tile.transform.scale.x * column, tile.transform.scale.y * row),
                        Vector2<int>(tile.transform.scale.x, tile.transform.scale.y)));
                        break;      
                    }

                    default:
                        break;
                }
                
                
            }
        }
    }

    void World::RenderMap(SDL_Renderer* renderer)
    {
        for(std::shared_ptr<Tile> tile : physicsWorld->tiles)
        {
            SDL_Rect tileDst = WorldToScreen(*tile);
            tile->Render(renderer, tileDst);
        }   
        
    }

   
    
    PhysicsWorld::PhysicsWorld(Player& _player, Camera& cam)
        : player(&_player), camera(&cam)
    {
    }

    PhysicsWorld::PhysicsWorld()
    {

    }

    void PhysicsWorld::MoveObjects()
    {

    }

    std::vector<std::shared_ptr<Tile>> PhysicsWorld::GetCollisions()
    {
        std::vector<std::shared_ptr<Tile>> t;

        for(auto& tile : tiles)
        {
            if(player->collider.AABB(tile->collider))
            {
                t.push_back(tile);
            }
        }

        return t;
    }

    void PhysicsWorld::CheckCollision()
    {
        for(auto& tile : GetCollisions())
        {
            if(player->fallSpeed > 0.0f)
            {
                //player->transform.position.y -= player->positionOffset.y;
                player->isJumping = false;
                player->isGrounded = true;
                player->fallSpeed = player->fallSpeed - player->fallSpeed;
            } 
     

        }

        if(player->isJumping)
        {
            //player->transform.position.y -= 4;
        }

        if(GetCollisions().empty())
        {
            player->fallSpeed += player->rigidBody.gravity;
        }
    }

    void PhysicsWorld::Step(const float& dt)
    {
        CheckCollision();
        
        player->Update(dt);

        for(std::shared_ptr<GameObject> obj : objs)
        {
            obj->Update(dt);
        }

        MoveObjects();
        CheckCollision();
    }


    void PhysicsWorld::AddTile(std::shared_ptr<Tile> tile)
    {
        tiles.push_back(tile);
    }

    //Remove tiles...

    void PhysicsWorld::AddObject(std::shared_ptr<GameObject> obj)
    {
        objs.push_back(obj);
    }

    //Remove objects...



}
 