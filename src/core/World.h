#pragma once
#include "GameObject.h"
#include <memory>
#include "Map.h"
#include "Camera.h"
#include <list>
#include <vector>
#include "Player.h"
#include "Tile.h"
#include <map>
#include <unordered_map>

namespace engine
{
    class PhysicsWorld;

    class World
    {
    public:
        World(Map& _map, Camera& cam, std::shared_ptr<PhysicsWorld> pWorld);

        //Updates all objects
        void Update();
        
        //Renders EVERYTHING in the game but the map
        void Render(SDL_Renderer* renderer);
        
        void LoadTiles();
        
        void LoadMap(const char* path);

        void AddTileImages(std::unordered_map<char, TileImage>& map);

    private: 
        //Background colors
        int earthColor[3] = {0, 179, 255};
        int moonColor[3] = {36, 42, 44};
        int marsColor[3] = {174, 39, 39};

        //Current physics world
        std::shared_ptr<PhysicsWorld> physicsWorld;

        //Renders map
        void RenderMap(SDL_Renderer* renderer);

        //Translates world cords to screen cords
        SDL_Rect WorldToScreen(GameObject& obj);

        //Used to load map from file
        Map map;

        //TileImages
        std::unordered_map<char, TileImage> tileImages;

        //Map from file will be loaded into level
        std::vector<std::vector<char>> level;

        //Main camera
        Camera* camera;
    };


    class PhysicsWorld
    {
    public:
        PhysicsWorld(Player& _player, Camera& cam);
        PhysicsWorld();
        
        //(Update function)
        void Step(const float& dt);

        //Moves objects that need to be moved
        void MoveObjects();

        //Adds tile to tile list
        void AddTile(std::shared_ptr<Tile> tile);

        //Removes tile from tile list
        void RemoveTile(std::shared_ptr<Tile> tile);

        //Adds object to object list
        void AddObject(std::shared_ptr<GameObject> obj);

        //Removes object to object list
        void RemoveObject(std::shared_ptr<GameObject> obj);

        friend class World;

    private:

        std::vector<std::shared_ptr<Tile>> GetCollisions();

        void CheckCollision();
        
        //All rendered tiles
        std::vector<std::shared_ptr<Tile>> tiles;

        //Objects in game
        std::vector<std::shared_ptr<GameObject>> objs;

        //Main player
        Player* player;

        //Main camera
        Camera* camera;

    };
}
