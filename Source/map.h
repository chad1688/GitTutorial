

#include <vector>

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
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
		void OnShow();
		bool isObject(int people_x,int people_y);
		int x, y;
	protected:
		CMovingBitmap map;
		CMovingBitmap wall;
		CMovingBitmap wall2;
		CMovingBitmap wall3;
		CMovingBitmap wall4;
		int all_map[10][22] = { {3, 2, 2, 1, 2, 2, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 2, 2, 1, 2, 2, 4},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{3, 2, 2, 1, 2, 2, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 2, 2, 1, 2, 2, 4} };
		int MH,MW,MW2;
	};
#endif // !MAP_H
}
