#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "string"
#include "vector"
#include "CPeople.h"
#include "enemy.h"
#include "Shot.h"
#include "Rocket.h"
#include "Uzi.h"
#include "map.h"
#include <math.h>

namespace game_framework {
	Cenemy::Cenemy() {
		large = 0;
		temp = 0;
		temp2 = 0;
		score = 0;
		for (int i = 0; i < 100; i++)
		{
			right[i] = left[i] = back[i] = up[i] = 0;
			stop[i] = 0;
			stop2[i] = 0;
			stop3[i] = 0;
			stop4[i] = 0;
			shoted[i] = 0;
			count[i] = 0;
			count2[i] = 0;
			count3[i] = 0;
			count4[i] = 0;
			is_enemy[i] = 2;
			is_enemy2[i] = 0;
			attack_back[i] = 0;
			attack_up[i] = 0;
			attack_left[i] = 0;
			attack_right[i] = 0;
			touch_enemy_address[i] = 0;
			enemy_die[i] = 0;
		}
	}

	void Cenemy::Getmapaddress(Cmap *m) {
		map = m;
	}

	void Cenemy::Getpeopleaddress(CPeople *x) {
		people = x;
	}

	void Cenemy::Getrocketaddress(CRocket *f) {
		rocket = f;
	}

	void Cenemy::Getshotaddress(Cshot *y) {
		shot = y;
	}

	void Cenemy::Getuziaddress(Cuzi *z) {
		uzi = z;
	}

	void Cenemy::LoadBitmap() {
		shoted_back.LoadBitmap("RES/enemy_shoted_back.bmp", RGB(255, 255, 255));
		shoted_up.LoadBitmap("RES/enemy_shoted_up.bmp", RGB(255, 255, 255));
		shoted_right.LoadBitmap("RES/enemy_shoted_right.bmp", RGB(255, 255, 255));
		shoted_left.LoadBitmap("RES/enemy_shoted_left.bmp", RGB(255, 255, 255));
	}

	void Cenemy::LoadAnimation() {
		animation_left.AddBitmap("RES/enemy_left2.bmp", RGB(255, 255, 255));
		animation_left.AddBitmap("RES/enemy_left3.bmp", RGB(255, 255, 255));
		animation_infrontof.AddBitmap("RES/enemy_up2.bmp", RGB(255, 255, 255));
		animation_infrontof.AddBitmap("RES/enemy_up3.bmp", RGB(255, 255, 255));
		animation_right.AddBitmap("RES/enemy_right2.bmp", RGB(255, 255, 255));
		animation_right.AddBitmap("RES/enemy_right3.bmp", RGB(255, 255, 255));
		animation_back.AddBitmap("RES/enemy_down2.bmp", RGB(255, 255, 255));
		animation_back.AddBitmap("RES/enemy_down3.bmp", RGB(255, 255, 255));
		for (int i = 0; i < 100; i++)
		{
			for (int j = 1; j < 5; j++) {
				char *change;
				std::string temp_string = "RES/enemy_down_attack" + to_string(j) + ".bmp";
				change = &temp_string[0];
				animation_back_attack[i].AddBitmap(change, RGB(255, 255, 255));
				std::string temp_string2 = "RES/enemy_up_attack" + to_string(j) + ".bmp";
				change = &temp_string2[0];
				animation_up_attack[i].AddBitmap(change, RGB(255, 255, 255));
				std::string temp_string3 = "RES/enemy_right_attack" + to_string(j) + ".bmp";
				change = &temp_string3[0];
				animation_right_attack[i].AddBitmap(change, RGB(255, 255, 255));
				std::string temp_string4 = "RES/enemy_left_attack" + to_string(j) + ".bmp";
				change = &temp_string4[0];
				animation_left_attack[i].AddBitmap(change, RGB(255, 255, 255));
			}
			for (int j = 3; j > 0; j--) {
				char *change;
				std::string temp_string = "RES/enemy_down_attack" + to_string(j) + ".bmp";
				change = &temp_string[0];
				animation_back_attack[i].AddBitmap(change, RGB(255, 255, 255));
				std::string temp_string2 = "RES/enemy_up_attack" + to_string(j) + ".bmp";
				change = &temp_string2[0];
				animation_up_attack[i].AddBitmap(change, RGB(255, 255, 255));
				std::string temp_string3 = "RES/enemy_right_attack" + to_string(j) + ".bmp";
				change = &temp_string3[0];
				animation_right_attack[i].AddBitmap(change, RGB(255, 255, 255));
				std::string temp_string4 = "RES/enemy_left_attack" + to_string(j) + ".bmp";
				change = &temp_string4[0];
				animation_left_attack[i].AddBitmap(change, RGB(255, 255, 255));
			}
		}
	}

