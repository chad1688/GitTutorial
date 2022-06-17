#include "map.h"
namespace game_framework {

#ifndef UZI_H
#define UZI_H

	class Cuzi {
	public:
		Cuzi();
		void LoadBitmap();
		void Getmapaddress(Cmap *m);
		void shot_OnMove();                           // 子彈的移動1
		void shot_OnMove2();                          // 子彈的移動2
		void shot_OnShow();
 		void Setspace(bool flag);                     // 設定是否按空白鍵
		int	gunx_up, guny_up, gunx_down, guny_down, gunx_right, guny_right, gunx_left, guny_left, mapx, mapy;
		bool isMovingright;
		bool isMovingleft;
		bool isMovingup;
		bool isMovingdown;
		int empty_bullet;                             // 判斷子彈是否射完
		int bullet;                                   // 目前射完的子彈數
		int infrontof1, left, right, back;
		int space;                                    // 如果是0代表場上沒子彈
		int temp_guny[100];
		int temp_infrontof[100];
		int temp_back[100];
		int temp_right[100];
		int temp_left[100];
		int temp_gunx[100];
		int shot_stop[100];
		bool is_space;
	protected:
		CMovingBitmap shot_infrontof[100];
		CMovingBitmap shot_left[100];
		CMovingBitmap shot_back[100];
		CMovingBitmap shot_right[100];
		Cmap *map;
		int count;
	};
#endif 
}
