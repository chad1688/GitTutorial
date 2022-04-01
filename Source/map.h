

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
		void OnShow();
		int x, y;
	protected:
		CMovingBitmap map;
		
	};
#endif // !MAP_H
}
