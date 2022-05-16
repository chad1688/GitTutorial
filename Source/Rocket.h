#include "map.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
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
		int	gunx, guny, mapx, mapy;
		bool isMovingright;
		bool isMovingleft;
		bool isMovingup;
		bool isMovingdown;
		int empty_bullet;
		int bullet;
		int infrontof1, left, right, back;
		int space;
		int show;
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
		
		int temp_guny[40];
		int temp_infrontof[40];
		int temp_back[40];
		int temp_right[40];
		int temp_left[40];
		int temp_bullet[40];
		int temp_gunx[40];
		int count;
		
		int boomx;
		int boomy;
		bool is_space;
	};
#endif // !MAP_H
}
