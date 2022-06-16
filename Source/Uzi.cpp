#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "string"
#include "vector"
#include "CPeople.h"
#include "Uzi.h"
#include "map.h"

namespace game_framework {
	Cuzi::Cuzi() {
		bullet = 0;
		space = 0;
		count = 3;
		empty_bullet = 0;
		for (int i = 0; i < 100; i++) {
			temp_bullet[i] = 0;
			temp_infrontof[i] = 0;
			temp_back[i] = 0;
			temp_right[i] = 0;
			temp_left[i] = 0;
			shot_stop[i] = 0;
		}
		is_space = false;
	}

	void Cuzi::LoadBitmap() {
		for (int i = 0; i < 100; i++) {
			shot_back[i].LoadBitmap("RES/shot_up_down.bmp", RGB(255, 255, 255));
			shot_infrontof[i].LoadBitmap("RES/shot_up_down.bmp", RGB(255, 255, 255));
			shot_left[i].LoadBitmap("RES/shot_right_left.bmp", RGB(255, 255, 255));
			shot_right[i].LoadBitmap("RES/shot_right_left.bmp", RGB(255, 255, 255));
		}
	}

	void Cuzi::Getmapaddress(Cmap *m) {
		map = m;
	}

	void Cuzi::shot_OnMove() {
		count++;
		if (is_space) {
			if (count >= 3) {
				if (space == 0)
					space = 1;
				if (bullet == 100) {
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
				}
				if (back == 1 && infrontof1 == 0 && right == 0 && left == 0) {
					shot_back[bullet].SetTopLeft(gunx_down, guny_down);
					shot_back[bullet].ShowBitmap();
					temp_back[bullet] = 1;
					temp_guny[bullet] = guny_down;
					temp_gunx[bullet] = gunx_down;
				}
				if (right == 1 && back == 0 && infrontof1 == 0 && left == 0) {
					shot_right[bullet].SetTopLeft(gunx_right, guny_right);
					shot_right[bullet].ShowBitmap();
					temp_right[bullet] = 1;
					temp_guny[bullet] = guny_right;
					temp_gunx[bullet] = gunx_right;
				}
				if (left == 1 && right == 0 && infrontof1 == 0 && right == 0) {
					shot_left[bullet].SetTopLeft(gunx_left, guny_left);
					shot_left[bullet].ShowBitmap();
					temp_left[bullet] = 1;
					temp_guny[bullet] = guny_left;
					temp_gunx[bullet] = gunx_left;
				}
				bullet++;
				count = 0;
			}
		}
	}
	
	void Cuzi::shot_OnMove2() {
		if (isMovingright && isMovingleft == false && isMovingup == false && isMovingdown == false) {
			if (gunx_up == 330 || gunx_down == 300 || gunx_right == 330 || gunx_left == 300) {
				for (int i = 0; i < 100; i++) {
					if (temp_bullet[i] != 0 || temp_infrontof[i] != 0 || temp_back[i] != 0 || temp_left[i] != 0) {
						temp_gunx[i] -= 10;
					}
				}
			}
		}
		if (isMovingleft && isMovingright == false && isMovingup == false && isMovingdown == false) {
			if (gunx_up == 330 || gunx_down == 300 || gunx_right == 330 || gunx_left == 300) {
				for (int i = 0; i < 100; i++) {
					if (temp_bullet[i] != 0 || temp_infrontof[i] != 0 || temp_back[i] != 0 || temp_right[i] != 0) {
						temp_gunx[i] += 10;
					}
				}
			}
		}
		if (isMovingup && isMovingright == false && isMovingleft == false && isMovingdown == false) {
			if (guny_up == 300 || guny_down == 330 || guny_right == 330 || guny_left == 330) {
				for (int i = 0; i < 100; i++) {
					if (temp_right[i] != 0 || temp_left[i] != 0 || temp_back[i] != 0) {
						temp_guny[i] += 10;
					}
				}
			}
		}
		if (isMovingdown && isMovingright == false && isMovingup == false && isMovingleft == false) {
			if (guny_up == 300 || guny_down == 330 || guny_right == 330 || guny_left == 330) {
				for (int i = 0; i < 100; i++) {
					if (temp_right[i] != 0 || temp_left[i] != 0 || temp_infrontof[i] != 0) {
						temp_guny[i] -= 10;
					}
				}
			}
		}
		if (space != 0) {
			int total_bullet = 0;
			for (int i = 0; i < 100; i++) {
				if (temp_infrontof[i] == 1) {
					if (temp_guny[i] >= (guny_up - 300) && map->isObject(temp_gunx[i], temp_guny[i] - 1) && shot_stop[i] == 0) {
						temp_guny[i] -= 30;
						shot_infrontof[i].SetTopLeft(temp_gunx[i], temp_guny[i]);
						//shot_back[0].ShowBitmap();
					}
					else {
						temp_gunx[i] = 0;
						temp_guny[i] = 0;
						temp_infrontof[i] = 0;
					}
				}
				if (temp_back[i] == 1) {
					if (temp_guny[i] <= (guny_down + 300) && map->isObject(temp_gunx[i], temp_guny[i] + 30) && shot_stop[i] == 0) {
						temp_guny[i] += 30;
						shot_back[i].SetTopLeft(temp_gunx[i], temp_guny[i]);
						//shot_back[0].ShowBitmap();
					}
					else {
						temp_gunx[i] = 0;
						temp_guny[i] = 0;
						temp_back[i] = 0;
					}
				}
				if (temp_right[i] == 1) {
					if (temp_gunx[i] <= (gunx_right + 300) && map->isObject(temp_gunx[i] + 30, temp_guny[i]) && shot_stop[i] == 0) {
						temp_gunx[i] += 30;
						shot_right[i].SetTopLeft(temp_gunx[i], temp_guny[i]);
						//shot_back[0].ShowBitmap();
					}
					else {
						temp_gunx[i] = 0;
						temp_guny[i] = 0;
						temp_right[i] = 0;
					}
				}
				if (temp_left[i] == 1) {
					if (temp_gunx[i] >= (gunx_left - 300) && map->isObject(temp_gunx[i] - 30, temp_guny[i]) && shot_stop[i] == 0) {
						temp_gunx[i] -= 30;
						shot_left[i].SetTopLeft(temp_gunx[i], temp_guny[i]);
						//shot_back[0].ShowBitmap();
					}
					else {
						temp_gunx[i] = 0;
						temp_guny[i] = 0;
						temp_left[i] = 0;
					}
				}
				total_bullet += temp_infrontof[i] + temp_back[i] + temp_right[i] + temp_left[i];
			}
			if (total_bullet == 0) {
				space = 0;
			}
		}
	}

	void Cuzi::Setspace(bool flag)
	{
		is_space = flag;
	}

	void Cuzi::shot_OnShow() {
		for (int i = 0; i < 100; i++) {
			if (temp_infrontof[i] == 1)
				shot_infrontof[i].ShowBitmap();
			if (temp_back[i] == 1)
				shot_back[i].ShowBitmap();
			if (temp_right[i] == 1)
				shot_right[i].ShowBitmap();
			if (temp_left[i] == 1)
				shot_left[i].ShowBitmap();
		}
	}

}