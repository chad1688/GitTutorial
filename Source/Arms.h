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
		void GetShotAddress(Cshot *shot);
		void GetUziAddress(Cuzi *uzi);
		void GetRocketAddress(CRocket *rocket);
		int randint();
		void OnMove();
		void OnShow();
		int add_arms = 0;
		int my_bullet[3];
		bool change_arms;
		int show_text;
		int count2;
		int now_arms;
		bool die;
		int r;
		int my_arms[3];
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
