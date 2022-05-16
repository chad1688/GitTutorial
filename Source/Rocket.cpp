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
		for (int i = 0; i < 40; i++) {
			temp_bullet[i] = 0;
			temp_infrontof[i] = 0;
			temp_back[i] = 0;
			temp_right[i] = 0;
			temp_left[i] = 0;
		}
		is_space = false;
	}

	void CRocket::LoadBitmap() {
		boom.LoadBitmap("RES/566.bmp", RGB(255, 255, 255));
		for (int i = 0; i < 40; i++) {
			shot_back[i].LoadBitmap("RES/back.bmp");
			shot_infrontof[i].LoadBitmap("RES/inforntof.bmp");
			shot_left[i].LoadBitmap("RES/left.bmp");
			shot_right[i].LoadBitmap("RES/right.bmp");
		}
	}

	void CRocket::Getmapaddress(Cmap *m) {
		map = m;
	}

	void CRocket::shot_OnMove() {
		if (is_space) {
			if (space == 0) {
				if (bullet == 40) {
					bullet = 0;
					empty_bullet = 1;
				}
				if (infrontof1 == 1 && back == 0 && right == 0 && left == 0) {
					shot_infrontof[bullet].SetTopLeft(gunx, guny);
					shot_infrontof[bullet].ShowBitmap();
					temp_infrontof[bullet] = 1;
				}
				if (back == 1 && infrontof1 == 0 && right == 0 && left == 0) {
					shot_back[bullet].SetTopLeft(gunx, guny);
					shot_back[bullet].ShowBitmap();
					temp_back[bullet] = 1;
				}
				if (right == 1 && back == 0 && infrontof1 == 0 && left == 0) {
					shot_right[bullet].SetTopLeft(gunx, guny);
					shot_right[bullet].ShowBitmap();
					temp_right[bullet] = 1;
				}
				if (left == 1 && right == 0 && infrontof1 == 0 && right == 0) {
					shot_left[bullet].SetTopLeft(gunx, guny);
					shot_left[bullet].ShowBitmap();
					temp_left[bullet] = 1;
				}
				temp_guny[bullet] = guny;
				temp_gunx[bullet] = gunx;
				bullet++;
			}
			if (space == 0)
				space = 1;
			//my_bullet[1] -= 1;
		}
	}

	void CRocket::shot_OnMove2() {
		if (isMovingright) {
			if (gunx == 330) {
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
		if (isMovingleft) {
			if (gunx == 330) {
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
		if (isMovingup) {
			if (guny == 300) {
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
		if (isMovingdown) {
			if (guny == 300) {
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
					if (temp_guny[i] >= (guny - 192) && map->isObject(temp_gunx[i], temp_guny[i] - 1)) {
						temp_guny[i] -= 10;
						shot_infrontof[i].SetTopLeft(temp_gunx[i], temp_guny[i]);
						//shot_back[0].ShowBitmap();
					}
					else {
						count = 0;
						boomx = temp_gunx[i] - 34;
						boomy = temp_guny[i] - 18;
						show = 1;
						temp_infrontof[i] = 0;
					}
				}
				if (temp_back[i] == 1) {
					if (temp_guny[i] <= (guny + 192) && map->isObject(temp_gunx[i], temp_guny[i] + 30)) {
						temp_guny[i] += 10;
						shot_back[i].SetTopLeft(temp_gunx[i], temp_guny[i]);
						//shot_back[0].ShowBitmap();
					}
					else {
						count = 0;
						boomx = temp_gunx[i] - 34;
						boomy = temp_guny[i];
						show = 1;
						temp_back[i] = 0;
					}
				}
				if (temp_right[i] == 1) {
					if (temp_gunx[i] <= (gunx + 192) && map->isObject(temp_gunx[i] + 30, temp_guny[i])) {
						temp_gunx[i] += 10;
						shot_right[i].SetTopLeft(temp_gunx[i], temp_guny[i]);
						//shot_back[0].ShowBitmap();
					}
					else {
						count = 0;
						boomx = temp_gunx[i] - 34;
						boomy = temp_guny[i] - 18;
						show = 1;
						temp_right[i] = 0;
					}
				}
				if (temp_left[i] == 1) {
					if (temp_gunx[i] >= (gunx - 192) && map->isObject(temp_gunx[i] - 30, temp_guny[i])) {
						temp_gunx[i] -= 10;
						shot_left[i].SetTopLeft(temp_gunx[i], temp_guny[i]);
						//shot_back[0].ShowBitmap();
					}
					else {
						count = 0;
						boomx = temp_gunx[i] - 34;
						boomy = temp_guny[i] - 18;
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