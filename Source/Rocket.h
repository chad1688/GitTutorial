#include "map.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////
#ifndef Rocket_H
#define Rocket_H

	class CRocket {
	public:
		CRocket();
		void LoadBitmap();
		void shot_OnMove();
		void shot_OnMove2();
		void Getmapaddress(Cmap *m);
		//void LoadAnimation();
		void shot_OnShow();
		void Setspace(bool flag);
		int	gunx_up, guny_up, gunx_down, guny_down, gunx_right, guny_right, gunx_left, guny_left, mapx, mapy;
		int space_mapx, space_mapy;
		bool isMovingright;
		bool isMovingleft;
		bool isMovingup;
		bool isMovingdown;
		int empty_bullet;
		int bullet;
		int infrontof1, left, right, back;
		int space;
		int show;
		int temp_guny[40];
		int temp_infrontof[40];
		int temp_back[40];
		int temp_right[40];
		int temp_left[40];
		int temp_gunx[40];
		int shot_stop[40];
		int boomx;
		int boomy;
		bool is_space;
	protected:
		CMovingBitmap shot_infrontof[100];
		CMovingBitmap shot_left[100];
		CMovingBitmap shot_back[100];
		CMovingBitmap shot_right[100];
		CMovingBitmap boom;
		//CAnimation  shot_infrontof;
		//CAnimation	shot_left;
		//CAnimation	shot_right;
		//CAnimation	shot_back;
		Cmap *map;
		int temp_bullet[40];
		int count;
		int count2;
	};
#endif // !MAP_H
}
