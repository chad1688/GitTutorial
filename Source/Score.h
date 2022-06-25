
namespace game_framework {
#ifndef SCORE_H
#define SCORE_H

	class CScore {
	public:
		CScore();
		void LoadBitmap();
		void OnMove();       // 分數的變化
		void OnShow();
		void Over_Onshow();  // 在Gamestateover裡面show
		int score;
	protected:
		CMovingBitmap	score1[10];
		CMovingBitmap	score2[10];
		CMovingBitmap	score3[10];
		CMovingBitmap	score4[10];
		int score_len;
	};
#endif 
}
