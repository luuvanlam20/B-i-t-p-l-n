#include <iostream>
#include "Hamchung.h"
#include "Hamcoso.h"
#include "bando.h"
#include "NVchinh.h"

Hamcoso g_background;

bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0)
        return false;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    g_window = SDL_CreateWindow("GAME SINH TON", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (g_window == NULL)
        success = false;
    else
    {
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if (g_screen == NULL)
            success = false;
        else
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        int ImgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(ImgFlags) && ImgFlags))
        {
            success = false;
        }
    }
    return success;
}

bool LoadBackGround()
{
    bool ret = g_background.LoadImg("hinh//thac.png", g_screen);
    if (ret == false)
        return false;
    return true;
}

void close()
{
    g_background.Free();
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;
    SDL_DestroyWindow(g_window);
    g_window = NULL;
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if (InitData() == false)
        return -1;
    if (LoadBackGround() == false)
        return -1;



    bando game_map;
    game_map.LoadMap("map/map01.dat");
    game_map.LoadTile(g_screen);


    NVchinh player;

    player.LoadImg("hinh//player_right.png", g_screen);
    player.SETNVchinh_clip();

    bool is_quit = false;
    while (!is_quit)
    {
        while (SDL_PollEvent(&g_event) != 0)
        {
            if (g_event.type == SDL_QUIT)
            {
                is_quit = true;
            }
            player.HandInputAction(g_event, g_screen);
        }
        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);


        g_background.Render(g_screen, NULL);
        
        map map_data = game_map.getMap();

        player.SetMapXY(map_data.stratX, map_data.stratY);
        player.dichuyen(map_data);
        player.show(g_screen);
        
        game_map.SetMap(map_data);
        game_map.DrawMap(g_screen);

        SDL_RenderPresent(g_screen);
    }
    close();
    return 0;
}
