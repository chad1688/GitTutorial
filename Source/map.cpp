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
	Cmap::Cmap()
		:X(1152 - (64 * 18)), Y(0), MW(59), MH(45)
	{
		int a = 1;
	}


	void Cmap::LoadBitmap()
	{
		Mapobj.LoadBitmap("RES/wall2.bmp");
	}
	


	bool Cmap::isObj(int x, int y) {
		if (this->map[y][x] != 0) {
			return true;
		}
		return false;
	}

	

	void Cmap::interaction(int x, int y) {
		int ID = this->map[y][x];
		if (ID > 7 && ID < 13) {
			map[y][x] = ID + 5;
		}
	}

	void Cmap::OnShow()
	{
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				int ID = this->map[i][j];
				if (ID > 0) {
					Mapobj.SetTopLeft(X + (MW * j), Y + (MH * i));
					Mapobj.ShowBitmap(0.2);
				}
			}
		}
	}
	void Cmap::test(int num) {
		map[0][0] = num;

	}
}