	void Cenemy::blood_on_move() {
		if (shot->space != 0) {
			for (int i = 0; i < large; i++)
			{
				int temp_x, temp_y;
				isenemy2(enemy_x[i], enemy_y[i], i);
				if (shot->temp_right == 1 && enemy_x[i] >= (-map->x) + people->GetX1() && enemy_x[i] <= (-map->x) + shot->temp_gunx + 30 + 50 && ((enemy_y[i] <= (-map->y) + shot->temp_guny && enemy_y[i] + 60 >= (-map->y) + shot->temp_guny) || (enemy_y[i] <= (-map->y) + shot->temp_guny + 5 && enemy_y[i] + 60 >= (-map->y) + shot->temp_guny + 5))) {
					if (is_enemy2[i] == 0)
					{
						temp_x = enemy_x[i] + 20;
						if (temp_x < 1600 && map->isObject(map->x + enemy_x[i] + 60 + 5, map->y + enemy_y[i] + 60) && map->isObject(map->x + enemy_x[i] + 60 + 5, map->y + enemy_y[i]))
						{
							enemy_x[i] += 20;
						}
						else if (temp_x >= 1600)
						{
							enemy_x[i] = 1600;
						}
					}
					shoted[i] = 1;
					blood[i] -= 10;
					if (enemy_die[i] == 0 && blood[i] <= 0)
					{
						score += 10;
						enemy_die[i] = 1;
					}
					count[i] = 0;
					shot->shot_stop = 1;
				}
				if (shot->temp_left == 1 && enemy_x[i] <= (-map->x) + people->GetX1() && enemy_x[i] >= (-map->x) + shot->temp_gunx - 50 && ((enemy_y[i] <= (-map->y) + shot->temp_guny && enemy_y[i] + 60 >= (-map->y) + shot->temp_guny) || (enemy_y[i] <= (-map->y) + shot->temp_guny + 5 && enemy_y[i] + 60 >= (-map->y) + shot->temp_guny + 5))) {
					if (is_enemy2[i] == 0)
					{
						temp_x = enemy_x[i] - 20;
						if (temp_x >= 0 && map->isObject(map->x + enemy_x[i] - 1, map->y + enemy_y[i]) && map->isObject(map->x + enemy_x[i] - 1, map->y + enemy_y[i] + 60))
						{
							enemy_x[i] -= 20;
						}
						else if(temp_x < 0)
						{
							enemy_x[i] = 0;
						}
					}
					blood[i] -= 10;
					if (enemy_die[i] == 0 && blood[i] <= 0)
					{
						score += 10;
						enemy_die[i] = 1;
					}
					count[i] = 0;
					shoted[i] = 2;
					shot->shot_stop = 1;
				}
				if (shot->temp_back == 1 && enemy_y[i] >= (-map->y) + people->GetY1() && enemy_y[i] <= (-map->y) + shot->temp_guny + 30 && ((enemy_x[i] <= (-map->x) + shot->temp_gunx && enemy_x[i] + 60 >= (-map->x) + shot->temp_gunx) || (enemy_x[i] <= (-map->x) + shot->temp_gunx + 5 && enemy_x[i] + 60 >= (-map->x) + shot->temp_gunx + 5))) {
					if (is_enemy2[i] == 0)
					{
						temp_y = enemy_y[i] + 20;
						if (temp_y <= 1020 && map->isObject(map->x + enemy_x[i] + 60, map->y + enemy_y[i] + 60 + 10) && map->isObject(map->x + enemy_x[i], map->y + enemy_y[i] + 60 + 10))
						{
							enemy_y[i] += 20;
						}
						else if(temp_y > 1020)
						{
							enemy_y[i] = 1020;
						}
					}
					blood[i] -= 10;
					if (enemy_die[i] == 0 && blood[i] <= 0)
					{
						score += 10;
						enemy_die[i] = 1;
					}
					count[i] = 0;
					shoted[i] = 3;
					shot->shot_stop = 1;
				}
				if (shot->temp_infrontof == 1 && enemy_y[i] <= (-map->y) + people->GetY1() && enemy_y[i] >= (-map->y) + shot->temp_guny - 50 && ((enemy_x[i] <= (-map->x) + shot->temp_gunx && enemy_x[i] + 60 >= (-map->x) + shot->temp_gunx) || (enemy_x[i] <= (-map->x) + shot->temp_gunx + 5 && enemy_x[i] + 60 >= (-map->x) + shot->temp_gunx + 5))) {
					if (is_enemy2[i] == 0)
					{
						temp_y = enemy_y[i] - 20;
						if (temp_y >= 0 && map->isObject(map->x + enemy_x[i], map->y + enemy_y[i] - 1) && map->isObject(map->x + enemy_x[i] + 60, map->y + enemy_y[i] - 1))
						{
							enemy_y[i] -= 20;
						}
						else if(temp_y < 0)
						{
							enemy_y[i] = 0;
						}
					}
					blood[i] -= 10;
					if (enemy_die[i] == 0 && blood[i] <= 0)
					{
						score += 10;
						enemy_die[i] = 1;
					}
					count[i] = 0;
					shoted[i] = 4;
					shot->shot_stop = 1;
				}
			}
		}
		if (uzi->space != 0) {
			for (int i = 0; i < 100; i++) {
				for (int j = 0; j < large; j++)
				{
					int temp_x, temp_y;
					isenemy3(enemy_x[j], enemy_y[j], j, i);
					if (uzi->temp_right[i] == 1 && enemy_x[j] >= (-map->x) + people->GetX1() && enemy_x[j] <= (-map->x) + uzi->temp_gunx[i] + 30 + 50&& ((enemy_y[j] <= (-map->y) + uzi->temp_guny[i] && enemy_y[j] + 60 >= (-map->y) + uzi->temp_guny[i]) || (enemy_y[j] <= (-map->y) + uzi->temp_guny[i] + 5 && enemy_y[j] + 60 >= (-map->y) + uzi->temp_guny[i] + 5))) {
						if (is_enemy2[j] == 0)
						{
							temp_x = enemy_x[j] + 20;
							if (temp_x < 1600 && map->isObject(map->x + enemy_x[j] + 60 + 5, map->y + enemy_y[j] + 60) && map->isObject(map->x + enemy_x[j] + 60 + 5, map->y + enemy_y[j]))
							{
								enemy_x[j] += 20;
							}
							else if(temp_x >= 1600)
							{
								enemy_x[j] = 1600;
							}
						}
						blood[j] -= 10;
						if (enemy_die[j] == 0 && blood[j] <= 0)
						{
							score += 10;
							enemy_die[j] = 1;
						}
						count[j] = 0;
						shoted[j] = 1;
						uzi->shot_stop[i] = 1;
					}
					if (uzi->temp_left[i] == 1 && enemy_x[j] <= (-map->x) + people->GetX1() && enemy_x[j] >= (-map->x) + uzi->temp_gunx[i] - 50 && ((enemy_y[j] <= (-map->y) + uzi->temp_guny[i] && enemy_y[j] + 60 >= (-map->y) + uzi->temp_guny[i]) || (enemy_y[j] <= (-map->y) + uzi->temp_guny[i] + 5 && enemy_y[j] + 60 >= (-map->y) + uzi->temp_guny[i] + 5))) {
						if (is_enemy2[j] == 0)
						{
							temp_x = enemy_x[j] - 20;
							if (temp_x >= 0 && map->isObject(map->x + enemy_x[j] - 1, map->y + enemy_y[j]) && map->isObject(map->x + enemy_x[j] - 1, map->y + enemy_y[j] + 60))
							{
								enemy_x[j] -= 20;
							}
							else if(temp_x < 0)
							{
								enemy_x[j] = 0;
							}
						}
						blood[j] -= 10;
						if (enemy_die[j] == 0 && blood[j] <= 0)
						{
							score += 10;
							enemy_die[j] = 1;
						}
						count[j] = 0;
						shoted[j] = 2;
						uzi->shot_stop[i] = 1;
					}
					if (uzi->temp_back[i] == 1 && enemy_y[j] >= (-map->y) + people->GetY1() && enemy_y[j] <= (-map->y) + uzi->temp_guny[i] + 30 && ((enemy_x[j] <= (-map->x) + uzi->temp_gunx[i] && enemy_x[j] + 60 >= (-map->x) + uzi->temp_gunx[i]) || (enemy_x[j] <= (-map->x) + uzi->temp_gunx[i] + 5 && enemy_x[j] + 60 >= (-map->x) + uzi->temp_gunx[i] + 5))) {
						if (is_enemy2[j] == 0)
						{
							temp_y = enemy_y[j] + 20;
							if (temp_y <= 1020 && map->isObject(map->x + enemy_x[j] + 60, map->y + enemy_y[j] + 60 + 10) && map->isObject(map->x + enemy_x[j], map->y + enemy_y[j] + 60 + 10))
							{
								enemy_y[j] += 20;
							}
							else if(temp_y > 1020)
							{ 
								enemy_y[j] = 1020;
							}
						}
						blood[j] -= 10;
						if (enemy_die[j] == 0 && blood[j] <= 0)
						{
							score += 10;
							enemy_die[j] = 1;
						}
						count[j] = 0;
						shoted[j] = 3;
						uzi->shot_stop[i] = 1;
					}
					if (uzi->temp_infrontof[i] == 1 && enemy_y[j] <= (-map->y) + people->GetY1() && enemy_y[j] >= (-map->y) + uzi->temp_guny[i] - 50 && ((enemy_x[j] <= (-map->x) + uzi->temp_gunx[i] && enemy_x[j] + 60 >= (-map->x) + uzi->temp_gunx[i]) || (enemy_x[j] <= (-map->x) + uzi->temp_gunx[i] + 5 && enemy_x[j] + 60 >= (-map->x) + uzi->temp_gunx[i] + 5))) {
						if (is_enemy2[j] == 0)
						{
							temp_y = enemy_y[j] - 20;
							if (temp_y >= 0 && map->isObject(map->x + enemy_x[j], map->y + enemy_y[j] - 1) && map->isObject(map->x + enemy_x[j] + 60, map->y + enemy_y[j] - 1))
							{
								enemy_y[j] -= 20;
							}
							else if(temp_y < 0)
							{
								enemy_y[j] = 0;
							}
						}
						blood[j] -= 10;
						if (enemy_die[j] == 0 && blood[j] <= 0)
						{
							score += 10;
							enemy_die[j] = 1;
						}
						count[j] = 0;
						shoted[j] = 4;
						uzi->shot_stop[i] = 1;
					}
				}
			}
		}
		if (rocket->space != 0) {
			for (int i = 0; i < 40; i++) {
				for (int j = 0; j < large; j++)
				{
					if (rocket->temp_right[i] == 1 && enemy_x[j] >= (-map->x) + people->GetX1() && enemy_x[j] <= (-map->x) + rocket->temp_gunx[i] + 30 && ((enemy_y[j] <= (-map->y) + rocket->temp_guny[i] && enemy_y[j] + 60 >= (-map->y) + rocket->temp_guny[i]) || (enemy_y[j] <= (-map->y) + rocket->temp_guny[i] + 30 && enemy_y[j] + 60 >= (-map->y) + rocket->temp_guny[i] + 30))) {
						rocket->shot_stop[i] = 1;
					}
					if (rocket->temp_left[i] == 1 && enemy_x[j] <= (-map->x) + people->GetX1() && enemy_x[j] >= (-map->x) + rocket->temp_gunx[i] - 50 && ((enemy_y[j] <= (-map->y) + rocket->temp_guny[i] && enemy_y[j] + 60 >= (-map->y) + rocket->temp_guny[i]) || (enemy_y[j] <= (-map->y) + rocket->temp_guny[i] + 30 && enemy_y[j] + 60 >= (-map->y) + rocket->temp_guny[i] + 30))) {
						rocket->shot_stop[i] = 1;
					}
					if (rocket->temp_back[i] == 1 && enemy_y[j] >= (-map->y) + people->GetY1() && enemy_y[j] <= (-map->y) + rocket->temp_guny[i] + 30 && ((enemy_x[j] <= (-map->x) + rocket->temp_gunx[i] && enemy_x[j] + 60 >= (-map->x) + rocket->temp_gunx[i]) || (enemy_x[j] <= (-map->x) + rocket->temp_gunx[i] + 30 && enemy_x[j] + 60 >= (-map->x) + rocket->temp_gunx[i] + 30))) {
						rocket->shot_stop[i] = 1;
					}
					if (rocket->temp_infrontof[i] == 1 && enemy_y[j] <= (-map->y) + people->GetY1() && enemy_y[j] >= (-map->y) + rocket->temp_guny[i] - 50 && ((enemy_x[j] <= (-map->x) + rocket->temp_gunx[i] && enemy_x[j] + 60 >= (-map->x) + rocket->temp_gunx[i]) || (enemy_x[j] <= (-map->x) + rocket->temp_gunx[i] + 30 && enemy_x[j] + 60 >= (-map->x) + rocket->temp_gunx[i] + 30))) {
						rocket->shot_stop[i] = 1;
					}
				}
				
			}
		}
		if (rocket->show == 2) {
			for (int i = 0; i < large; i++)
			{
				if (enemy_x[i] >= (-map->x) + rocket->boomx && enemy_x[i] <= (-map->x) + rocket->boomx + 200 && enemy_y[i] >= (-map->y) + rocket->boomy + 5 && enemy_y[i] <= (-map->y) + rocket->boomy + 100)
				{
					blood[i] = 0;
					if (enemy_die[i] == 0)
					{
						score += 10;
						enemy_die[i] = 1;
					}
				}
				else if (enemy_x[i] >= (-map->x) + rocket->boomx && enemy_x[i] + 60 <= (-map->x) + rocket->boomx + 200 && enemy_y[i] >= (-map->y) + rocket->boomy + 5 && enemy_y[i] <= (-map->y) + rocket->boomy + 100)
				{
					blood[i] = 0;
					if (enemy_die[i] == 0)
					{
						score += 10;
						enemy_die[i] = 1;
					}
				}
				else if (enemy_x[i] >= (-map->x) + rocket->boomx && enemy_x[i] <= (-map->x) + rocket->boomx + 200 && enemy_y[i] + 60 >= (-map->y) + rocket->boomy + 5 && enemy_y[i] + 60 <= (-map->y) + rocket->boomy + 100)
				{
					blood[i] = 0;
					if (enemy_die[i] == 0)
					{
						score += 10;
						enemy_die[i] = 1;
					}
				}
				else if (enemy_x[i] + 60 >= (-map->x) + rocket->boomx && enemy_x[i] + 60 <= (-map->x) + rocket->boomx + 200 && enemy_y[i] + 60 >= (-map->y) + rocket->boomy + 5 && enemy_y[i] + 60 <= (-map->y) + rocket->boomy + 100)
				{
					blood[i] = 0;
					if (enemy_die[i] == 0)
					{
						score += 10;
						enemy_die[i] = 1;
					}
				}
			}
			
		}
		for (int i = 0; i < large; i++)
		{
			if (shoted[i] != 0)
			{
				count[i] ++;
			}
			if (count[i] >= 20)
			{
				shoted[i] = 0;
			}
		}
	}

