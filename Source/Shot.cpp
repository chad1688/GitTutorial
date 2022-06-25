#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "string"
#include "vector"
#include "CPeople.h"
#include "Shot.h"
#include "map.h"

namespace game_framework {
	Cshot::Cshot() {
		space = 0;
		temp_infrontof = 0;
		temp_back = 0;
		temp_left = 0;
		temp_right = 0;
		temp_bullet = 0;
		shot_stop = 0;
		count = 15;
		is_space = false;
	}
	void Cshot::Getmapaddress(Cmap *m) {
		map = m;
	}

	void Cshot::LoadBitmap() {
		shot_back.LoadBitmap("RES/shot_up_down.bmp", RGB(255, 255, 255));
		shot_infrontof.LoadBitmap("RES/shot_up_down.bmp", RGB(255, 255, 255));
		shot_left.LoadBitmap("RES/shot_right_left.bmp", RGB(255, 255, 255));
		shot_right.LoadBitmap("RES/shot_right_left.bmp", RGB(255, 255, 255));

	}

	void Cshot::shot_OnMove() {
		count++;
		if (is_space) {
			if (count >= 20) {
				if (space == 0)
					space = 1;
				shot_stop = 0;
				if (infrontof1 == 1 && back == 0 && right == 0 && left == 0 && temp_bullet == 0) {
					shot_infrontof.SetTopLeft(gunx_up, guny_up);
					temp_guny = guny_up;
					temp_gunx = gunx_up;
					temp_infrontof = 1;
					temp_bullet = 1;
				}
				if (infrontof1 == 0 && back == 1 && right == 0 && left == 0 && temp_bullet == 0) {
					shot_back.SetTopLeft(gunx_down, guny_down);
					temp_guny = guny_down;
					temp_gunx = gunx_down;
					temp_back = 1;
					temp_bullet = 1;
				}
				if (infrontof1 == 0 && back == 0 && right == 1 && left == 0 && temp_bullet == 0) {
					shot_right.SetTopLeft(gunx_right, guny_right);
					temp_guny = guny_right;
					temp_gunx = gunx_right;
					temp_right = 1;
					temp_bullet = 1;
				}
				if (infrontof1 == 0 && back == 0 && right == 0 && left == 1 && temp_bullet == 0) {
					shot_left.SetTopLeft(gunx_left, guny_left);
					temp_guny = guny_left;
					temp_gunx = gunx_left;
					temp_left = 1;
					temp_bullet = 1;
				}
				count = 0;
			}
		}
	}

	void Cshot::shot_OnMove2() {
		if (isMovingright && isMovingleft == false && isMovingup == false && isMovingdown == false) {
			if (gunx_up == 330 || gunx_down == 300 || gunx_right == 330 || gunx_left == 300) {
				if (temp_infrontof != 0 || temp_back != 0 || temp_left != 0) {
					temp_gunx -= 10;
				}
			}
		}
		if (isMovingleft && isMovingright == false && isMovingup == false && isMovingdown == false) {
			if (gunx_up == 330 || gunx_down == 300 || gunx_right == 330 || gunx_left == 300) {
				if (temp_infrontof != 0 || temp_back != 0 || temp_right != 0) {
					temp_gunx += 10;
				}
			}
		}
		if (isMovingup && isMovingright == false && isMovingleft == false && isMovingdown == false) {
			if (guny_up == 300 || guny_down == 330 || guny_right == 330 || guny_left == 330) {
				if (temp_right != 0 || temp_back != 0 || temp_left != 0) {
					temp_guny += 10;
				}
			}
		}
		if (isMovingdown && isMovingright == false && isMovingup == false && isMovingleft == false) {
			if (guny_up == 300 || guny_down == 330 || guny_right == 330 || guny_left == 330) {
				if (temp_infrontof != 0 || temp_right != 0 || temp_left != 0) {
					temp_guny -= 10;
				}
			}
		}
		if (space != 0) {
			if (temp_infrontof == 1) {
				if (temp_guny >= (guny_up - 300) && map->isObject(temp_gunx, temp_guny - 1) && shot_stop == 0) {
					temp_guny -= 50;
					shot_infrontof.SetTopLeft(temp_gunx, temp_guny);
				}
				else {
					temp_gunx = 0;
					temp_guny = 0;
					space = 0;
					temp_infrontof = 0;
					temp_bullet = 0;
				}
			}
			if (temp_back == 1) {
				if (temp_guny <= (guny_down + 300) && map->isObject(temp_gunx, temp_guny + 30) && shot_stop == 0) {
					temp_guny += 50;
					shot_back.SetTopLeft(temp_gunx, temp_guny);
				}
				else {
					temp_gunx = 0;
					temp_guny = 0;
					space = 0;
					temp_back = 0;
					temp_bullet = 0;
				}
			}
			if (temp_right == 1) {
				if (temp_gunx <= (gunx_right + 300) && map->isObject(temp_gunx + 30, temp_guny) && shot_stop == 0) {
					temp_gunx += 50;
					shot_right.SetTopLeft(temp_gunx, temp_guny);
				}
				else {
					temp_gunx = 0;
					temp_guny = 0;
					space = 0;
					temp_right = 0;
					temp_bullet = 0;
				}
			}
			if (temp_left == 1) {
				if (temp_gunx >= (gunx_left - 300) && map->isObject(temp_gunx - 30, temp_guny) && shot_stop == 0) {
					temp_gunx -= 50;
					shot_left.SetTopLeft(temp_gunx, temp_guny);
				}
				else {
					temp_gunx = 0;
					temp_guny = 0;
					space = 0;
					temp_left = 0;
					temp_bullet = 0;
				}
			}
		}
	}

	void Cshot::Setspace(bool flag)
	{
		is_space = flag;
	}

	void Cshot::shot_OnShow() {
		if (temp_infrontof == 1)
			shot_infrontof.ShowBitmap();
		if (temp_back == 1)
			shot_back.ShowBitmap();
		if (temp_right == 1)
			shot_right.ShowBitmap();
		if (temp_left == 1)
			shot_left.ShowBitmap();
	}

}