#include "map.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////
#ifndef UZI_H
#define UZI_H

	class Cuzi {
	public:
		Cuzi();
		void LoadBitmap();
		void Getmapaddress(Cmap *m);
		void shot_OnMove();
		void shot_OnMove2();
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
	protected:
		CMovingBitmap shot_infrontof[100];
		CMovingBitmap shot_left[100];
		CMovingBitmap shot_back[100];
		CMovingBitmap shot_right[100];
		//CAnimation  shot_infrontof;
		//CAnimation	shot_left;
		//CAnimation	shot_right;
		//CAnimation	shot_back;
		Cmap *map;
		
		int temp_guny[100];
		int temp_infrontof[100];
		int temp_back[100];
		int temp_right[100];
		int temp_left[100];
		int temp_bullet[100];
		int temp_gunx[100];
		int count;
		bool is_space;
	};
#endif // !MAP_H
}
