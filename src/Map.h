#pragma once
#include <SDL2/SDL.h>

SDL_Texture* TextureManager::LoadTexture(const char* path, SDL_Renderer* renderer);

template<int n1, int n2>
class Map
{
public:
    Map(SDL_Renderer* rend)
    {
        ground.tex = TextureManager::LoadTexture("../files/images/ground.png", rend);

        src.x = 0;
        src.y = 0;
        src.w = 32;
        src.h = 32;

        dst.w = 32 * 2;
        dst.h = 32 * 2;

        dst.x = 0;
        dst.y = 0;

        ren = rend;
    }

    void LoadMap(int m[n1][n2])
    {
        rows = n1;
        columns = n2;

        for(int row = 0; row < rows; row++)
        {
            for(int column = 0; column < columns; column++)
            {
                map[row][column] = m[row][column];
            }
        }
    }

    void RenderMap(SDL_Rect& camera)
    {
        int type;

        for(int row = 0; row < rows; row++)
        {
            for(int column = 0; column < columns; column++)
            {
                ground.transform.position.x = column * 32;
                ground.transform.position.y = row * 32;

                auto dst_screen_x = camera.x - ground.transform.position.x;
                auto dst_screen_y = camera.y - ground.transform.position.y;

                dst = {dst_screen_x, dst_screen_y, dst.w, dst.h};

                type = map[row][column];

                switch(type)
                {
                    case 0:
                        SDL_RenderCopy(ren, ground.tex, &src, &dst);
                        break;
                }
            }
        }
    }

private:
    int map[n1][n2];
    int x,y;
    int rows, columns;

    SDL_Rect src, dst;
    GameObject ground;

    SDL_Renderer* ren;
};