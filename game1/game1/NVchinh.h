#ifndef NV_CHINH_H_
#define NV_CHUNH_H_

#include "Hamchung.h"
#include "Hamcoso.h"
enum WAKL_TYPE
{
	RIGHT = 0,
	LEFT = 1,
};
class NVchinh : public Hamcoso
{
public:
	NVchinh();
	~NVchinh();

	bool LoadImg(std::string path, SDL_Renderer* screen);
	void show(SDL_Renderer* screen);
	void HandInputAction(SDL_Event event, SDL_Renderer* screen);
private:
	float x_val;
	float y_val;

	float x_pos;
	float y_pos;

	int width_pic;
	int height_pic;

	SDL_Rect pic_clip[8];
	input input_type;

	int frame;
	int status;


};

#endif // !NV_CHINH_H_

