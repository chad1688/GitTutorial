#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "string"
#include "Arms.h"
#include "Shot.h"
#include "Uzi.h"
//#include <iostream>
//#include <cstdlib>
//#include <ctime>

namespace game_framework {
	CArms::CArms() {
		now_arms = 0;
		count = 0;
		my_arms[0] = 1;
		touch_up = touch_down = 0;
		for (int i = 1; i < 3; i++) {
			my_arms[i] = 0;
			my_bullet[i] = 0;
		}
		change_arms = false;
	}

	void CArms::GetShotAddress(Cshot *x) {
		shot = x;
	}

	void CArms::GetUziAddress(Cuzi *y) {
		uzi = y;
	}

	void CArms::GetRocketAddress(CRocket *z) {
		rocket = z;
	}

	int CArms::randint() {
		srand((unsigned)time(NULL));

		int min = 1;
		int max = 2;

		int x = rand() % (max - min + 1) + min;
		return x;
	}

	void CArms::OnMove() {
		if (add_arms == 1) {
			count2 = 0;
			show_text = 1;
			r = randint();
			my_arms[r] = 1;
			if(r == 1)
				uzi->bullet = 0;
			if (r == 2)
				rocket->bullet = 0;
			add_arms = 0;
		}
		if (change_arms == true)
			touch_down = 1;
		if (change_arms == false && touch_down == 1)
			touch_up = 1;
		if (touch_down == 1 && touch_up == 1) {
			while (1) {
				now_arms++;
				if (now_arms > 2)
					now_arms = 0;
				if (my_arms[now_arms] == 1)
					break;
			}
			touch_down = touch_up = 0;
		}
		if (now_arms == 0) {
			if (uzi->space != 0)
				uzi->shot_OnMove2();
			if (rocket->space != 0 || rocket->show != 0)
				rocket->shot_OnMove2();
			shot->shot_OnMove();
			shot->shot_OnMove2();
		}
		if (now_arms == 1 && my_arms[now_arms] == 1) {
			if (shot->space != 0)
				shot->shot_OnMove2();
			if (rocket->space != 0 || rocket->show != 0)
				rocket->shot_OnMove2();
			uzi->shot_OnMove();
			uzi->shot_OnMove2();
			my_bullet[now_arms] -= 1;
			if (uzi->empty_bullet == 1) {
				my_arms[now_arms] = 0;
				now_arms = 0;
				uzi->empty_bullet = 0;
			}
		}
		if (now_arms == 2 && my_arms[now_arms] == 1) {
			if (shot->space != 0)
				shot->shot_OnMove2();
			if (uzi->space != 0)
				uzi->shot_OnMove2();
			rocket->shot_OnMove();
			rocket->shot_OnMove2();
			my_bullet[now_arms] -= 1;
			if (rocket->empty_bullet == 1) {
				my_arms[now_arms] = 0;
				now_arms = 0;
				rocket->empty_bullet = 0;
			}
		}
		if (count2 == 30) {
			show_text = 0;
		}
		count2++;
	}

	void CArms::OnShow() {
		if (now_arms == 0 || shot->space != 0)
			shot->shot_OnShow();
		if (now_arms == 1 || uzi->space != 0)
			uzi->shot_OnShow();
		if (now_arms == 2 || rocket->space != 0 || rocket->show != 0)
			rocket->shot_OnShow();
	}
}