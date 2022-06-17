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
		void shot_OnMove();                                    // 子彈的移動
		void shot_OnMove2();                                   // 子彈的移動2
		void Getmapaddress(Cmap *m);
		void shot_OnShow();
		void Setspace(bool flag);
		int	gunx_up, guny_up, gunx_down, guny_down, gunx_right, guny_right, gunx_left, guny_left, mapx, mapy;
		int space_mapx, space_mapy;                            // 取得按下空白鍵時的XY
		bool isMovingright;
		bool isMovingleft;
		bool isMovingup;
		bool isMovingdown;
		int empty_bullet;                                      // 判斷子彈是否射完
		int bullet;                                            // 目前射出幾發子彈
		int infrontof1, left, right, back;
		int space;                                             // 0代表地圖上沒子彈
		int show;
		int temp_guny[40];                                     // 移動時的Y
		int temp_infrontof[40];                                // 發射時人物朝上
		int temp_back[40];                                     // 發射時人物朝下
		int temp_right[40];                                    // 發射時人物朝右
		int temp_left[40];                                     // 發射時人物朝左
		int temp_gunx[40];                                     // 移動時的X
		int shot_stop[40];                                     // 撞到物件
		int boomx;                                             // 爆炸畫面的X
		int boomy;                                             // 爆炸畫面的Y
		bool is_space;                                         // 是否和空白鍵                 
		bool right_isobject;                                   // 人物右邊是否沒物件
		bool left_isobject;                                    // 人物左邊是否沒物件
		bool up_isobject;                                      // 人物上邊是否沒物件
		bool down_isobject;                                    // 人物下邊是否沒物件
		int stop;
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
