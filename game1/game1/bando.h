#ifndef BAN_DO_H_
#define BAN_DO_H_

#include "Hamchung.h"
#include "Hamcoso.h"
#define MAXTILE 20
class TileMap : public Hamcoso
{
public:
	TileMap() { ; }
	~TileMap() { ; }

};

typedef class bando
{
public:
	bando() { ; }
	~bando() { ; }
	void LoadMap(const char* nap);
	void LoadTile(SDL_Renderer* screen);
	void DrawMap(SDL_Renderer* screen);

private:
	map ban_do;
	TileMap tile_map[MAXTILE];
};

#endif
