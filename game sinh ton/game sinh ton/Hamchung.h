#ifndef HAM_CHUNG_H_
#define HAM_CHUNG_H_

#include <Windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

//Screen
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

//Collor

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;


const int RENDER_DRAW_COLOR = 0xff;

#define chotrong 0
#define TILE_SIZE 64
#define MAPMAX_X 400
#define MAPMAX_Y 10

typedef struct map
{
	int stratX;
	int stratY;

	int max_X;
	int max_Y;
	int tile[MAPMAX_Y][MAPMAX_X];
	const char* file_name;
};

typedef struct input
{
	int left;
	int right;
	int up;
	int down;
	int jump;
};

#endif
