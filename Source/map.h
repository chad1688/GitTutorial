

#include <vector>

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////
#ifndef MAP_H
#define MAP_H

	class Cmap {
	public:
		Cmap();
		void LoadBitmap();
		void OnMove_left();
		void OnMove_right();
		void OnMove_up();
		void OnMove_down();
		void OnMove_redbox_address();
		void OnMove_redbox_live();
		void OnShow();
		bool isObject(int people_x,int people_y);
		int redbox_appear3[2];
		int redbox_x[2];
		int redbox_y[2];
		int count_red_box3[2];
		int temp3[2];
		int x, y;
		int MH, MW, MW2;
	protected:
		CMovingBitmap map;
		CMovingBitmap wall;
		CMovingBitmap wall2;
		CMovingBitmap wall3;
		CMovingBitmap wall4;
		CMovingBitmap new_gun[2];
		int gun_index,wall1_index,wall2_index,wall3_index,wall4_index;
		int all_map[10][22] = { {4, 3, 3, 2, 3, 3, 2, 3, 3, 2, 0, 0, 2, 3, 3, 2, 3, 3, 2, 3, 3, 5},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{4, 3, 3, 2, 3, 3, 2, 3, 3, 2, 0, 0, 2, 3, 3, 2, 3, 3, 2, 3, 3, 5} };
		
	};
#endif // !MAP_H
}
