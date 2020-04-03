#ifndef NV_CHINH_H_
#define NV_CHUNH_H_

#include "Hamchung.h"
#include "Hamcoso.h"

class NVchinh : public Hamcoso
{
public:
	NVchinh();
	~NVchinh();
	enum WAKL_TYPE
	{
		RIGHT = 0,
		LEFT = 1,
	};
	bool LoadImg(std::string path, SDL_Renderer* screen);
	void show(SDL_Renderer* des);
	void HandInputAction(SDL_Event event, SDL_Renderer* screen);
	void SETNVchinh_clip();
	void dichuyen(map& map_data);
	void vacham(map& map_data);
	void SetMapXY(const int map_x, const int map_y) { map_x_ = map_x; map_y_ = map_y; }
	void centerMap(map& map_data);
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
	bool on_groud;
	int map_x_;
	int map_y_;

};

#endif // !NV_CHINH_H_


