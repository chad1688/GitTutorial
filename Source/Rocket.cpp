#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "string"
#include "vector"
#include "CPeople.h"
#include "Rocket.h"
#include "map.h"

namespace game_framework {
	CRocket::CRocket() {
		bullet = 0;
		space = 0;
		show = 0;
		empty_bullet = 0;
		count2 = 0;
		for (int i = 0; i < 40; i++) {
			temp_bullet[i] = 0;
			temp_infrontof[i] = 0;
			temp_back[i] = 0;
			temp_right[i] = 0;
			temp_left[i] = 0;
			shot_stop[i] = 0;
		}
		is_space = false;
	}

	void CRocket::LoadBitmap() {
		boom.LoadBitmap("RES/566.bmp", RGB(255, 255, 255));
		for (int i = 0; i < 40; i++) {
			shot_back[i].LoadBitmap("RES/rocket_down.bmp", RGB(255, 255, 255));
			shot_infrontof[i].LoadBitmap("RES/rocket_up.bmp", RGB(255, 255, 255));
			shot_left[i].LoadBitmap("RES/rocket_left.bmp", RGB(255, 255, 255));
			shot_right[i].LoadBitmap("RES/rocket_right.bmp", RGB(255, 255, 255));
		}
	}

	void CRocket::Getmapaddress(Cmap *m) {
		map = m;
	}

	void CRocket::shot_OnMove() {
		count2++;
		if (is_space) {
			if (count2 >= 30)
			{
				if (space == 0) {
					if (bullet == 40) {
						bullet = 0;
						empty_bullet = 1;
					}
					shot_stop[bullet] = 0;
					if (infrontof1 == 1 && back == 0 && right == 0 && left == 0) {
						shot_infrontof[bullet].SetTopLeft(gunx_up, guny_up);
						shot_infrontof[bullet].ShowBitmap();
						temp_infrontof[bullet] = 1;
						temp_guny[bullet] = guny_up;
						temp_gunx[bullet] = gunx_up;
						space_mapy = (-map->y);
					}
					if (back == 1 && infrontof1 == 0 && right == 0 && left == 0) {
						shot_back[bullet].SetTopLeft(gunx_down, guny_down);
						shot_back[bullet].ShowBitmap();
						temp_back[bullet] = 1;
						temp_guny[bullet] = guny_down;
						temp_gunx[bullet] = gunx_down;
						space_mapy = (-map->y);
					}
					if (right == 1 && back == 0 && infrontof1 == 0 && left == 0) {
						shot_right[bullet].SetTopLeft(gunx_right, guny_right);
						shot_right[bullet].ShowBitmap();
						temp_right[bullet] = 1;
						temp_guny[bullet] = guny_right;
						temp_gunx[bullet] = gunx_right;
						space_mapx = (-map->x);
					}
					if (left == 1 && right == 0 && infrontof1 == 0 && right == 0) {
						shot_left[bullet].SetTopLeft(gunx_left, guny_left);
						shot_left[bullet].ShowBitmap();
						temp_left[bullet] = 1;
						temp_guny[bullet] = guny_left;
						temp_gunx[bullet] = gunx_left;
						space_mapx = (-map->x);
					}
					bullet++;
				}
				if (space == 0)
					space = 1;
				count2 = 0;
			}
			
			//my_bullet[1] -= 1;
		}
	}

