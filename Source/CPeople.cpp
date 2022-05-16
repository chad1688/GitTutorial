#include "stdafx.h"
#include "Resource.h"
#include <string>
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CPeople.h"
#include "map.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CPeople::CPeople()
	{
		Initialize();
	}

	void CPeople::Getmapaddress(Cmap *m) 
	{
		map = m;
	}

	int CPeople::GetX1()
	{
		return x;
	}

	int CPeople::GetY1()
	{
		return y;
	}

	int CPeople::GetX2()
	{
		return x + animation_left.Width();
	}

	int CPeople::GetY2()
	{
		return y + animation_left.Height();
	}



	bool CPeople::GetisMovingup() {
		return isMovingUp;
	}

	bool CPeople::GetisMovingdown() {
		return isMovingDown;
	}

	bool CPeople::GetisMovingright() {
		return isMovingRight;
	}

	bool CPeople::GetisMovingleft() {
		return isMovingLeft;
	}

	void CPeople::Initialize()
	{
		const int X_POS = 300;
		const int Y_POS = 300;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = is_space = false;
		blood_index = 0;
		monster_touch = false;
		count = 0;
		for (int i = 0; i < 2; i++)
			red_box_appear3[i] = 0;
		add_arms = 0;
	}

	void CPeople::LoadBitmap() {
		start_infrontof.LoadBitmap("RES/player01_up01.bmp", RGB(255, 255, 255));
		start_left.LoadBitmap("RES/player01_left01.bmp", RGB(255, 255, 255));
		start_right.LoadBitmap("RES/player01_right01.bmp", RGB(255, 255, 255));
		start_back.LoadBitmap("RES/player01_down01.bmp", RGB(255, 255, 255));
		for (int i = 38; i < 41; i++) {
			char *change;
			std::string temp_string = "RES/" + to_string(i) + ".bmp";
			change = &temp_string[0];
			blood[i-38].LoadBitmap(change, RGB(255, 255, 255));
		}
	}

	void CPeople::LoadAnimation() {
		animation_left.AddBitmap("RES/player01_left02.bmp", RGB(255, 255, 255));
		animation_left.AddBitmap("RES/player01_left03.bmp", RGB(255, 255, 255));
		animation_infrontof.AddBitmap("RES/player01_up02.bmp", RGB(255, 255, 255));
		animation_infrontof.AddBitmap("RES/player01_up03.bmp", RGB(255, 255, 255));
		animation_right.AddBitmap("RES/player01_right02.bmp", RGB(255, 255, 255));
		animation_right.AddBitmap("RES/player01_right03.bmp", RGB(255, 255, 255));
		animation_back.AddBitmap("RES/player01_down02.bmp", RGB(255, 255, 255));
		animation_back.AddBitmap("RES/player01_down03.bmp", RGB(255, 255, 255));
		//animation_back.AddBitmap("RES/back3.bmp", RGB(184, 184, 184));
	}

	void CPeople::blood_OnMove()
	{
		if (monster_touch) {
			count++;
			timer = 0;
			if (count > 2) {
				if (blood_index < 2)
					blood_index += 1;
				count = 0;
			}
		}
		else {
			if ((timer % 150) == 0 || (timer % 180) == 0) {
				if(blood_index>0)
					blood_index -= 1;
			}
		}
		blood[blood_index].SetTopLeft(x+10, y - 9);
	}

	void CPeople::people_touch_redbox() 
	{
		for (int i = 0; i < 2; i++) {
			if ((-map->x) + x >= map->redbox_x[i] && (-map->x) + x <= map->redbox_x[i] + 35 && (-map->y) + y >= map->redbox_y[i] && (-map->y) + y <= map->redbox_y[i] + 33) {
				if(red_box_appear3[i] == 0)
					add_arms = 1;
				red_box_appear3[i] = 1;
			}
			else if ((-map->x) + x + animation_left.Width() >= map->redbox_x[i] && (-map->x) + x + animation_left.Width() <= map->redbox_x[i] + 35 && (-map->y) + y >= map->redbox_y[i] && (-map->y) + y <= map->redbox_y[i] + 33) {
				if (red_box_appear3[i] == 0)
					add_arms = 1;
				red_box_appear3[i] = 1;
				
			}
			else if ((-map->x) + x >= map->redbox_x[i] && (-map->x) + x <= map->redbox_x[i] + 35 && (-map->y) + y + animation_left.Height() >= map->redbox_y[i] && (-map->y) + y + animation_left.Height() <= map->redbox_y[i] + 33) {
				if (red_box_appear3[i] == 0)
					add_arms = 1;
				red_box_appear3[i] = 1;
			}
			else if ((-map->x) + x + animation_left.Width() >= map->redbox_x[i] && (-map->x) + x + animation_left.Width() <= map->redbox_x[i] + 35 && (-map->y) + y + animation_left.Height() >= map->redbox_y[i] && (-map->y) + y + animation_left.Height() <= map->redbox_y[i] + 33) {
				if (red_box_appear3[i] == 0)
					add_arms = 1;
				red_box_appear3[i] = 1;
				
			}
			else if ((-map->x) + x + animation_left.Width() >= map->redbox_x[i] && (-map->x) + x + animation_left.Width() <= map->redbox_x[i] + 35 && (-map->y) + ((y + animation_left.Height() + y)/2) >= map->redbox_y[i] && (-map->y) + ((y + animation_left.Height() + y)/2) <= map->redbox_y[i] + 33) {
				if (red_box_appear3[i] == 0)
					add_arms = 1;
				red_box_appear3[i] = 1;
			}
			else if ((-map->x) + x >= map->redbox_x[i] && (-map->x) + x <= map->redbox_x[i] + 35 && (-map->y) + ((y + animation_left.Height() + y) / 2) >= map->redbox_y[i] && (-map->y) + ((y + animation_left.Height() + y) / 2) <= map->redbox_y[i] + 33) {
				if (red_box_appear3[i] == 0)
					add_arms = 1;
				red_box_appear3[i] = 1;
			}
			else if ((-map->x) + ((x + animation_left.Width() + x) / 2) >= map->redbox_x[i] && (-map->x) + ((x + animation_left.Width() + x) / 2) <= map->redbox_x[i] + 35 && (-map->y) + y >= map->redbox_y[i] && (-map->y) + y <= map->redbox_y[i] + 33) {
				if (red_box_appear3[i] == 0)
					add_arms = 1;
				red_box_appear3[i] = 1;
			}
			else if ((-map->x) + ((x + animation_left.Width() + x) / 2) >= map->redbox_x[i] && (-map->x) + ((x + animation_left.Width() + x) / 2) <= map->redbox_x[i] + 35 && (-map->y) + y + animation_left.Height() >= map->redbox_y[i] && (-map->y) + y + animation_left.Height() <= map->redbox_y[i] + 33) {
				if (red_box_appear3[i] == 0)
					add_arms = 1;
				red_box_appear3[i] = 1;
			}
		}
	}

	void CPeople::OnMove()
	{
		const int STEP_SIZE = 5;
		//TRACE("%d", (-map->x) + x);
		if (isMovingLeft) {
			if (map->x < 0) {
				if (x > 300) {
					x -= STEP_SIZE;
					animation_left.OnMove();
				}
				else {
					map->OnMove_right();
					animation_left.OnMove();
				}
			}
			else {
				if (x == 0) {
					x = STEP_SIZE;
					animation_left.OnMove();
				}
				else {
					x -= STEP_SIZE;
					animation_left.OnMove();
				}
			}
		}
		if (isMovingRight) {
			if (map->x > -1045) {
				if (x < 300) {
					x += STEP_SIZE;
					animation_right.OnMove();
				}
				else {
					map->OnMove_left();
					animation_right.OnMove();
				}
			}
			else {
				if (x == 605) {
					animation_right.OnMove();
				}
				else {
					x += STEP_SIZE;
					animation_right.OnMove();
				}
			}
		}
		if (isMovingUp) {
			if (map->y < 0) {
				if (y > 300) {
					y -= STEP_SIZE;
					animation_infrontof.OnMove();
				}
				else {
					map->OnMove_down();
					animation_infrontof.OnMove();
				}
			}
			else {
				if (y == 0) {
					y = STEP_SIZE;
					animation_infrontof.OnMove();
				}
				else {
					y -= STEP_SIZE;
					animation_infrontof.OnMove();
				}
			}
		}
		if (isMovingDown) {
			if (map->y > -610) {
				if (y < 300) {
					y += STEP_SIZE;
					animation_back.OnMove();
				}
				else {
					map->OnMove_up();
					animation_back.OnMove();
				}
			}
			else {
				if (y == 445) {
					animation_back.OnMove();
				}
				else {
					y += STEP_SIZE;
					animation_back.OnMove();
				}
			}

		}
		
		
	}

	void CPeople::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CPeople::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CPeople::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CPeople::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}
	

	void CPeople::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void CPeople::Setmonser_touch(bool flag)
	{
		monster_touch = flag;
	}

	void CPeople::OnShow()
	{
		if (infrontof1 == 1) {
			start_infrontof.SetTopLeft(x, y);
			start_infrontof.ShowBitmap();
		}
		if (left == 1) {
			start_left.SetTopLeft(x, y);
			start_left.ShowBitmap();
		}
		if (right == 1) {
			start_right.SetTopLeft(x, y);
			start_right.ShowBitmap();
		}
		if (back == 1) {
			start_back.SetTopLeft(x, y);
			start_back.ShowBitmap();
		}
		if (isMovingLeft) {
			left = 1;
			infrontof1 = 0;
			back = 0;
			right = 0;
			animation_left.SetTopLeft(x, y);
			animation_left.OnShow();
		}
		if (isMovingUp) {
			infrontof1 = 1;
			left = 0;
			right = 0;
			back = 0;
			animation_infrontof.SetTopLeft(x, y);
			animation_infrontof.OnShow();
		}
		if (isMovingRight) {
			infrontof1 = 0;
			left = 0;
			right = 1;
			back = 0;
			animation_right.SetTopLeft(x, y);
			animation_right.OnShow();
		}
		if (isMovingDown) {
			infrontof1 = 0;
			left = 0;
			right = 0;
			back = 1;
			animation_back.SetTopLeft(x, y);
			animation_back.OnShow();
		}
		blood[blood_index].ShowBitmap();
	}
}