	int Cenemy::randx()
	{
		srand((unsigned)time(NULL));
		if (choose_map == 0)
		{
			int min = 800;
			int max = 870;

			int x = rand() % (max - min + 1) + min;
			return x;
		}
		else
		{
			int min = 0;
			int max = 1600;

			int x = rand() % (max - min + 1) + min;
			return x;
		}
	}

	int Cenemy::randy()
	{
		srand((unsigned)time(NULL));

		if (choose_map == 0)
		{
			int min = 110;
			int max = 930;

			int y = rand() % (max - min + 1) + min;
			return y;
		}
		else
		{
			int min = 0;
			int max = 1020;

			int y = rand() % (max - min + 1) + min;
			return y;
		}
	}

	int Cenemy::rand_position()
	{
		srand((unsigned)time(NULL));

		int min = 1;
		int max = 4;

		int position = rand() % (max - min + 1) + min;
		return position;
	}

	void Cenemy::born() 
	{
		enemy_position = rand_position();
		if (enemy_position == 1)
		{
			enemy_x[large] = randx();
			enemy_y[large] = 0;
		}
		else if (enemy_position == 2)
		{
			enemy_x[large] = 1600;
			enemy_y[large] = randy();
		}
		else if (enemy_position == 3)
		{
			enemy_x[large] = randx();
			enemy_y[large] = 1020;
		}
		else
		{
			enemy_x[large] = 0;
			enemy_y[large] = randy();
		}
		blood[large] = 100;
		large++;
	}

