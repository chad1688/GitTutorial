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
		x = -1045;
		y = -245;
	}

	void Cmap::LoadBitmap() {
		this->map.LoadBitmap("./RES/69.bmp",RGB(0,0,0));
	}

	void Cmap::OnMove_left() {
		if(x > -1045)
			this->x -=5;
	}

	void Cmap::OnMove_right() {
		if(x<0)
			this->x += 5;
	}

	void Cmap::OnMove_up() {
		if (y > -610)
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