	void CRocket::shot_OnMove2() {
		if (isMovingright && isMovingleft == false && isMovingup == false && isMovingdown == false && map->isObject(gunx_down + 70,gunx_left) && map->isObject(gunx_down + 70, gunx_left + 60)) {
			if (gunx_up == 330 || gunx_down == 300 || gunx_right == 330 || gunx_left == 300) {
				for (int i = 0; i < 40; i++) {
					if (temp_bullet[i] != 0 || temp_infrontof[i] != 0 || temp_back[i] != 0 || temp_left[i] != 0) {
						temp_gunx[i] -= 10;

					}
				}
			}
			if (show != 0) {
				boomx -= 10;
			}
		}
		if (isMovingleft && isMovingright == false && isMovingup == false && isMovingdown == false && map->isObject(gunx_down - 1, gunx_left) && map->isObject(gunx_down - 1, gunx_left + 60)) {
			if (gunx_up == 330 || gunx_down == 300 || gunx_right == 330 || gunx_left == 300) {
				for (int i = 0; i < 40; i++) {
					if (temp_bullet[i] != 0 || temp_infrontof[i] != 0 || temp_back[i] != 0 || temp_right[i] != 0) {
						temp_gunx[i] += 10;

					}
				}
			}
			if (show != 0) {
				boomx += 10;
			}
		}
		if (isMovingup && isMovingright == false && isMovingleft == false && isMovingdown == false && map->isObject(gunx_down , gunx_left - 1) && map->isObject(gunx_down + 60, gunx_left - 1)) {
			if (guny_up == 300 || guny_down == 330 || guny_right == 330 || guny_left == 330) {
				for (int i = 0; i < 40; i++) {
					if (temp_right[i] != 0 || temp_left[i] != 0 || temp_back[i] != 0) {
						temp_guny[i] += 10;

					}
				}
			}
			if (show != 0) {
				boomy += 10;
			}
		}
		if (isMovingdown && isMovingright == false && isMovingup == false && isMovingleft == false && map->isObject(gunx_down , gunx_left + 61) && map->isObject(gunx_down + 60, gunx_left + 61)) {
			if (guny_up == 300 || guny_down == 330 || guny_right == 330 || guny_left == 330) {
				for (int i = 0; i < 40; i++) {
					if (temp_right[i] != 0 || temp_left[i] != 0 || temp_infrontof[i] != 0) {
						temp_guny[i] -= 10;

					}
				}
			}
			if (show != 0) {
				boomy -= 10;
			}
		}
		if (space != 0) {
			int total_bullet = 0;
			for (int i = 0; i < 40; i++) {
				if (temp_infrontof[i] == 1) {
					if ((-map->y) + temp_guny[i] >= space_mapy + (guny_up - 300) && map->isObject(temp_gunx[i], temp_guny[i] - 1) && shot_stop[i] == 0) {
						temp_guny[i] -= 10;
						shot_infrontof[i].SetTopLeft(temp_gunx[i], temp_guny[i]);
						//shot_back[0].ShowBitmap();
					}
					else {
						count = 0;
						boomx = temp_gunx[i] - 100;
						boomy = temp_guny[i] - 40;
						show = 1;
						temp_gunx[i] = 0;
						temp_guny[i] = 0;
						temp_infrontof[i] = 0;
					}
				}
				if (temp_back[i] == 1) {
					if ((-map->y) + temp_guny[i] <= space_mapy + (guny_down + 300) && map->isObject(temp_gunx[i], temp_guny[i] + 30) && shot_stop[i] == 0) {
						temp_guny[i] += 10;
						shot_back[i].SetTopLeft(temp_gunx[i], temp_guny[i]);
						//shot_back[0].ShowBitmap();
					}
					else {
						count = 0;
						boomx = temp_gunx[i] - 100;
						boomy = temp_guny[i] - 40;
						temp_gunx[i] = 0;
						temp_guny[i] = 0;
						show = 1;
						temp_back[i] = 0;
					}
				}
				if (temp_right[i] == 1) {
					if ((-map->x) + temp_gunx[i] <=space_mapx + (gunx_right + 300) && map->isObject(temp_gunx[i] + 30, temp_guny[i]) && shot_stop[i] == 0) {
						temp_gunx[i] += 10;
						shot_right[i].SetTopLeft(temp_gunx[i], temp_guny[i]);
						//shot_back[0].ShowBitmap();
					}
					else {
						count = 0;
						boomx = temp_gunx[i] - 100;
						boomy = temp_guny[i] - 40;
						temp_gunx[i] = 0;
						temp_guny[i] = 0;
						show = 1;
						temp_right[i] = 0;
					}
				}
				if (temp_left[i] == 1) {
					if ((-map->x) + temp_gunx[i] >= space_mapx + (gunx_left - 300) && map->isObject(temp_gunx[i] - 30, temp_guny[i]) && shot_stop[i] == 0) {
						temp_gunx[i] -= 10;
						shot_left[i].SetTopLeft(temp_gunx[i], temp_guny[i]);
						//shot_back[0].ShowBitmap();
					}
					else {
						count = 0;
						boomx = temp_gunx[i] - 100;
						boomy = temp_guny[i] - 40;
						temp_gunx[i] = 0;
						temp_guny[i] = 0;
						show = 1;
						temp_left[i] = 0;
					}
				}
				total_bullet += temp_infrontof[i] + temp_back[i] + temp_right[i] + temp_left[i];
			}
			if (total_bullet == 0) {
				space = 0;
			}
		}
		if (show == 1) {
			count++;
			if (count == 5) {
				boom.SetTopLeft(boomx, boomy);
				show = 2;
			}
		}
	}

	void CRocket::Setspace(bool flag)
	{
		is_space = flag;
	}

	void CRocket::shot_OnShow() {
		for (int i = 0; i < 40; i++) {
			if (temp_infrontof[i] == 1 && show == 0)
				shot_infrontof[i].ShowBitmap();
			if (temp_back[i] == 1)
				shot_back[i].ShowBitmap();
			if (temp_right[i] == 1)
				shot_right[i].ShowBitmap();
			if (temp_left[i] == 1)
				shot_left[i].ShowBitmap();
		}
		if (show == 2) {
			boom.ShowBitmap();
			show = 0;
		}
	}

}