	void Cenemy::isenemy(int x,int y,int adrress)
	{
		for (int i = 0; i < large; i++)
		{
			if (i == adrress)
				continue;
			if (((distance_y < 0 && is_enemy[adrress] == 2) || is_enemy[adrress] == 7) && map->isObject(map->x + x + 60, map->y + y + 60 + 10) && map->isObject(map->x + x, map->y + y + 60 + 10)) {
				if (shoted[i] != 0)
				{
					if (y < enemy_y[i] && y + 70 >= enemy_y[i] && ((x >= enemy_x[i] && x <= enemy_x[i] + 60) || (x + 60 >= enemy_x[i] && x + 60 <= enemy_x[i] + 60)))
					{
						stop2[adrress] = 1;
						count2[adrress] = 0;
						break;
					}
				}
				else if (is_enemy[adrress] == 7)
				{
					if (y < enemy_y[i] && y + 70 >= enemy_y[i] && ((x >= enemy_x[i] && x <= enemy_x[i] + 60) || (x + 60 >= enemy_x[i] && x + 60 <= enemy_x[i] + 60)))
					{
						stop3[adrress] = 1;
						count3[adrress] = 0;
						break;
					}

					if (!(x <= enemy_x[touch_enemy_address[adrress]] + 70 && x > enemy_x[touch_enemy_address[adrress]] && ((y >= enemy_y[touch_enemy_address[adrress]] && y <= enemy_y[touch_enemy_address[adrress]] + 60) || (y + 60 >= enemy_y[touch_enemy_address[adrress]] && y + 60 <= enemy_y[touch_enemy_address[adrress]] + 60))))
					{
						is_enemy[adrress] = 8;
						touch_enemy_address[adrress] = 0;
						break;
					}
				}
				else
				{
					if (y < enemy_y[i] && y + 70 >= enemy_y[i] && ((x >= enemy_x[i] && x <= enemy_x[i] + 60) || (x + 60 >= enemy_x[i] && x + 60 <= enemy_x[i] + 60)))
					{
						is_enemy[adrress] = 1;
						touch_enemy_address[adrress] = i;
						break;
					}
					else
					{
						is_enemy[adrress] = 2;
					}
				}
			}
			else if (((distance_x < 0 && (is_enemy[adrress] == 6 || is_enemy[adrress] == 2)) || is_enemy[adrress] == 1 || is_enemy[adrress] == 12) && map->isObject(map->x + x + 60 + 5, map->y + y + 60) && map->isObject(map->x + x + 60 + 5, map->y + y)) {
				if (shoted[i] != 0)
				{
					if (x < enemy_x[i] && x + 70 >= enemy_x[i] && ((y >= enemy_y[i] && y <= enemy_y[i] + 60) || (y + 60 >= enemy_y[i] && y + 60 <= enemy_y[i] + 60)))
					{
						stop2[adrress] = 1;
						count2[adrress] = 0;
						break;
					}
				}
				if (is_enemy[adrress] == 1)
				{
					if (x < enemy_x[i] && x + 70 >= enemy_x[i] && ((y >= enemy_y[i] && y <= enemy_y[i] + 60) || (y + 60 >= enemy_y[i] && y + 60 <= enemy_y[i] + 60)))
					{
						stop4[adrress] = 1;
						count4[adrress] = 0;
						break;
					}
					if (!(y < enemy_y[touch_enemy_address[adrress]] && y + 70 >= enemy_y[touch_enemy_address[adrress]] && ((x >= enemy_x[touch_enemy_address[adrress]] && x <= enemy_x[touch_enemy_address[adrress]] + 60) || (x + 60 >= enemy_x[touch_enemy_address[adrress]] && x + 60 <= enemy_x[touch_enemy_address[adrress]] + 60))))
					{
						is_enemy[adrress] = 2;
						touch_enemy_address[adrress] = 0;
						break;
					}
				}
				else if (is_enemy[adrress] == 2 && !(map->isObject(map->x + x + 60, map->y + y + 60 + 10) && map->isObject(map->x + x, map->y + y + 60 + 10)))
				{
					is_enemy[adrress] = 12;
					break;
				}
				else if (is_enemy[adrress] == 12)
				{
					if (map->isObject(map->x + x + 60, map->y + y + 60 + 10) && map->isObject(map->x + x, map->y + y + 60 + 10))
					{
						is_enemy[adrress] = 2;
						break;
					}
					if (x < enemy_x[i] && x + 70 >= enemy_x[i] && ((y >= enemy_y[i] && y <= enemy_y[i] + 60) || (y + 60 >= enemy_y[i] && y + 60 <= enemy_y[i] + 60)))
					{
						stop4[adrress] = 1;
						count4[adrress] = 0;
						break;
					}
				}
				else
				{
					if (x < enemy_x[i] && x + 70 >= enemy_x[i] && ((y >= enemy_y[i] && y <= enemy_y[i] + 60) || (y + 60 >= enemy_y[i] && y + 60 <= enemy_y[i] + 60)))
					{
						if (map->isObject(map->x + x, map->y + y - 5) && map->isObject(map->x + x + 60, map->y + y - 5))
						{
							is_enemy[adrress] = 5;
							touch_enemy_address[adrress] = i;
							break;
						}
						else
						{
							stop4[adrress] = 1;
							count4[adrress] = 0;
							break;
						}
					}
					else
					{
						is_enemy[adrress] = 6;
					}
				}
			}
			else if (((distance_x > 0 && (is_enemy[adrress] == 8 || is_enemy[adrress] == 2)) || is_enemy[adrress] == 3 || is_enemy[adrress] == 6 || is_enemy[adrress] == 13) && (map->isObject(map->x + x - 1, map->y + y) && map->isObject(map->x + x - 1, map->y + y + 60))) {
				if (shoted[i] != 0)
				{
					if (x <= enemy_x[i] + 70 && x > enemy_x[i] && ((y >= enemy_y[i] && y <= enemy_y[i] + 60) || (y + 60 >= enemy_y[i] && y + 60 <= enemy_y[i] + 60)))
					{
						stop2[adrress] = 1;
						count2[adrress] = 0;
						break;
					}
				}
				if (is_enemy[adrress] == 3)
				{
					if (x <= enemy_x[i] + 70 && x > enemy_x[i] && ((y >= enemy_y[i] && y <= enemy_y[i] + 60) || (y + 60 >= enemy_y[i] && y + 60 <= enemy_y[i] + 60)))
					{
						stop4[adrress] = 1;
						count4[adrress] = 0;
						break;
					}
					if (!(y > enemy_y[touch_enemy_address[adrress]] && y <= enemy_y[touch_enemy_address[adrress]] + 70 && ((x >= enemy_x[touch_enemy_address[adrress]] && x <= enemy_x[touch_enemy_address[adrress]] + 60) || (x + 60 >= enemy_x[touch_enemy_address[adrress]] && x + 60 <= enemy_x[touch_enemy_address[adrress]] + 60))))
					{
						is_enemy[adrress] = 4;
						touch_enemy_address[adrress] = 0;
						break;
					}
				}
				else if (is_enemy[adrress] == 2 && !(map->isObject(map->x + x + 60, map->y + y + 60 + 10) && map->isObject(map->x + x, map->y + y + 60 + 10)))
				{
					is_enemy[adrress] = 13;
					break;
				}
				else if (is_enemy[adrress] == 13)
				{
					if (map->isObject(map->x + x + 60, map->y + y + 60 + 10) && map->isObject(map->x + x, map->y + y + 60 + 10))
					{
						is_enemy[adrress] = 2;
						break;
					}
					if (x <= enemy_x[i] + 70 && x > enemy_x[i] && ((y >= enemy_y[i] && y <= enemy_y[i] + 60) || (y + 60 >= enemy_y[i] && y + 60 <= enemy_y[i] + 60)))
					{
						stop4[adrress] = 1;
						count4[adrress] = 0;
						break;
					}
				}
				else
				{
					if (x <= enemy_x[i] + 70 && x > enemy_x[i] && ((y >= enemy_y[i] && y <= enemy_y[i] + 60) || (y + 60 >= enemy_y[i] && y + 60 <= enemy_y[i] + 60)))
					{
						if (map->isObject(map->x + x, map->y + y - 5) && map->isObject(map->x + x + 60, map->y + y - 5))
						{
							is_enemy[adrress] = 7;
							touch_enemy_address[adrress] = i;
							break;
						}
						else
						{
							stop4[adrress] = 1;
							count4[adrress] = 0;
							break;
						}
					}
					else
					{
						is_enemy[adrress] = 8;
					}
				}
			}
			else if (((distance_y > 0 && is_enemy[adrress] == 4) || is_enemy[adrress] == 5 || is_enemy[adrress] == 6 || is_enemy[adrress] == 8 || is_enemy[adrress] == 10 || is_enemy[adrress] == 11) && (map->isObject(map->x + x, map->y + y - 1) && map->isObject(map->x + x + 60, map->y + y - 1))) {
				if (shoted[i] != 0)
				{
					if (y > enemy_y[i] && y <= enemy_y[i] + 70 && ((x >= enemy_x[i] && x <= enemy_x[i] + 60) || (x + 60 >= enemy_x[i] && x + 60 <= enemy_x[i] + 60)))
					{
						stop2[adrress] = 1;
						count2[adrress] = 0;
						break;
					}
				}
				if (is_enemy[adrress] == 5)
				{
					if (y > enemy_y[i] && y <= enemy_y[i] + 70 && ((x >= enemy_x[i] && x <= enemy_x[i] + 60) || (x + 60 >= enemy_x[i] && x + 60 <= enemy_x[i] + 60)))
					{
						stop3[adrress] = 1;
						count3[adrress] = 0;
						break;
					}
					if (!(x < enemy_x[touch_enemy_address[adrress]] && x + 70 >= enemy_x[touch_enemy_address[adrress]] && ((y >= enemy_y[touch_enemy_address[adrress]] && y <= enemy_y[touch_enemy_address[adrress]] + 60) || (y + 60 >= enemy_y[touch_enemy_address[adrress]] && y + 60 <= enemy_y[touch_enemy_address[adrress]] + 60))))
					{
						is_enemy[adrress] = 6;
						touch_enemy_address[adrress] = 0;
						break;
					}

				}
				else if (is_enemy[adrress] == 6 && (!(map->isObject(map->x + x + 60 + 5, map->y + y) && map->isObject(map->x + x + 60 + 5, map->y + y + 60))))
				{
					is_enemy[adrress] = 10;
					break;
				}
				else if (is_enemy[adrress] == 10)
				{
					if (map->isObject(map->x + x + 60 + 1, map->y + y) && map->isObject(map->x + x + 60 + 1, map->y + y + 60))
					{
						is_enemy[adrress] = 6;
						break;
					}
					if (y > enemy_y[i] && y <= enemy_y[i] + 70 && ((x >= enemy_x[i] && x <= enemy_x[i] + 60) || (x + 60 >= enemy_x[i] && x + 60 <= enemy_x[i] + 60)))
					{
						stop3[adrress] = 1;
						count3[adrress] = 0;
						break;
					}
				}
				else if (is_enemy[adrress] == 8 && (!(map->isObject(map->x + x - 1, map->y + y) && map->isObject(map->x + x - 1, map->y + y + 60))))
				{
					is_enemy[adrress] = 11;
					break;
				}
				else if (is_enemy[adrress] == 11)
				{
					if (map->isObject(map->x + x - 1, map->y + y) && map->isObject(map->x + x - 1, map->y + y + 60))
					{
						is_enemy[adrress] = 8;
						break;
					}
					if (y <= 1)
					{
						is_enemy[adrress] = 2;
						break;
					}
					if (y > enemy_y[i] && y <= enemy_y[i] + 70 && ((x >= enemy_x[i] && x <= enemy_x[i] + 60) || (x + 60 >= enemy_x[i] && x + 60 <= enemy_x[i] + 60)))
					{
						stop3[adrress] = 1;
						count3[adrress] = 0;
						break;
					}
				}
				else
				{
					if (y > enemy_y[i] && y <= enemy_y[i] + 70 && ((x >= enemy_x[i] && x <= enemy_x[i] + 60) || (x + 60 >= enemy_x[i] && x + 60 <= enemy_x[i] + 60)))
					{
						is_enemy[adrress] = 3;
						touch_enemy_address[adrress] = i;
						break;
					}
					else
					{
						is_enemy[adrress] = 4;
					}
				}
			}
			else
			{
				if (distance_x < 0 && map->isObject(map->x + x + 60 + 5, map->y + y + 60) && map->isObject(map->x + x + 60 + 5, map->y + y))
				{
					is_enemy[adrress] = 6;
				}
				else if (distance_x > 0 && map->isObject(map->x + x - 1, map->y + y + 60) && map->isObject(map->x + x - 1, map->y + y))
				{
					is_enemy[adrress] = 8;
				}
				else if (distance_x == 0)
				{
					is_enemy[adrress] = 13;
					break;
				}
				else
				{
					is_enemy[adrress] = 2;
				}
			}
		}
	}

