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
		y = -150;
	}

	void Cmap::LoadBitmap() {
		this->map.LoadBitmap("./RES/background.bmp",RGB(0,0,0));
	}

	void Cmap::OnMove_left() {
		if(x > -855)
			this->x -=5;
	}

	void Cmap::OnMove_right() {
		if(x<0)
			this->x += 5;
	}

	void Cmap::OnMove_up() {
		if (y > -150)
			this->y -= 5;
	}

	void Cmap::OnMove_down() {
		if (y <0) {
			this->y += 5;
		}
	}

	void Cmap::OnShow() {
		this->map.SetTopLeft(x, y);
		this->map.ShowBitmap();
	}
}