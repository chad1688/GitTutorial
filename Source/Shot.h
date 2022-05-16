#include "map.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
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
		int	gunx, guny, mapx, mapy;
		int isobject;
		int temp_gunx;
		int temp_guny;
		bool isMovingright;
		bool isMovingleft;
		bool isMovingup;
		bool isMovingdown;
		int infrontof1, left, right, back;
		int space;
	protected:
		CMovingBitmap shot_infrontof;
		CMovingBitmap shot_left;
		CMovingBitmap shot_back;
		CMovingBitmap shot_right;
		Cmap *map;
		int temp_infrontof;
		int temp_right;
		int temp_left;
		int temp_back;
		int temp_bullet;
		int count;
		
		bool is_space;
	};
#endif // !MAP_H
}
