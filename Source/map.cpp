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
		for (int i = 0; i < 4; i++)
			temp3[i] = 0;
	}

	void Cmap::LoadBitmap() {
		this->map.LoadBitmap("./RES/background.bmp",RGB(0,0,0));
		this->wall.LoadBitmap("./RES/70.bmp", RGB(255, 255, 255));
		this->wall2.LoadBitmap("./RES/76.bmp", RGB(255, 255, 255));
		this->wall3.LoadBitmap("./RES/70_left.bmp", RGB(255, 255, 255));
		this->wall4.LoadBitmap("./RES/70_right.bmp", RGB(255, 255, 255));
		this->wall5.LoadBitmap("./RES/129.bmp", RGB(255, 255, 255));
		this->wall6.LoadBitmap("./RES/100.bmp", RGB(255, 255, 255));
		for(int i = 0;i<4;i++)
			this->new_gun[i].LoadBitmap("./RES/643.bmp", RGB(0, 0, 0));
		
	}

	bool Cmap::isObject(int people_x,int people_y) {
		if (choose_map == 0)
		{
			if (all_map[((-y) + people_y) / 110][((-x) + people_x + MW2) / 80] <= 0 || all_map[((-y) + people_y) / 110][((-x) + people_x + MW2) / 80] > 5) {
				return true;
			}
			return false;
		}
		else if (choose_map == 1)
		{
			if (all_map2[((-y) + people_y) / 110][((-x) + people_x + MW2) / 80] <= 0 || all_map2[((-y) + people_y) / 110][((-x) + people_x + MW2) / 80] > 5) {
				return true;
			}
			return false;
		}
		else
		{
			if (all_map3[((-y) + people_y) / 110][((-x) + people_x + MW2) / 80] <= 0 || all_map2[((-y) + people_y) / 110][((-x) + people_x + MW2) / 80] > 5) {
				return true;
			}
			return false;
		}
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
		if (choose_map == 0)
		{
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
		else if (choose_map == 1)
		{
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 22; j++) {
					if (all_map2[i][j] > 5) {
						if (gun_index >= 4)
							gun_index = 0;
						redbox_x[gun_index] = MW * j - MW2;
						//TRACE("%d", redbox_x[1]);
						redbox_y[gun_index] = MH * i;
						gun_index++;
					}
				}
			}
		}
		else if (choose_map == 2)
		{
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 22; j++) {
					if (all_map3[i][j] > 5) {
						if (gun_index >= 4)
							gun_index = 0;
						redbox_x[gun_index] = MW * j - MW2;
						//TRACE("%d", redbox_x[1]);
						redbox_y[gun_index] = MH * i;
						gun_index++;
					}
				}
			}
		}
	}

	void Cmap::OnMove_redbox_live() 
	{
		if (choose_map == 0)
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
		else if (choose_map == 1 || choose_map == 2)
		{
			for (int i = 0; i < 4; i++) {
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
	}

	void Cmap::OnShow() {
		if (choose_map == 0)
		{
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
		else if (choose_map == 1)
		{
			this->map.SetTopLeft(x, y);
			this->map.ShowBitmap();
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 22; j++) {
					if (all_map2[i][j] == 1) {
						this->wall5.SetTopLeft(x + MW * j - MW2, y + MH * i);
						this->wall5.ShowBitmap();
					}
					if (all_map2[i][j] == 6 && redbox_appear3[0] == 0) {
						this->new_gun[0].SetTopLeft(x + MW * j - MW2, y + MH * i);
						this->new_gun[0].ShowBitmap();
					}
					if (all_map2[i][j] == 7 && redbox_appear3[1] == 0) {
						this->new_gun[1].SetTopLeft(x + MW * j - MW2, y + MH * i);
						this->new_gun[1].ShowBitmap();
					}
					if (all_map2[i][j] == 9 && redbox_appear3[2] == 0) {
						this->new_gun[2].SetTopLeft(x + MW * j - MW2, y + MH * i);
						this->new_gun[2].ShowBitmap();
					}
					if (all_map2[i][j] == 8 && redbox_appear3[3] == 0) {
						this->new_gun[3].SetTopLeft(x + MW * j - MW2, y + MH * i);
						this->new_gun[3].ShowBitmap();
					}
				}
			}
		}
		else if (choose_map == 2)
		{
			this->map.SetTopLeft(x, y);
			this->map.ShowBitmap();
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 22; j++) {
					if (all_map3[i][j] == 1) {
						this->wall6.SetTopLeft(x + MW * j - MW2, y + MH * i);
						this->wall6.ShowBitmap();
					}
					if (all_map3[i][j] == 6 && redbox_appear3[0] == 0) {
						this->new_gun[0].SetTopLeft(x + MW * j - MW2, y + MH * i);
						this->new_gun[0].ShowBitmap();
					}
					if (all_map3[i][j] == 7 && redbox_appear3[1] == 0) {
						this->new_gun[1].SetTopLeft(x + MW * j - MW2, y + MH * i);
						this->new_gun[1].ShowBitmap();
					}
					if (all_map3[i][j] == 9 && redbox_appear3[2] == 0) {
						this->new_gun[2].SetTopLeft(x + MW * j - MW2, y + MH * i);
						this->new_gun[2].ShowBitmap();
					}
					if (all_map3[i][j] == 8 && redbox_appear3[3] == 0) {
						this->new_gun[3].SetTopLeft(x + MW * j - MW2, y + MH * i);
						this->new_gun[3].ShowBitmap();
					}
				}
			}
		}
	}
}