#include "map.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
#ifndef SHOT_H
#define SHOT_H

	class Cshot {
	public:
		Cshot();
		void LoadBitmap();
		void shot_OnMove();
		void shot_OnMove2();
		void shot_OnShow();
		void Setspace(bool flag);
		void Getmapaddress(Cmap *m);
		int	gunx_up, guny_up,gunx_down,guny_down,gunx_right,guny_right,gunx_left,guny_left, mapx, mapy;
		int isobject;
		int temp_gunx;
		int temp_guny;
		bool isMovingright;
		bool isMovingleft;
		bool isMovingup;
		bool isMovingdown;
		int infrontof1, left, right, back;
		int space;
		int shot_stop;
		int temp_infrontof;
		int temp_right;
		int temp_left;
		int temp_back;
		bool is_space;
	protected:
		CMovingBitmap shot_infrontof;
		CMovingBitmap shot_left;
		CMovingBitmap shot_back;
		CMovingBitmap shot_right;
		Cmap *map;
		
		int temp_bullet;
		int count;
		
		
	};
#endif // !MAP_H
}
