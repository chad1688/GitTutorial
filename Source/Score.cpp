#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "string"
#include "Score.h"
//#include <iostream>
//#include <cstdlib>
//#include <ctime>

namespace game_framework {
	CScore::CScore() {
		score_len = 0;
	}

	void CScore::LoadBitmap()
	{
		for (int i = 0; i < 9; i++) {
			char *change;
			std::string temp_string = "RES/" + to_string(i) + ".bmp";
			change = &temp_string[0];
			score1[i].LoadBitmap(change, RGB(255, 255, 255));
			temp_string = "RES/" + to_string(i) + ".bmp";
			change = &temp_string[0];
			score2[i].LoadBitmap(change, RGB(255, 255, 255));
			temp_string = "RES/" + to_string(i) + ".bmp";
			change = &temp_string[0];
			score3[i].LoadBitmap(change, RGB(255, 255, 255));
			temp_string = "RES/" + to_string(i) + ".bmp";
			change = &temp_string[0];
			score4[i].LoadBitmap(change, RGB(255, 255, 255));
		}
		score1[9].LoadBitmap("RES/10.bmp", RGB(255, 255, 255));
		score2[9].LoadBitmap("RES/10.bmp", RGB(255, 255, 255));
		score3[9].LoadBitmap("RES/10.bmp", RGB(255, 255, 255));
		score4[9].LoadBitmap("RES/10.bmp", RGB(255, 255, 255));
	}

	void CScore::OnMove() {
		if (score / 10 >= 0 && score/10 < 10)
		{
			score_len = 1;
			score1[score % 10].SetTopLeft(400,30);
			score2[score / 10].SetTopLeft(350,30);
			score3[0].SetTopLeft(300,30);
			score4[0].SetTopLeft(250,30);
		}
		else if (score / 10 >= 10 && score / 10 < 100)
		{
			score_len = 2;
			score1[score % 10].SetTopLeft(400, 30);
			score2[(score / 10) % 10].SetTopLeft(350, 30);
			score3[score/100].SetTopLeft(300, 30);
			score4[0].SetTopLeft(250, 30);
		}
		else if (score / 10 >= 100 && score / 10 < 1000)
		{
			score_len = 3;
			score1[score % 10].SetTopLeft(400, 30);
			score2[(score / 10) % 10].SetTopLeft(350, 30);
			score3[(score / 100) % 10].SetTopLeft(300, 30);
			score4[score/1000].SetTopLeft(250, 30);
		}
	}

	void CScore::OnShow() {
		if (score_len == 1)
		{
			score1[score % 10].ShowBitmap();
			score2[score / 10].ShowBitmap();
			score3[0].ShowBitmap();
			score4[0].ShowBitmap();
		}
		else if (score_len == 2)
		{
			score1[score % 10].ShowBitmap();
			score2[(score / 10) % 10].ShowBitmap();
			score3[score / 100].ShowBitmap();
			score4[0].ShowBitmap();
		}
		else if (score_len == 3)
		{
			score1[score % 10].ShowBitmap();
			score2[(score / 10) % 10].ShowBitmap();
			score3[(score / 100) % 10].ShowBitmap();
			score4[score / 1000].ShowBitmap();
		}
	}

	void CScore::Over_Onshow() {
		if (score / 10 >= 0 && score / 10 < 10)
		{
			score_len = 1;
			score1[score % 10].SetTopLeft(350, 50);
			score2[score / 10].SetTopLeft(250, 50);
			score3[0].SetTopLeft(150, 50);
			score4[0].SetTopLeft(50, 50);
		}
		else if (score / 10 >= 10 && score / 10 < 100)
		{
			score_len = 2;
			score1[score % 10].SetTopLeft(350, 50);
			score2[(score / 10) % 10].SetTopLeft(250, 50);
			score3[score / 100].SetTopLeft(150, 50);
			score4[0].SetTopLeft(50, 50);
		}
		else if (score / 10 >= 100 && score / 10 < 1000)
		{
			score_len = 3;
			score1[score % 10].SetTopLeft(350, 50);
			score2[(score / 10) % 10].SetTopLeft(250, 50);
			score3[(score / 100) % 10].SetTopLeft(150, 50);
			score4[score / 1000].SetTopLeft(50, 50);
		}

		if (score_len == 1)
		{
			score1[score % 10].ShowBitmap(5);
			score2[score / 10].ShowBitmap(5);
			score3[0].ShowBitmap(5);
			score4[0].ShowBitmap(5);
		}
		else if (score_len == 2)
		{
			score1[score % 10].ShowBitmap(5);
			score2[(score / 10) % 10].ShowBitmap(5);
			score3[score / 100].ShowBitmap(5);
			score4[0].ShowBitmap(5);
		}
		else if (score_len == 3)
		{
			score1[score % 10].ShowBitmap(5);
			score2[(score / 10) % 10].ShowBitmap(5);
			score3[(score / 100) % 10].ShowBitmap(5);
			score4[score / 1000].ShowBitmap(5);
		}
	}
}