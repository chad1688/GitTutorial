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
		for (int i = 0; i < 4; i++)
			red_box_appear3[i] = 0;
		add_arms = 0;
		pickup = false;
		Map_Moving_up = false;
		Map_Moving_right = false;
		Map_Moving_left = false;
		Map_Moving_down = false;
		die = false;
		stop = 0;
		stop2 = 0;
		hit = 0;
		stop3 = 0;
		stop4 = 0;
		count_hit = 0;
	}

	void CPeople::LoadBitmap() {
		start_infrontof.LoadBitmap("RES/people_up1.bmp", RGB(255, 255, 255));
		start_left.LoadBitmap("RES/people_left1.bmp", RGB(255, 255, 255));
		start_right.LoadBitmap("RES/people_right1.bmp", RGB(255, 255, 255));
		start_back.LoadBitmap("RES/people_down1.bmp", RGB(255, 255, 255));
		for (int i = 1; i < 11; i++) {
			char *change;
			std::string temp_string = "RES/blood" + to_string(i) + ".bmp";
			change = &temp_string[0];
			blood[i-1].LoadBitmap(change, RGB(255, 255, 255));
		}
	}

	void CPeople::LoadAnimation() {
		animation_left.AddBitmap("RES/people_left2.bmp", RGB(255, 255, 255));
		animation_left.AddBitmap("RES/people_left3.bmp", RGB(255, 255, 255));
		animation_infrontof.AddBitmap("RES/people_up2.bmp", RGB(255, 255, 255));
		animation_infrontof.AddBitmap("RES/people_up3.bmp", RGB(255, 255, 255));
		animation_right.AddBitmap("RES/people_right2.bmp", RGB(255, 255, 255));
		animation_right.AddBitmap("RES/people_right3.bmp", RGB(255, 255, 255));
		animation_back.AddBitmap("RES/people_down2.bmp", RGB(255, 255, 255));
		animation_back.AddBitmap("RES/people_down3.bmp", RGB(255, 255, 255));
		for (int i = 1; i < 9; i++) {
			char *change;
			std::string temp_string = "RES/die_down" + to_string(i) + ".bmp";
			change = &temp_string[0];
			down_die.AddBitmap(change, RGB(255, 255, 255));
			std::string temp_string2 = "RES/die_up" + to_string(i) + ".bmp";
			change = &temp_string2[0];
			up_die.AddBitmap(change, RGB(255, 255, 255));
			std::string temp_string3 = "RES/die_right" + to_string(i) + ".bmp";
			change = &temp_string3[0];
			right_die.AddBitmap(change, RGB(255, 255, 255));
			std::string temp_string4 = "RES/die_left" + to_string(i) + ".bmp";
			change = &temp_string4[0];
			left_die.AddBitmap(change, RGB(255, 255, 255));
		}
		down_die.AddBitmap("RES/die9.bmp", RGB(255, 255, 255));
		up_die.AddBitmap("RES/die9.bmp", RGB(255, 255, 255));
		right_die.AddBitmap("RES/die9.bmp", RGB(255, 255, 255));
		left_die.AddBitmap("RES/die9.bmp", RGB(255, 255, 255));
		//animation_back.AddBitmap("RES/back3.bmp", RGB(184, 184, 184));
	}

	void CPeople::blood_OnMove()
	{
		timer++;
		if (blood_index == 9)
		{
			die = true;
			if (infrontof1 == 1)
			{
				up_die.SetTopLeft(x, y);
				if (!(up_die.IsFinalBitmap()))
				{
					up_die.OnMove();
				}
			}
			if (back == 1)
			{
				down_die.SetTopLeft(x, y);
				if (!(down_die.IsFinalBitmap()))
				{
					down_die.OnMove();
				}
			}
			if (right == 1)
			{
				right_die.SetTopLeft(x, y);
				if (!(right_die.IsFinalBitmap()))
				{
					right_die.OnMove();
				}
			}
			if (left == 1)
			{
				left_die.SetTopLeft(x, y);
				if (!(left_die.IsFinalBitmap()))
				{
					left_die.OnMove();
				}
			}
		}
		else if (monster_touch) {
			timer = 0;
			if (blood_index < 9)
			{
				blood_index += 1;
			}
		}
		else{
			if(timer >= 150 && (timer % 30) == 0){
				if(blood_index>0)
					blood_index -= 1;
			}
		}
		blood[blood_index].SetTopLeft(x+10, y - 9);
	}

	void CPeople::hit_OnMove()
	{
		count_hit++;
		if (stop3 == 0)
		{
			for (int i = 0; i < large; i++)
			{
				if (hit == 1)
				{
					if ((-map->y) + y + 36 < enemy_y[i] && (-map->y) + y + 36 + 70 >= enemy_y[i] && (((-map->x) + x >= enemy_x[i] && (-map->x) + x <= enemy_x[i] + 60) || ((-map->x) + x + 60 >= enemy_x[i] && (-map->x) + x + 60 <= enemy_x[i] + 60)))
					{
						stop3 = 1;
						break;
						
					}
				}
				if (hit == 2)
				{
					if ((-map->y) + y - 30 > enemy_y[i] && (-map->y) + y - 30 <= enemy_y[i] + 70 && (((-map->x) + x >= enemy_x[i] && (-map->x) + x <= enemy_x[i] + 60) || ((-map->x) + x + 60 >= enemy_x[i] && (-map->x) + x + 60 <= enemy_x[i] + 60)))
					{
						stop3 = 1;
						break;
						
					}
				}
				if (hit == 3)
				{
					if ((-map->x) + x + 36 < enemy_x[i] && (-map->x) + x + 36 + 70 >= enemy_x[i] && (((-map->y) + y >= enemy_y[i] && (-map->y) + y <= enemy_y[i] + 60) || ((-map->y) + y + 60 >= enemy_y[i] && (-map->y) + y + 60 <= enemy_y[i] + 60)))
					{
						stop3 = 1;
						break;
					

					}
				}
				if (hit == 4)
				{
					if ((-map->x) + x - 36 <= enemy_x[i] + 70 && (-map->x) + x - 36 > enemy_x[i] && (((-map->y) + y >= enemy_y[i] && (-map->y) + y <= enemy_y[i] + 60) || ((-map->y) + y + 60 >= enemy_y[i] && (-map->y) + y + 60 <= enemy_y[i] + 60)))
					{
						stop3 = 1;
						break;
					}
				}
			}
		}
		
		if (hit == 1 && stop3 == 0 && stop4 == 0 && die == false)
		{
			if (map->isObject(x, y + 96) && map->isObject(x + 60, y + 96) && ((-map->y) + y + 96) <= 1040)
			{
				stop4 = 1;
				y += 30;
			}
		}
		else if (hit == 2 && stop3 == 0 && stop4 == 0 && die == false)
		{
			if (map->isObject(x, y - 30) && map->isObject(x + 60, y - 30) && ((-map->y) + y - 30) >= 0)
			{
				stop4 = 1;
				y -= 30;
			}
		}
		else if (hit == 3 && stop3 == 0 && stop4 == 0 && die == false)
		{
			if (map->isObject(x + 96, y) && map->isObject(x + 96, y + 60) && ((-map->x) + x + 96) <= 1650)
			{
				stop4 = 1;
				x += 30;
			}
		}
		else if (hit == 4 && stop3 == 0 && stop4 == 0 && die == false)
		{
			if (map->isObject(x - 30, y) && map->isObject(x - 30, y + 60) && ((-map->x) + x - 30) >= 0)
			{
				stop4 = 1;
				x -= 30;
			}
		}


		if (hit != 0)
		{
			if (infrontof1 == 1)
			{
				animation_infrontof.OnMove();
			}
			if (back == 1)
			{
				animation_back.OnMove();
			}
			if (right == 1)
			{
				animation_right.OnMove();
			}
			if (left == 1)
			{
				animation_left.OnMove();
			}
			if (stop2 == 0)
				count_hit = 0;
			stop2 = 1;
		}
		if (count_hit > 15)
		{
			hit = 0;
			stop2 = 0;
			stop3 = 0;
			stop4 = 0;
		}
	}

	void CPeople::people_touch_redbox() 
	{
		if (choose_map == 0)
		{
			for (int i = 0; i < 2; i++) {
				if ((-map->x) + x >= map->redbox_x[i] && (-map->x) + x <= map->redbox_x[i] + 35 && (-map->y) + y >= map->redbox_y[i] && (-map->y) + y <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;
					}
					red_box_appear3[i] = 1;
				}
				else if ((-map->x) + x + animation_left.Width() >= map->redbox_x[i] && (-map->x) + x + animation_left.Width() <= map->redbox_x[i] + 35 && (-map->y) + y >= map->redbox_y[i] && (-map->y) + y <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;
					}
					red_box_appear3[i] = 1;

				}
				else if ((-map->x) + x >= map->redbox_x[i] && (-map->x) + x <= map->redbox_x[i] + 35 && (-map->y) + y + animation_left.Height() >= map->redbox_y[i] && (-map->y) + y + animation_left.Height() <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;
					}
					red_box_appear3[i] = 1;
				}
				else if ((-map->x) + x + animation_left.Width() >= map->redbox_x[i] && (-map->x) + x + animation_left.Width() <= map->redbox_x[i] + 35 && (-map->y) + y + animation_left.Height() >= map->redbox_y[i] && (-map->y) + y + animation_left.Height() <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;
					}
					red_box_appear3[i] = 1;

				}
				else if ((-map->x) + x + animation_left.Width() >= map->redbox_x[i] && (-map->x) + x + animation_left.Width() <= map->redbox_x[i] + 35 && (-map->y) + ((y + animation_left.Height() + y) / 2) >= map->redbox_y[i] && (-map->y) + ((y + animation_left.Height() + y) / 2) <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;
					}
					red_box_appear3[i] = 1;
				}
				else if ((-map->x) + x >= map->redbox_x[i] && (-map->x) + x <= map->redbox_x[i] + 35 && (-map->y) + ((y + animation_left.Height() + y) / 2) >= map->redbox_y[i] && (-map->y) + ((y + animation_left.Height() + y) / 2) <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;
					}
					red_box_appear3[i] = 1;
				}
				else if ((-map->x) + ((x + animation_left.Width() + x) / 2) >= map->redbox_x[i] && (-map->x) + ((x + animation_left.Width() + x) / 2) <= map->redbox_x[i] + 35 && (-map->y) + y >= map->redbox_y[i] && (-map->y) + y <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;
					}
					red_box_appear3[i] = 1;
				}
				else if ((-map->x) + ((x + animation_left.Width() + x) / 2) >= map->redbox_x[i] && (-map->x) + ((x + animation_left.Width() + x) / 2) <= map->redbox_x[i] + 35 && (-map->y) + y + animation_left.Height() >= map->redbox_y[i] && (-map->y) + y + animation_left.Height() <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;
					}
					red_box_appear3[i] = 1;
				}
			}
		}
		else if (choose_map == 1 ||choose_map == 2)
		{
			for (int i = 0; i < 4; i++) {
				if ((-map->x) + x >= map->redbox_x[i] && (-map->x) + x <= map->redbox_x[i] + 35 && (-map->y) + y >= map->redbox_y[i] && (-map->y) + y <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;
					}
					red_box_appear3[i] = 1;
				}
				else if ((-map->x) + x + animation_left.Width() >= map->redbox_x[i] && (-map->x) + x + animation_left.Width() <= map->redbox_x[i] + 35 && (-map->y) + y >= map->redbox_y[i] && (-map->y) + y <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;

					}
					red_box_appear3[i] = 1;

				}
				else if ((-map->x) + x >= map->redbox_x[i] && (-map->x) + x <= map->redbox_x[i] + 35 && (-map->y) + y + animation_left.Height() >= map->redbox_y[i] && (-map->y) + y + animation_left.Height() <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;
					}
					red_box_appear3[i] = 1;
				}
				else if ((-map->x) + x + animation_left.Width() >= map->redbox_x[i] && (-map->x) + x + animation_left.Width() <= map->redbox_x[i] + 35 && (-map->y) + y + animation_left.Height() >= map->redbox_y[i] && (-map->y) + y + animation_left.Height() <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;
					}
					red_box_appear3[i] = 1;

				}
				else if ((-map->x) + x + animation_left.Width() >= map->redbox_x[i] && (-map->x) + x + animation_left.Width() <= map->redbox_x[i] + 35 && (-map->y) + ((y + animation_left.Height() + y) / 2) >= map->redbox_y[i] && (-map->y) + ((y + animation_left.Height() + y) / 2) <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;
					}
					red_box_appear3[i] = 1;
				}
				else if ((-map->x) + x >= map->redbox_x[i] && (-map->x) + x <= map->redbox_x[i] + 35 && (-map->y) + ((y + animation_left.Height() + y) / 2) >= map->redbox_y[i] && (-map->y) + ((y + animation_left.Height() + y) / 2) <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;
					}
					red_box_appear3[i] = 1;
				}
				else if ((-map->x) + ((x + animation_left.Width() + x) / 2) >= map->redbox_x[i] && (-map->x) + ((x + animation_left.Width() + x) / 2) <= map->redbox_x[i] + 35 && (-map->y) + y >= map->redbox_y[i] && (-map->y) + y <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;
					}
					red_box_appear3[i] = 1;
				}
				else if ((-map->x) + ((x + animation_left.Width() + x) / 2) >= map->redbox_x[i] && (-map->x) + ((x + animation_left.Width() + x) / 2) <= map->redbox_x[i] + 35 && (-map->y) + y + animation_left.Height() >= map->redbox_y[i] && (-map->y) + y + animation_left.Height() <= map->redbox_y[i] + 33) {
					if (red_box_appear3[i] == 0)
					{
						add_arms = 1;
						pickup = true;
					}
					red_box_appear3[i] = 1;
				}
			}
		}
		
	}

	void CPeople::OnMove()
	{
		
		const int STEP_SIZE = 5;
		//TRACE("%d %d", (-map->x) + x,enemy_x);
		if (isMovingLeft && isMovingRight == false && isMovingDown == false && isMovingUp == false && hit == 0) {
			stop = 0;
			for (int i = 0; i < large; i++)
			{
				if ((-map->x) + x <= enemy_x[i] + 70 && (-map->x) + x > enemy_x[i] && (((-map->y) + y >= enemy_y[i] && (-map->y) + y <= enemy_y[i] + 60) || ((-map->y) + y + 60 >= enemy_y[i] && (-map->y) + y + 60 <= enemy_y[i] + 60)))
				{
					stop += 1;
				}
			}
			if (map->x < 0) {
				if (stop > 0)
				{
					animation_left.OnMove();
				}
				else if (x > 300) {
					x -= STEP_SIZE;
					animation_left.OnMove();
				}
				else {
					map->OnMove_right();
					animation_left.OnMove();
				}
			}
			else {
				if (x == 0 || stop > 0) {
					animation_left.OnMove();
				}
				else {
					x -= STEP_SIZE;
					animation_left.OnMove();
				}
			}
		}
		if (isMovingRight && isMovingLeft == false && isMovingDown == false && isMovingUp == false && hit == 0) {
			stop = 0;
			for (int i = 0; i < large; i++)
			{
				if ((-map->x) + x < enemy_x[i] && (-map->x) + x + 70 >= enemy_x[i] && (((-map->y) + y >= enemy_y[i] && (-map->y) + y <= enemy_y[i] + 60) || ((-map->y) + y + 60 >= enemy_y[i] && (-map->y) + y + 60 <= enemy_y[i] + 60)))
				{
					stop += 1;
				}
			}
			if (map->x > -1045) {
				if (stop > 0)
				{
					animation_right.OnMove();
				}
				else if (x < 300) 
				{
					x += STEP_SIZE;
					animation_right.OnMove();
				}
				else {
					map->OnMove_left();
					animation_right.OnMove();
				}
			}
			else {
				if (x == 605 || stop > 0)
				{
					animation_right.OnMove();
				}
				else {
					x += STEP_SIZE;
					animation_right.OnMove();
				}
			}
		}
		if (isMovingUp && isMovingDown == false && isMovingLeft == false && isMovingRight == false && hit == 0) {
			stop = 0;
			for (int i = 0; i < large; i++)
			{
				if ((-map->y) + y > enemy_y[i] && (-map->y) + y <= enemy_y[i] + 70 && (((-map->x) + x >= enemy_x[i] && (-map->x) + x <= enemy_x[i] + 60) || ((-map->x) + x + 60 >= enemy_x[i] && (-map->x) + x + 60 <= enemy_x[i] + 60)))
				{
					stop += 1;
				}
			}
			if (map->y < 0) {
				if (stop > 0)
				{
					animation_infrontof.OnMove();
				}
				else if (y > 300) {
					y -= STEP_SIZE;
					animation_infrontof.OnMove();
				}
				else {
					map->OnMove_down();
					animation_infrontof.OnMove();
				}
			}
			else {
				if (y == 0 || stop > 0) {
					animation_infrontof.OnMove();
				}
				else {
					y -= STEP_SIZE;
					animation_infrontof.OnMove();
				}
			}
		}
		if (isMovingDown && isMovingUp == false && isMovingLeft == false && isMovingRight == false && hit == 0) {
			stop = 0;
			for (int i = 0; i < large; i++)
			{
				if ((-map->y) + y < enemy_y[i] && (-map->y) + y + 70 >= enemy_y[i] && (((-map->x) + x >= enemy_x[i] && (-map->x) + x <= enemy_x[i] + 60) || ((-map->x) + x + 60 >= enemy_x[i] && (-map->x) + x + 60 <= enemy_x[i] + 60)))
				{
					stop += 1;
				}
			}
			if (map->y > -610) {
				if (stop > 0)
				{
					animation_back.OnMove();
				}
				else if (y < 300) {
					y += STEP_SIZE;
					animation_back.OnMove();
				}
				else {
					map->OnMove_up();
					animation_back.OnMove();
				}
			}
			else {
				if (y == 445||stop > 0) {
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
		if (die == false)
		{
			blood[blood_index].ShowBitmap();
			if (infrontof1 == 1 && !isMovingLeft && !isMovingDown && !isMovingRight && !isMovingUp && hit == 0) {
				start_infrontof.SetTopLeft(x, y);
				start_infrontof.ShowBitmap();
			}
			if (left == 1 && !isMovingLeft && !isMovingDown && !isMovingRight && !isMovingUp && hit == 0) {
				start_left.SetTopLeft(x, y);
				start_left.ShowBitmap();
			}
			if (right == 1 && !isMovingLeft && !isMovingDown && !isMovingRight && !isMovingUp && hit == 0) {
				start_right.SetTopLeft(x, y);
				start_right.ShowBitmap();
			}
			if (back == 1 && !isMovingLeft && !isMovingDown && !isMovingRight && !isMovingUp && hit == 0) {
				start_back.SetTopLeft(x, y);
				start_back.ShowBitmap();
			}
			if (isMovingLeft&& hit == 0) {
				left = 1;
				infrontof1 = 0;
				back = 0;
				right = 0;
				animation_left.SetTopLeft(x, y);
				animation_left.OnShow();
			}
			if (isMovingUp&& hit == 0) {
				infrontof1 = 1;
				left = 0;
				right = 0;
				back = 0;
				animation_infrontof.SetTopLeft(x, y);
				animation_infrontof.OnShow();
			}
			if (isMovingRight&& hit == 0) {
				infrontof1 = 0;
				left = 0;
				right = 1;
				back = 0;
				animation_right.SetTopLeft(x, y);
				animation_right.OnShow();
			}
			if (isMovingDown&& hit == 0) {
				infrontof1 = 0;
				left = 0;
				right = 0;
				back = 1;
				animation_back.SetTopLeft(x, y);
				animation_back.OnShow();
			}

			if (hit != 0)
			{
				if (infrontof1 == 1)
				{
					animation_infrontof.SetTopLeft(x, y);
					animation_infrontof.OnShow();
				}
				if (back == 1)
				{
					animation_back.SetTopLeft(x, y);
					animation_back.OnShow();
				}
				if (right == 1)
				{
					animation_right.SetTopLeft(x, y);
					animation_right.OnShow();
				}
				if (left == 1)
				{
					animation_left.SetTopLeft(x, y);
					animation_left.OnShow();
				}
					
			}
		}
		else
		{
			if (infrontof1 == 1)
			{
				up_die.OnShow();
			}
			if (back == 1)
			{
				down_die.OnShow();
			}
			if (right == 1)
			{
				right_die.OnShow();
			}
			if (left == 1)
			{
				left_die.OnShow();
			}
		}
	}
}