	void Cenemy::isenemy2(int x, int y, int adrress)
	{
		for (int i = 0; i < large; i++)
		{
			if (i == adrress)
				continue;
			if (shot->temp_back == 1)
			{
				if (y < enemy_y[i] && y + 70 >= enemy_y[i] && ((x >= enemy_x[i] && x <= enemy_x[i] + 60) || (x + 60 >= enemy_x[i] && x + 60 <= enemy_x[i] + 60)))
				{
					is_enemy2[adrress] = 1;
					break;
				}
				else
				{
					is_enemy2[adrress] = 0;
				}
			}
			else if (shot->temp_infrontof == 1)
			{
				if (y > enemy_y[i] && y<= enemy_y[i] + 70 && ((x >= enemy_x[i] && x <= enemy_x[i] + 60) || (x + 60 >= enemy_x[i] && x + 60 <= enemy_x[i] + 60)))
				{
					is_enemy2[adrress] = 1;
					break;
				}
				else
				{
					is_enemy2[adrress] = 0;
				}
			}
			else if (shot->temp_right == 1)
			{
				if (x < enemy_x[i] && x + 70 >= enemy_x[i] && ((y >= enemy_y[i] && y <= enemy_y[i] + 60) || (y + 60 >= enemy_y[i] && y + 60 <= enemy_y[i] + 60)))
				{
					is_enemy2[adrress] = 1;
					break;
				}
				else
				{
					is_enemy2[adrress] = 0;
				}
			}
			else if (shot->temp_left == 1)
			{
				if (x <= enemy_x[i] + 70 && x > enemy_x[i] && ((y >= enemy_y[i] && y <= enemy_y[i] + 60) || (y + 60 >= enemy_y[i] && y + 60 <= enemy_y[i] + 60)))
				{
					is_enemy2[adrress] = 1;
					break;
				}
				else
				{
					is_enemy2[adrress] = 0;
				}
			}
		}
	}

