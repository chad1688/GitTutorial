
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////
#ifndef SCORE_H
#define SCORE_H

	class CScore {
	public:
		CScore();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void Over_Onshow();
		int score;
	protected:
		CMovingBitmap	score1[10];
		CMovingBitmap	score2[10];
		CMovingBitmap	score3[10];
		CMovingBitmap	score4[10];
		int score_len;
	};
#endif // !MAP_H
}
