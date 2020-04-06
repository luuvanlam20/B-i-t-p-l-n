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
		JUMP = 2,
		RIGHT = 0,
		LEFT = 1,
	};
	bool LoadImg(std::string path, SDL_Renderer* screen);//load anh
	void show(SDL_Renderer* des);//show anh
	void HandInputAction(SDL_Event event, SDL_Renderer* screen);//nhap tu ngoai
	void SETNVchinh_clip();//clip nhan vat
	void dichuyen(map& map_data);//di chuyen
	void vacham(map& map_data);//va cham
	void SetMapXY(const int map_x, const int map_y) { map_x_ = map_x; map_y_ = map_y; }//set toa do X,Y
	void centerMap(map& map_data);//man hinh di chuyen
	void updateImg(SDL_Renderer* des);
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

	int time_back;

};

#endif // !NV_CHINH_H_