	void Cenemy::isenemy3(int x, int y, int adrress, int adrress2)
	{
		for (int i = 0; i < large; i++)
		{
			if (i == adrress)
				continue;
			if (uzi->temp_back[adrress2] == 1)
			{
				if (y < enemy_y[i] && y + 70 >= enemy_y[i] && ((x >= enemy_x[i] && x <= enemy_x[i] + 60) || (x + 60 >= enemy_x[i] && x + 60 <= enemy_x[i] + 60)))
				{
					is_enemy2[adrress] = 1;
					break;
				}
				else
				{
					is_enemy2[adrress] = 0;
				}
			}
			else if (uzi->temp_infrontof[adrress2] == 1)
			{
				if (y > enemy_y[i] && y <= enemy_y[i] + 70 && ((x >= enemy_x[i] && x <= enemy_x[i] + 60) || (x + 60 >= enemy_x[i] && x + 60 <= enemy_x[i] + 60)))
				{
					is_enemy2[adrress] = 1;
					break;
				}
				else
				{
					is_enemy2[adrress] = 0;
				}
			}
			else if (uzi->temp_right[adrress2] == 1)
			{
				if (x < enemy_x[i] && x + 70 >= enemy_x[i] && ((y >= enemy_y[i] && y <= enemy_y[i] + 60) || (y + 60 >= enemy_y[i] && y + 60 <= enemy_y[i] + 60)))
				{
					is_enemy2[adrress] = 1;
					break;
				}
				else
				{
					is_enemy2[adrress] = 0;
				}
			}
			else if (uzi->temp_left[adrress2] == 1)
			{
				if (x <= enemy_x[i] + 70 && x > enemy_x[i] && ((y >= enemy_y[i] && y <= enemy_y[i] + 60) || (y + 60 >= enemy_y[i] && y + 60 <= enemy_y[i] + 60)))
				{
					is_enemy2[adrress] = 1;
					break;
				}
				else
				{
					is_enemy2[adrress] = 0;
				}
			}
		}
	}

