#include "NVchinh.h"

NVchinh::NVchinh()
{
	frame = 0;
	x_val = 0;
	y_val = 0;
	x_pos = 0;
	y_pos = 0;
	width_pic = 0;
	height_pic = 0;
	status = -1;
}
NVchinh::~NVchinh()
{

}
bool NVchinh::LoadImg(std::string path, SDL_Renderer* screen)
{
	bool rect = Hamcoso::LoadImg(path, screen);

}