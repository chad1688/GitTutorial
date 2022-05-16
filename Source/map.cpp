#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "string"
#include "map.h"
#include "vector"
#include "CPeople.h"

namespace game_framework {
	Cmap::Cmap( ) {
		x = 0;
		y = 0;
		MH = 110;
		MW = 80;
		MW2 = 40;
		wall1_index = wall2_index = wall3_index = wall4_index = gun_index = 0;
		for (int i = 0; i < 2; i++)
			temp3[i] = 0;
	}

	void Cmap::LoadBitmap() {
		this->map.LoadBitmap("./RES/background.bmp",RGB(0,0,0));
		this->wall.LoadBitmap("./RES/70.bmp", RGB(255, 255, 255));
		this->wall2.LoadBitmap("./RES/76.bmp", RGB(255, 255, 255));
		this->wall3.LoadBitmap("./RES/70_left.bmp", RGB(255, 255, 255));
		this->wall4.LoadBitmap("./RES/70_right.bmp", RGB(255, 255, 255));
		for(int i = 0;i<2;i++)
			this->new_gun[i].LoadBitmap("./RES/643.bmp", RGB(0, 0, 0));
		
	}

	bool Cmap::isObject(int people_x,int people_y) {
		if (all_map[((-y)+people_y)/110][((-x) + people_x + MW2) / 80] <= 0 || all_map[((-y) + people_y) / 110][((-x) + people_x + MW2) / 80] > 5) {
			return true;
		}
		return false;
	}

	void Cmap::OnMove_left() {
		if (x > -1045) {
			this->x -= 10;
		}
	}

	void Cmap::OnMove_right() {
		if(x<0)
			this->x += 10;
	}

	void Cmap::OnMove_up() {
		if (y > -610)
			this->y -= 10;
	}

	void Cmap::OnMove_down() {
		if (y <0) {
			this->y += 10;
		}
	}

	void Cmap::OnMove_redbox_address() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 22; j++) {
				if (all_map[i][j] > 5) {
					if (gun_index >= 2)
						gun_index = 0;
					redbox_x[gun_index] = MW * j - MW2;
					//TRACE("%d", redbox_x[1]);
					redbox_y[gun_index] = MH * i;
				    gun_index++;
				}
			}
		}
	}

	void Cmap::OnMove_redbox_live() 
	{
		for (int i = 0; i < 2; i++) {
			if (redbox_appear3[i] == 1 && temp3[i] == 0) {
				count_red_box3[i] = 0;
				temp3[i] = 1;
			}
			count_red_box3[i] ++;
			if (count_red_box3[i] == 180) {
				redbox_appear3[i] = 0;
				temp3[i] = 0;
			}
		}
	}

	void Cmap::OnShow() {
		this->map.SetTopLeft(x, y);
		
		this->map.ShowBitmap();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 22; j++) {
				if (all_map[i][j] == 2) {
					this->wall.SetTopLeft(x + MW * j - MW2, y + MH * i);
					this->wall.ShowBitmap();
				}
				if (all_map[i][j] == 3) {
					this->wall2.SetTopLeft(x + MW * j - MW2, y + MH * i);
					this->wall2.ShowBitmap();

				}
				if (all_map[i][j] == 4) {
					this->wall3.SetTopLeft(x + MW * j, y + MH * i);
					this->wall3.ShowBitmap();
				}
				if (all_map[i][j] == 5) {
					this->wall4.SetTopLeft(x + MW * j - MW2, y + MH * i);
					this->wall4.ShowBitmap();
				}
				if (all_map[i][j] == 6 && redbox_appear3[0] == 0) {
					this->new_gun[0].SetTopLeft(x + MW * j - MW2, y + MH * i);
					this->new_gun[0].ShowBitmap();
				}
				if (all_map[i][j] == 7 && redbox_appear3[1] == 0) {
					this->new_gun[1].SetTopLeft(x + MW * j - MW2, y + MH * i);
					this->new_gun[1].ShowBitmap();
				}
			}
		}
	}
}