	void Cenemy::On_Move() 
	{
		people->Setmonser_touch(false);
		for (int i = 0; i < large; i++)
		{
			distance_x = enemy_x[i] - ((-map->x) + people->GetX1());
			distance_y = enemy_y[i] - ((-map->y) + people->GetY1());
			isenemy(enemy_x[i], enemy_y[i], i);
			if (shoted[i] == 1)
			{
				is_enemy[i] = 8;
			}
			else if (shoted[i] == 2)
			{
				is_enemy[i] = 6;
			}
			else if (shoted[i] == 3)
			{
				is_enemy[i] = 4;
			}
			else if (shoted[i] == 4)
			{
				is_enemy[i] = 2;
			}
			if ((is_enemy[i] == 2 || is_enemy[i] == 7) && map->isObject(map->x + enemy_x[i] + 60, map->y + enemy_y[i] + 60 + 10) && map->isObject(map->x + enemy_x[i], map->y + enemy_y[i] + 60 + 10) || attack_back[i] == 1)
			{
				up[i] = 0;
				right[i] = 0;
				left[i] = 0;
				back[i] = 1;
				if (distance_y >= -66 && abs(distance_x) <= 66 && distance_y < 0 || attack_back[i] == 1) {
					if (attack_back[i] == 0)
					{
						animation_back_attack[i].Reset();
						attack_back[i] = 1;
					}
					animation_back_attack[i].OnMove();
				}
				else if (stop2[i] == 1 || stop3[i] == 1)
				{
					animation_back.OnMove();
				}
				else if (shoted[i] != 0) {
					animation_back.OnMove();
				}
				else if (enemy_y[i] <= 1020) {
					enemy_y[i] += 1;
					animation_back.OnMove();
				}
			}
			else if ((is_enemy[i] == 1 || is_enemy[i] == 6 || is_enemy[i] == 12) && map->isObject(map->x + enemy_x[i] + 60 + 5, map->y + enemy_y[i] + 60) && map->isObject(map->x + enemy_x[i] + 60 + 5, map->y + enemy_y[i]) || attack_right[i] == 1)
			{
				up[i] = 0;
				right[i] = 1;
				left[i] = 0;
				back[i] = 0;
				if (distance_x >= -66 && abs(distance_y) <= 66 && distance_x < 0 || attack_right[i] == 1) {
					if (attack_right[i] == 0)
					{
						animation_right_attack[i].Reset();
						attack_right[i] = 1;
					}
					animation_right_attack[i].OnMove();
				}
				else if (stop2[i] == 1 || stop3[i] == 1 || stop4[i] == 1)
				{
					animation_right.OnMove();
				}
				else if (shoted[i] != 0) {
					animation_right.OnMove();
				}
				else if (enemy_x[i] <= 1600) {
					enemy_x[i] += 1;
					animation_right.OnMove();
				}
			}
			else if ((is_enemy[i] == 3 || is_enemy[i] == 8 || is_enemy[i] == 13) && map->isObject(map->x + enemy_x[i] - 1, map->y + enemy_y[i]) && map->isObject(map->x + enemy_x[i] - 1, map->y + enemy_y[i] + 60))
			{
				up[i] = 0;
				right[i] = 0;
				left[i] = 1;
				back[i] = 0;
				if (abs(distance_y) <= 66 && distance_x <= 66 && distance_x > 0 || attack_left[i] == 1) {
					if (attack_left[i] == 0)
					{
						animation_left_attack[i].Reset();
						attack_left[i] = 1;
					}
					animation_left_attack[i].OnMove();
				}
				else if (stop2[i] == 1 || stop3[i] == 1 || stop4[i] == 1)
				{
					animation_left.OnMove();
				}
				else if (shoted[i] != 0) {
					animation_left.OnMove();
				}
				else if (enemy_x[i] >= 0) {
					enemy_x[i] -= 1;
					animation_left.OnMove();
				}
			}
			else if ((is_enemy[i] == 5 || is_enemy[i] == 4 || is_enemy[i] == 10 || is_enemy[i] == 11) && map->isObject(map->x + enemy_x[i], map->y + enemy_y[i] - 1) && map->isObject(map->x + enemy_x[i] + 60, map->y + enemy_y[i] - 1) || attack_up[i] == 1)
			{
				up[i] = 1;
				right[i] = 0;
				left[i] = 0;
				back[i] = 0;
				if (distance_y <= 66 && abs(distance_x) <= 66 && distance_y > 0 || attack_up[i] == 1) {
					if (attack_up[i] == 0)
					{
						animation_up_attack[i].Reset();
						attack_up[i] = 1;
					}
					animation_up_attack[i].OnMove();
				}
				else if (stop2[i] == 1 || stop3[i] == 1)
				{
					animation_infrontof.OnMove();
				}
				else if (shoted[i] != 0) {
					animation_infrontof.OnMove();
				}
				else if (enemy_y[i] >= 0) {
					enemy_y[i] -= 1;
					animation_infrontof.OnMove();
				}
			}
			if (animation_back_attack[i].IsFinalBitmap() && attack_back[i] == 1)
			{
				if (distance_y >= -126 && abs(distance_x) <= 66 && distance_y < 0)
				{
					people->Setmonser_touch(true);
					people->hit = 1;
				}
					
				attack_back[i] = 0;
				
			}
			else if (animation_up_attack[i].IsFinalBitmap() && attack_up[i] == 1)
			{
				if (distance_y <= 126 && abs(distance_x) <= 66 && distance_y > 0)
				{
					people->Setmonser_touch(true);
					people->hit = 2;
				}
					
				attack_up[i] = 0;
				
			}
			else if (animation_right_attack[i].IsFinalBitmap() && attack_right[i] == 1)
			{
				if (distance_x >= -126 && abs(distance_y) <= 66 && distance_x < 0)
				{
					people->Setmonser_touch(true);
					people->hit = 3;
				}
				attack_right[i] = 0;
				
			}
			else if (animation_left_attack[i].IsFinalBitmap() && attack_left[i] == 1)
			{
				if (distance_x <= 126 && abs(distance_y) <= 66 && distance_x > 0)
				{
					people->Setmonser_touch(true);
					people->hit = 4;
				}	
				attack_left[i] = 0;
				
			}
			if (stop2[i] == 1)
			{
				count2[i] ++;
			}
			if (count2[i] >= 20)
			{
				stop2[i] = 0;
			}
			if (stop3[i] == 1)
			{
				count3[i] ++;
			}
			if (count3[i] >= 20)
			{
				stop3[i] = 0;
			}
			if (stop4[i] == 1)
			{
				count4[i] ++;
			}
			if (count4[i] >= 20)
			{
				stop4[i] = 0;
			}
		}
	}

