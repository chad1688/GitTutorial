
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
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
