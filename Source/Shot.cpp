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
		count = 15;
		is_space = false;
	}
	void Cshot::Getmapaddress(Cmap *m) {
		map = m;
	}

	void Cshot::LoadBitmap() {
		shot_back.LoadBitmap("RES/back.bmp");
		shot_infrontof.LoadBitmap("RES/inforntof.bmp");
		shot_left.LoadBitmap("RES/left.bmp");
		shot_right.LoadBitmap("RES/right.bmp");
	}

	void Cshot::shot_OnMove() {
		count++;
		if (is_space) {
			if (count >= 15) {
				if (space == 0)
					space = 1;
				if (infrontof1 == 1 && back == 0 && right == 0 && left == 0 && temp_bullet == 0) {
					shot_infrontof.SetTopLeft(gunx, guny);
					temp_guny = guny;
					temp_gunx = gunx;
					temp_infrontof = 1;
					temp_bullet = 1;
				}
				if (infrontof1 == 0 && back == 1 && right == 0 && left == 0 && temp_bullet == 0) {
					shot_back.SetTopLeft(gunx, guny);
					temp_guny = guny;
					temp_gunx = gunx;
					temp_back = 1;
					temp_bullet = 1;
				}
				if (infrontof1 == 0 && back == 0 && right == 1 && left == 0 && temp_bullet == 0) {
					shot_right.SetTopLeft(gunx, guny);
					temp_guny = guny;
					temp_gunx = gunx;
					temp_right = 1;
					temp_bullet = 1;
				}
				if (infrontof1 == 0 && back == 0 && right == 0 && left == 1 && temp_bullet == 0) {
					shot_left.SetTopLeft(gunx, guny);
					temp_guny = guny;
					temp_gunx = gunx;
					temp_left = 1;
					temp_bullet = 1;
				}
				count = 0;
			}
		}
	}

	void Cshot::shot_OnMove2() {
		if (isMovingright) {
			if (gunx == 330) {
				if (temp_infrontof != 0 || temp_back != 0 || temp_left != 0) {
					temp_gunx -= 10;
				}
			}
		}
		if (isMovingleft) {
			if (gunx == 330) {
				if (temp_infrontof != 0 || temp_back != 0 || temp_right != 0) {
					temp_gunx += 10;
				}
			}
		}
		if (isMovingup) {
			if (guny == 300) {
				if (temp_right != 0 || temp_back != 0 || temp_left != 0) {
					temp_guny += 10;
				}
			}
		}
		if (isMovingdown) {
			if (guny == 300) {
				if (temp_infrontof != 0 || temp_right != 0 || temp_left != 0) {
					temp_guny -= 10;
				}
			}
		}
		if (space != 0) {
			if (temp_infrontof == 1) {
				if (temp_guny >= (guny - 192) && map->isObject(temp_gunx, temp_guny - 1)) {
					temp_guny -= 50;
					shot_infrontof.SetTopLeft(temp_gunx, temp_guny);
				}
				else {
					space = 0;
					temp_infrontof = 0;
					temp_bullet = 0;
				}
			}
			if (temp_back == 1) {
				if (temp_guny <= (guny + 192) && map->isObject(temp_gunx, temp_guny + 30)) {
					temp_guny += 50;
					shot_back.SetTopLeft(temp_gunx, temp_guny);
				}
				else {
					space = 0;
					temp_back = 0;
					temp_bullet = 0;
				}
			}
			if (temp_right == 1) {
				if (temp_gunx <= (gunx + 192) && map->isObject(temp_gunx + 30, temp_guny)) {
					temp_gunx += 50;
					shot_right.SetTopLeft(temp_gunx, temp_guny);
				}
				else {
					space = 0;
					temp_right = 0;
					temp_bullet = 0;
				}
			}
			if (temp_left == 1) {
				if (temp_gunx >= (gunx - 192) && map->isObject(temp_gunx - 30, temp_guny)) {
					temp_gunx -= 50;
					shot_left.SetTopLeft(temp_gunx, temp_guny);
				}
				else {
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