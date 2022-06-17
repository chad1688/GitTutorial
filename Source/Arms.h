#include "Shot.h"
#include "Uzi.h"
#include "Rocket.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////
#ifndef ARMS_H
#define ARMS_H

	class CArms{
	public:
		CArms();
		void GetShotAddress(Cshot *shot);					// 獲得Cshot的位址
		void GetUziAddress(Cuzi *uzi);						// 獲得Cuzi的位址
		void GetRocketAddress(CRocket *rocket);				// 獲得CRocket的位址
		int randint();										// 取亂數 1是uzi 2是rocket
		void OnMove();
		void OnShow();
		int add_arms = 0;									// 判斷是否踩到紅色盒子 0是沒有 1是有
		bool change_arms;									// 判斷是否換槍
		int show_text;										// 0不顯示文字 1顯示文字
		int count2;											// 計算文字顯示時間
		int now_arms;										// 目前的武器
		bool die;											// 人物是否死亡
		int r;
		int my_arms[3];										// 判斷現在擁有甚麼武器
	protected:
		Cuzi *uzi;
		Cshot *shot;
		CRocket *rocket;
		int touch_up;
		int touch_down;
		int count;
		int newarms_address;
		
	};
#endif // !MAP_H
}