	void Cenemy::On_Show() 
	{
		for (int i = 0; i < large; i++)
		{
			if (blood[i] > 0) {
				if (up[i] == 1) {
					if (shoted[i] == 3)
					{
						shoted_up.SetTopLeft(map->x + enemy_x[i], map->y + enemy_y[i]);
						shoted_up.ShowBitmap();
					}
					else if (!animation_up_attack[i].IsFinalBitmap() && attack_up[i] == 1)
					{
						animation_up_attack[i].SetTopLeft(map->x + enemy_x[i], map->y + enemy_y[i]);
						animation_up_attack[i].OnShow();
					}
					else
					{
						animation_infrontof.SetTopLeft(map->x + enemy_x[i], map->y + enemy_y[i]);
						animation_infrontof.OnShow();
					}
				}
				if (left[i] == 1) {
					if (shoted[i] == 1)
					{
						shoted_left.SetTopLeft(map->x + enemy_x[i], map->y + enemy_y[i]);
						shoted_left.ShowBitmap();
					}
					else if (!animation_left_attack[i].IsFinalBitmap() && attack_left[i] == 1)
					{
						animation_left_attack[i].SetTopLeft(map->x + enemy_x[i], map->y + enemy_y[i]);
						animation_left_attack[i].OnShow();
					}
					else
					{
						animation_left.SetTopLeft(map->x + enemy_x[i], map->y + enemy_y[i]);
						animation_left.OnShow();
					}
				}
				if (right[i] == 1) {
					if (shoted[i] == 2)
					{
						shoted_right.SetTopLeft(map->x + enemy_x[i], map->y + enemy_y[i]);
						shoted_right.ShowBitmap();
					}
					else if (!animation_right_attack[i].IsFinalBitmap() && attack_right[i] == 1)
					{
						animation_right_attack[i].SetTopLeft(map->x + enemy_x[i], map->y + enemy_y[i]);
						animation_right_attack[i].OnShow();
					}
					else
					{
						animation_right.SetTopLeft(map->x + enemy_x[i], map->y + enemy_y[i]);
						animation_right.OnShow();
					}
				}
				if (back[i] == 1) {
					if (shoted[i] == 4)
					{
						shoted_back.SetTopLeft(map->x + enemy_x[i], map->y + enemy_y[i]);
						shoted_back.ShowBitmap();
					}
					else if (!animation_back_attack[i].IsFinalBitmap() && attack_back[i] == 1)
					{
						animation_back_attack[i].SetTopLeft(map->x + enemy_x[i], map->y + enemy_y[i]);
						animation_back_attack[i].OnShow();
					}
					else
					{
						animation_back.SetTopLeft(map->x + enemy_x[i], map->y + enemy_y[i]);
						animation_back.OnShow();
					}
				}
			}
			else {
				enemy_x[i] = 1800;
				enemy_y[i] = 1800;
			}
		}
		
	}
}