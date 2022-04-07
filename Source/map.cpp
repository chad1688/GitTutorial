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
	}

	void Cmap::LoadBitmap() {
		this->map.LoadBitmap("./RES/background.bmp",RGB(0,0,0));
		this->wall .LoadBitmap("./RES/70.bmp", RGB(255, 255, 255));
		this->wall2.LoadBitmap("./RES/76.bmp", RGB(255, 255, 255));
		this->wall3.LoadBitmap("./RES/70_left.bmp", RGB(255, 255, 255));
		this->wall4.LoadBitmap("./RES/70_right.bmp", RGB(255, 255, 255));
	}

	bool Cmap::isObject(int people_x,int people_y) {
		if (all_map[((-y)+people_y)/110][((-x) + people_x + MW2) / 80] == 0) {
			return true;
		}
		return false;
	}

	void Cmap::OnMove_left() {
		if (x > -1045) {
			this->x -= 20;
		}
	}

	void Cmap::OnMove_right() {
		if(x<0)
			this->x += 20;
	}

	void Cmap::OnMove_up() {
		if (y > -610)
			this->y -= 20;
	}

	void Cmap::OnMove_down() {
		if (y <0) {
			this->y += 20;
		}
	}

	void Cmap::OnShow() {
		this->map.SetTopLeft(x, y);
		this->map.ShowBitmap();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 22; j++) {
				if (all_map[i][j] == 1) {
					this->wall.SetTopLeft(x + MW * j-MW2, y + MH * i);
					this->wall.ShowBitmap();
				}
				if (all_map[i][j] == 2) {
					this->wall2.SetTopLeft(x + MW * j - MW2, y + MH * i);
					this->wall2.ShowBitmap();
		
				}
				if (all_map[i][j] == 3) {
					this->wall3.SetTopLeft(x + MW * j, y + MH * i );
					this->wall3.ShowBitmap();
				}
				if (all_map[i][j] == 4) {
					this->wall4.SetTopLeft(x + MW * j-MW2, y + MH * i);
					this->wall4.ShowBitmap();
				}
			}
		}
	}
}