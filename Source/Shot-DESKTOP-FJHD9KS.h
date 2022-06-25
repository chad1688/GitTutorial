#include "map.h"
namespace game_framework {

#ifndef SHOT_H
#define SHOT_H

	class Cshot {
	public:
		Cshot();
		void LoadBitmap();
		void shot_OnMove();                         // 子彈的移動1
		void shot_OnMove2();                        // 子彈的移動2
		void shot_OnShow();
		void Setspace(bool flag);                   // 設定是否按空白鍵
		void Getmapaddress(Cmap *m);
		int	gunx_up, guny_up,gunx_down,guny_down,gunx_right,guny_right,gunx_left,guny_left, mapx, mapy;
		int isobject;
		int temp_gunx;                              // 移動時的X
		int temp_guny;                              // 移動時的Y
		bool isMovingright;
		bool isMovingleft;
		bool isMovingup;
		bool isMovingdown;
		int infrontof1, left, right, back;
		int space;                                  // 如果是0代表地圖上沒子彈
		int shot_stop;                              // 子彈撞到物件
		int temp_infrontof;
		int temp_right;
		int temp_left;
		int temp_back;
		bool is_space;                              // 是否按空白鍵
	protected:
		CMovingBitmap shot_infrontof;
		CMovingBitmap shot_left;
		CMovingBitmap shot_back;
		CMovingBitmap shot_right;
		Cmap *map;
		
		int temp_bullet;
		int count;
		
		
	};
#endif
}
