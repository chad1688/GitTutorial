

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
		int x, y;
	protected:
		CMovingBitmap map;
		
	};
#endif // !MAP_H
}
