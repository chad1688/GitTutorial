/*
 * mygame.cpp: 本檔案儲遊戲本身的class的implementation
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 *   2002-03-04 V3.1
 *          Add codes to demostrate the use of CMovingBitmap::ShowBitmap(CMovingBitmap &).
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *      2. Demo the use of CInteger in CGameStateRun.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *      1. Add codes to display IDC_GAMECURSOR in GameStateRun.
 *   2006-02-08 V4.2
 *      1. Revise sample screens to display in English only.
 *      2. Add code in CGameStateInit to demo the use of PostQuitMessage().
 *      3. Rename OnInitialUpdate() -> OnInit().
 *      4. Fix the bug that OnBeginState() of GameStateInit is not called.
 *      5. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      6. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2006-12-30
 *      1. Bug fix: fix a memory leak problem by replacing PostQuitMessage(0) as
 *         PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0).
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
 *   2010-03-23 V4.6
 *      1. Demo MP3 support: use lake.mp3 to replace lake.wav.
*/

#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"



namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	/////////////////////////////////////////////////////////////////////////////

	CGameStateInit::CGameStateInit(CGame *g)
		: CGameState(g)
	{
		//choose_map = 0;
	}

	void CGameStateInit::OnInit()
	{
		//
		// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
		//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
		//
		ShowInitProgress(0);	                                     // 一開始的loading進度為0%
		//
		// 開始載入資料
		//
		logo.LoadBitmap("RES/Boxhead_title.bmp");
		start.LoadBitmap("RES/start2.bmp", RGB(255, 255, 255));
		start2.LoadBitmap("RES/start3.bmp", RGB(255, 255, 255));
		introduction.LoadBitmap("RES/introduction.bmp", RGB(255, 255, 255));
		introduction2.LoadBitmap("RES/introduction2.bmp", RGB(255, 255, 255));
		introduction_text.LoadBitmap("RES/introduction_text.bmp", RGB(255, 255, 255));
		about.LoadBitmap("RES/about.bmp", RGB(255, 255, 255));
		about2.LoadBitmap("RES/about2.bmp", RGB(255, 255, 255));
		about_text.LoadBitmap("RES/about_text.bmp", RGB(255, 255, 255));
		arrow_back.LoadBitmap("RES/arrow_back.bmp", RGB(255, 255, 255));
		background.LoadBitmap("RES/BG.bmp");
		text.LoadBitmap("RES/text.bmp", RGB(255, 255, 255));
		character.LoadBitmap("RES/518.bmp");
		arrow1.LoadBitmap("RES/arrow1.bmp", RGB(255, 255, 255));
		arrow2.LoadBitmap("RES/arrow2.bmp", RGB(255, 255, 255));
		arrow3.LoadBitmap("RES/arrow3.bmp", RGB(255, 255, 255));
		arrow4.LoadBitmap("RES/arrow4.bmp", RGB(255, 255, 255));
		map1.LoadBitmap("RES/456.bmp");
		map2.LoadBitmap("RES/436.bmp");
		map3.LoadBitmap("RES/465.bmp");
		CAudio::Instance()->Load(AUDIO_END, "sounds\\World.End.mp3");
		Sleep(300);				                                  // 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
		//
		// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
		//
		
	}

	void CGameStateInit::OnBeginState()
	{
		choose_state = false;
		s->choose_map = 0;
	}

	void CGameStateInit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_SPACE = ' ';
		if (nChar == KEY_SPACE)
			choose_state = true;
	}

	void CGameStateInit::OnLButtonUp(UINT nFlags, CPoint point)
	{
		touch_arrow1 = false;
		touch_arrow3 = false;
		touch_back = false;
		if (touch_start == true)
		{
			touch_start = false;
		}

		if (touch_introduction == true)
		{
			touch_introduction = false;
		}

		if (touch_about == true)
		{
			touch_about = false;
		}
	}

	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		if (choose_state == true)
		{
			if (point.x >= 597 && point.x <= 617 && point.y >= 300 && point.y <= 330)
			{
				touch_arrow1 = true;
				touch_arrow3 = false;
				temp = 1;
			}
			else if (point.x >= 261 && point.x <= 281 && point.y >= 300 && point.y <= 330)
			{
				touch_arrow1 = false;
				touch_arrow3 = true;
				temp2 = 1;
			}
			else
			{
				touch_arrow1 = false;
				touch_arrow3 = false;
			}

			if (point.x >= 300 && point.x <= 587 && point.y >= 250 && point.y <= 400)
			{
				GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
			}
		}

		if (choose_state == true || select_purpose == 1 || select_purpose == 2)
		{
			if (point.x >= 20 && point.x <= 141 && point.y >= 410 && point.y <= 450)
			{
				touch_back = true;
			}
		}

		if (choose_state == false)
		{
			if (point.x >= 260 && point.x <= 381 && point.y >= 250 && point.y <= 310)
			{
				touch_start = true;
				touch_introduction = false;
				touch_about = false;
			}
			if (point.x >= 220 && point.x <= 420 && point.y >= 320 && point.y <= 380)
			{
				touch_introduction= true;
				touch_start = false;
				touch_about = false;
			}
			if (point.x >= 260 && point.x <= 381 && point.y >= 390 && point.y <= 450)
			{
				touch_about = true;
				touch_start = false;
				touch_introduction = false;
			}
		}
	}

	void CGameStateInit::OnShow()
	{
		//
		// 貼上圖片
		//

		if (touch_arrow1 == false && temp == 1)
		{
			temp = 0;
			if (s->choose_map < 2)
				s->choose_map += 1;
			else
				s->choose_map = 0;
		}

		if (touch_arrow3 == false && temp2 == 1)
		{
			temp2 = 0;
			if (s->choose_map > 0)
				s->choose_map -= 1;
			else
				s->choose_map = 3;
		}

		if (choose_state == true)
		{
			if (touch_back == true)
			{
				choose_state = false;
			}
			background.ShowBitmap();
			text.SetTopLeft(20, 5);
			text.ShowBitmap();
			character.SetTopLeft(50, 250);
			character.ShowBitmap();
			arrow_back.SetTopLeft(20, 410);
			arrow_back.ShowBitmap();
			if (s->choose_map == 0)
			{
				map1.SetTopLeft(300, 250);
				map1.ShowBitmap();
			}
			else if (s->choose_map == 1)
			{
				map2.SetTopLeft(300, 250);
				map2.ShowBitmap();
			}
			else
			{
				map3.SetTopLeft(300, 250);
				map3.ShowBitmap();
			}

			if (touch_arrow1 == false)
			{
				arrow1.SetTopLeft(597, 300);
				arrow1.ShowBitmap();
			}
			else
			{
				arrow2.SetTopLeft(597, 300);
				arrow2.ShowBitmap();
			}
			if (touch_arrow3 == false)
			{
				arrow3.SetTopLeft(260, 300);
				arrow3.ShowBitmap();
			}
			else
			{
				arrow4.SetTopLeft(260, 300);
				arrow4.ShowBitmap();
			}
		}
		else if (select_purpose == 1)
		{
			if (touch_back == true)
			{
				select_purpose = 0;
			}
			introduction_text.ShowBitmap();
			arrow_back.SetTopLeft(20, 410);
			arrow_back.ShowBitmap();
		}
		else if (select_purpose == 2)
		{
			if (touch_back == true)
			{
				select_purpose = 0;
			}
			about_text.ShowBitmap();
			arrow_back.SetTopLeft(20, 410);
			arrow_back.ShowBitmap();
		}
		else
		{
			background.ShowBitmap();
			logo.SetTopLeft((SIZE_X - logo.Width()) / 2, 10);
			logo.ShowBitmap();
			start.SetTopLeft((SIZE_X - start.Width()) / 2, 250);
			start2.SetTopLeft((SIZE_X - start2.Width()) / 2, 250);
			introduction.SetTopLeft((SIZE_X - introduction.Width()) / 2, 320);
			introduction2.SetTopLeft((SIZE_X - introduction2.Width()) / 2, 320);
			about.SetTopLeft((SIZE_X - about.Width()) / 2, 390);
			about2.SetTopLeft((SIZE_X - about2.Width()) / 2, 390);
			if (touch_start == true)
			{
				start2.ShowBitmap();
				touch[0] = 1;
			}
			else
			{
				start.ShowBitmap();
				if (touch[0] == 1)
				{
					touch[0] = 0;
					choose_state = true;
					CAudio::Instance()->Play(AUDIO_END);
				}
			}
			
			if (touch_introduction == true)
			{
				introduction2.ShowBitmap();
				touch[1] = 1;
			}
			else
			{
				introduction.ShowBitmap();
				if (touch[1] == 1)
				{
					touch[1] = 0;
					select_purpose = 1;
				}
			}

			if (touch_about == true)
			{
				about2.ShowBitmap();
				touch[2] = 1;
			}
			else
			{
				about.ShowBitmap();
				if (touch[2] == 1)
				{
					touch[2] = 0;
					select_purpose =2;
				}
			}
			
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	/////////////////////////////////////////////////////////////////////////////

	CGameStateOver::CGameStateOver(CGame *g)
		: CGameState(g)
	{
	}

	void CGameStateOver::OnMove()
	{
		score.score = s->score;
	}

	void CGameStateOver::OnBeginState()
	{
		CAudio::Instance()->Play(AUDIO_END);
	}

	void CGameStateOver::OnLButtonDown(UINT nFlags, CPoint point)
	{
		if (point.x >= 100 && point.x <= 221 && point.y >= 350 && point.y <= 410)
		{
			GotoGameState(GAME_STATE_RUN);
		}
		if (point.x >= 400 && point.x <= 521 && point.y >= 350 && point.y <= 410)
		{
			GotoGameState(GAME_STATE_INIT);
		}
	}

	void CGameStateOver::OnLButtonUp(UINT nFlags, CPoint point)
	{

	}

	void CGameStateOver::OnInit()
	{
		//
		// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
		//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
		//
		ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
		//
		// 開始載入資料
		//
		//
		// 最終進度為100%
		//
		ShowInitProgress(100);
		lose.LoadBitmap("RES/lose.bmp", RGB(255, 255, 255));
		retry.LoadBitmap("RES/retry.bmp", RGB(255, 255, 255));
		menu.LoadBitmap("RES/menu.bmp", RGB(255, 255, 255));
		win.LoadBitmap("RES/win.bmp", RGB(255, 255, 255));
		score.LoadBitmap();
	}

	void CGameStateOver::OnShow()
	{
		win.ShowBitmap();
		retry.SetTopLeft(100, 375);
		retry.ShowBitmap();
		menu.SetTopLeft(400, 375);
		menu.ShowBitmap();
		score.Over_Onshow();
	}

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	/////////////////////////////////////////////////////////////////////////////

	CGameStateRun::CGameStateRun(CGame *g)
		: CGameState(g)
	{
		map.choose_map = s->choose_map;
		people.choose_map = s->choose_map;
		enemy.choose_map = s->choose_map;
	}

	CGameStateRun::~CGameStateRun()
	{

	}

	void CGameStateRun::OnBeginState()
	{
		map.choose_map = s->choose_map;
		people.choose_map = s->choose_map;
		enemy.choose_map = s->choose_map;
		level = 0;
		for (int i = 0; i < 100; i++)
		{
			enemy.blood[i] = 0;
			enemy.shoted[i] = 0;
			enemy.enemy_die[i] = 0;
			enemy.is_enemy[i] = 2;
		}
		for (int i = 1; i < 3; i++)
		{
			arms.my_arms[i] = 0;
		}
		arms.now_arms = 0;
		people.x = 300;
		people.y = 300;
		map.x = 0;
		map.y = 0;
		map.gun_index = 0;
		people.blood_index = 0;
		music_stop4 = 0;
		people.monster_touch = false;
		people.die = false;
		people.hit = 0;
		people.count_hit = 30;
		people.up_die.Reset();
		people.down_die.Reset();
		people.right_die.Reset();
		people.left_die.Reset();
		s->special = false;
		s->special2 = false;
		enemy.score = 0;
		count2 = 0;
		CAudio::Instance()->Play(AUDIO_END);
	}

	void CGameStateRun::OnMove()							// 移動遊戲元素
	{
		die_count++;
		if (people.die == false)
		{
			map.OnMove_redbox_address();
			//
			//
			// 移動人物
			//
			if (people.GetisMovingup() && !people.GetisMovingdown() && !people.GetisMovingleft() && !people.GetisMovingright()) {
				if (map.isObject(people.GetX1(), people.GetY1() - 1) && map.isObject(people.GetX2(), people.GetY1() - 1)) {
					people.OnMove();
					rocket.up_isobject = false;
				}
				else
				{
					rocket.up_isobject = true;
				}
			}
			if (people.GetisMovingright() && !people.GetisMovingdown() && !people.GetisMovingleft() && !people.GetisMovingup()) {
				if (map.isObject(people.GetX2() + 10, people.GetY2()) && map.isObject(people.GetX2() + 10, people.GetY1())) {
					people.OnMove();
					rocket.right_isobject = false;
				}
				else
				{
					rocket.right_isobject = true;
				}
			}
			if (people.GetisMovingleft() && !people.GetisMovingdown() && !people.GetisMovingup() && !people.GetisMovingright()) {
				if (map.isObject(people.GetX1() - 1, people.GetY1()) && map.isObject(people.GetX1() - 1, people.GetY2())) {
					people.OnMove();
					rocket.left_isobject = false;
				}
				else
				{
					rocket.left_isobject = true;
				}
			}
			if (people.GetisMovingdown() && !people.GetisMovingup() && !people.GetisMovingleft() && !people.GetisMovingright()) {
				if (map.isObject(people.GetX2(), people.GetY2() + 10) && map.isObject(people.GetX1(), people.GetY2() + 10)) {
					people.OnMove();
					rocket.down_isobject = false;
				}
				else
				{
					rocket.down_isobject = true;
				}
			}
			rocket.stop = people.stop;
			//
			//
			// 人物觸碰紅色盒子
			//
			people.people_touch_redbox();
			if (people.pickup == true)
			{
				CAudio::Instance()->Play(AUDIO_PICKUP);
				people.pickup = false;
			}
			arms.add_arms = people.add_arms;
			for (int i = 0; i < 4; i++)
				map.redbox_appear3[i] = people.red_box_appear3[i];
			map.OnMove_redbox_live();
			for (int i = 0; i < 4; i++)
				people.red_box_appear3[i] = map.redbox_appear3[i];
			//
			//
			// 人物扣血
			//
			people.blood_OnMove();
		}
		else
		{
			if (music_stop4 == 0)
				music_stop4 = 1;
			people.blood_OnMove();
		}
		//
		//
		// 播放死亡音效
		//
		if (music_stop4 == 1)
		{
			die_count = 0;
			CAudio::Instance()->Play(AUDIO_DIE);
			music_stop4 = 2;
		}
		//
		//
		// 傳分數給GameStateRun
		//
		if (die_count >= 90 && music_stop4 == 2)
		{
			s->score = enemy.score;
			GotoGameState(GAME_STATE_OVER);
		}
		
		uzi.isMovingright = people.GetisMovingright();
		uzi.isMovingleft = people.GetisMovingleft();
		uzi.isMovingup = people.GetisMovingup();
		uzi.isMovingdown = people.GetisMovingdown();
		uzi.infrontof1 = people.infrontof1;
		uzi.right = people.right;
		uzi.left = people.left;
		uzi.back = people.back;
		uzi.gunx_up = people.GetX2() - 5;
		uzi.guny_up = people.GetY1() + 60;
		uzi.gunx_down = people.GetX1();
		uzi.guny_down = people.GetY2() - 60;
		uzi.gunx_right = people.GetX2() - 60;
		uzi.guny_right = people.GetY2() - 25;
		uzi.gunx_left = people.GetX1() - 30;
		uzi.guny_left = people.GetY1() + 10;
		shot.isMovingright = people.GetisMovingright();
		shot.isMovingleft = people.GetisMovingleft();
		shot.isMovingup = people.GetisMovingup();
		shot.isMovingdown = people.GetisMovingdown();
		shot.infrontof1 = people.infrontof1;
		shot.right = people.right;
		shot.left = people.left;
		shot.back = people.back;
		shot.gunx_up = people.GetX2() - 5;
		shot.guny_up = people.GetY1() + 60;
		shot.gunx_down = people.GetX1();
		shot.guny_down = people.GetY2() - 60;
		shot.gunx_right = people.GetX2() - 60;
		shot.guny_right = people.GetY2() - 25;
		shot.gunx_left = people.GetX1() - 30;
		shot.guny_left = people.GetY1() + 10;
		rocket.isMovingright = people.GetisMovingright();
		rocket.isMovingleft = people.GetisMovingleft();
		rocket.isMovingup = people.GetisMovingup();
		rocket.isMovingdown = people.GetisMovingdown();
		rocket.infrontof1 = people.infrontof1;
		rocket.right = people.right;
		rocket.left = people.left;
		rocket.back = people.back;
		rocket.gunx_up = people.GetX2() - 30;
		rocket.guny_up = people.GetY1() + 60;
		rocket.gunx_down = people.GetX1();
		rocket.guny_down = people.GetY2() - 60;
		rocket.gunx_right = people.GetX2() - 60;
		rocket.guny_right = people.GetY2() - 30;
		rocket.gunx_left = people.GetX1() + 30;
		rocket.guny_left = people.GetY1();
		arms.die = people.die;
		arms.OnMove();
		count_music_shot++;
		count_music_uzi++;
		count_music_rocket++;
		//
		//
		// 播放射擊音效
		//
		if (shot.space != 0 && arms.now_arms == 0 && music_stop2 == false)
		{
			CAudio::Instance()->Play(AUDIO_PISTOL, true);
			music_stop2 = true;
			count_music_shot = 0;
		}
		else if (shot.space == 0 && count_music_shot >= 15)
		{
			CAudio::Instance()->Stop(AUDIO_PISTOL);
			music_stop2 = false;
		}

		if (uzi.space != 0 && arms.now_arms == 1 && music_stop == false)
		{
			CAudio::Instance()->Play(AUDIO_UZI, true);
			music_stop = true;
			count_music_uzi = 0;
		}
		else if (uzi.space == 0 && count_music_uzi >= 15)
		{
			CAudio::Instance()->Stop(AUDIO_UZI);
			music_stop = false;
		}

		if (rocket.space != 0 && arms.now_arms == 2 && music_stop3 == false)
		{
			CAudio::Instance()->Play(AUDIO_ROCKET, true);
			music_stop3 = true;
			count_music_rocket = 0;
		}
		else if (rocket.space == 0 && count_music_rocket >= 20)
		{
			CAudio::Instance()->Stop(AUDIO_ROCKET);
			music_stop3 = false;
		}

		if (rocket.show != 0)
		{
			CAudio::Instance()->Play(AUDIO_EXPLOSION);
		}


		people.add_arms = arms.add_arms;
		show_text_x = people.GetX1() + 20;
		show_text_y = people.GetY1() - 30;
		show_text_x2 = people.GetX1() + 15;
		show_text_y2 = people.GetY1() - 30;
		show_text_x3 = people.GetX1() + 10;
		show_text_y3 = people.GetY1() - 30;
		total_blood = 0;
		count++;
		count2++;
		//
		//
		// 計算目前Level以及殭屍生成
		//
		if (level == 1)
		{
			if (enemy.large < 10 && count >= 45)
			{
				enemy.born();
				count = 0;
			}
		}
		else if (level == 2)
		{
			if (enemy.large < 20 && count >= 45)
			{
				enemy.born();
				count = 0;
			}
		}
		else if (level == 3)
		{
			if (enemy.large < 30 && count >= 45)
			{
				enemy.born();
				count = 0;
			}
		}
		else if (level == 4)
		{
			if (enemy.large < 40 && count >= 45)
			{
				enemy.born();
				count = 0;
			}
		}
		else if (level == 5)
		{
			if (enemy.large < 50 && count >= 45)
			{
				enemy.born();
				count = 0;
			}
		}
		else if (level == 6)
		{
			if (enemy.large < 60 && count >= 45)
			{
				enemy.born();
				count = 0;
			}
		}
		else if (level == 7)
		{
			if (enemy.large < 70 && count >= 45)
			{
				enemy.born();
				count = 0;
			}
		}
		else if (level == 8)
		{
			if (enemy.large < 80 && count >= 45)
			{
				enemy.born();
				count = 0;
			}
		}
		else if (level == 9)
		{
			if (enemy.large < 90 && count >= 45)
			{
				enemy.born();
				count = 0;
			}
		}
		else if (level == 10)
		{
			if (enemy.large < 100 && count >= 45 && (s->special == false || s->special2 == false))
			{
				enemy.born();
				count = 0;
			}
		}
		else if (level == 11)
		{
			s->special = true;
			s->score = enemy.score;
			GotoGameState(GAME_STATE_OVER);
		}
		
		//
		//
		// 觸發密技
		//
		if (s->special == true && s->special2 == true && enemy.score != 4500)
		{
			level = 10;
			enemy.large = 1;
			enemy.score = 4500;
			count2 = 0;
			for (int i = 0; i < 100; i++)
			{
				enemy.blood[i] = 0;
				enemy.enemy_x[i] = 1800;
				enemy.enemy_y[i] = 1800;
			}
		}

		for (int i = 0; i < enemy.large; i++)
		{
			total_blood += enemy.blood[i];
		}

		//
		//
		// 播放殭屍被打音效
		//
		for (int i = 0; i < enemy.large; i++)
		{
			if (enemy.shoted[i] != 0 && temp_i == 101)
			{
				CAudio::Instance()->Play(AUDIO_ZOMBIE_HIT, true);
				temp_i = i;
			}
		}

		if (temp_i != 101)
		{
			if (enemy.shoted[temp_i] == 0 || total_blood <= 0)
			{
				CAudio::Instance()->Stop(AUDIO_ZOMBIE_HIT);
				temp_i = 101;
			}
		}
		//
		//
		// 殭屍扣血以及算分
		//
		enemy.blood_on_move();
		score.score = enemy.score;
		score.OnMove();

		//
		//
		// 判斷是否要進下一個Level
		//
		if (total_blood > 0 && enemy.large > 0)
		{
			enemy.On_Move();
			people.hit_OnMove();
			people.large = enemy.large;
		}
		else if (total_blood <= 0 && enemy.large > 0 && kill_all == 0)
		{
			kill_all = 1;
			for (int i = 0; i < enemy.large; i++)
			{
				enemy.shoted[i] = 0;
				enemy.enemy_die[i] = 0; 
				enemy.is_enemy[i] = 2;
			}
			count2 = 0;
		}

		if (count2 == 180)
		{
			if (level <= 10)
			{
				kill_all = 0;
				enemy.large = 0;
				level++;
			}
		}

		for (int i = 0; i < enemy.large; i++)
		{
			people.enemy_x[i] = enemy.enemy_x[i];
			people.enemy_y[i] = enemy.enemy_y[i];
		}
	

	}

	void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
	{
		//
		// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
		//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
		//
		ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
		//
		// 開始載入資料
		//
		people.LoadBitmap();
		people.LoadAnimation();
		shot.LoadBitmap();
		uzi.LoadBitmap();
		rocket.LoadBitmap();
		whiltbackground.LoadBitmap("RES/whilt.bmp");
		enemy.LoadAnimation();
		enemy.LoadBitmap();
		//
		// 完成部分Loading動作，提高進度
		//
		ShowInitProgress(50);
		Sleep(300); // 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
		//
		// 繼續載入其他資料
		//
		map.LoadBitmap();
		score.LoadBitmap();
		CAudio::Instance()->Load(AUDIO_DING, "sounds\\ding.wav");	// 載入編號0的聲音ding.wav
		CAudio::Instance()->Load(AUDIO_LAKE, "sounds\\lake.mp3");	// 載入編號1的聲音lake.mp3
		CAudio::Instance()->Load(AUDIO_NTUT, "sounds\\ntut.mid");	// 載入編號2的聲音ntut.mid
		CAudio::Instance()->Load(AUDIO_HITFLOOR, "sounds\\HitFloor.mp3");
		CAudio::Instance()->Load(AUDIO_PICKUP, "sounds\\Pickup.mp3");
		CAudio::Instance()->Load(AUDIO_PISTOL, "sounds\\Pistol.Fire.mp3");
		CAudio::Instance()->Load(AUDIO_ROCKET, "sounds\\Rocket.Fire.mp3");
		CAudio::Instance()->Load(AUDIO_UZI, "sounds\\UZI.Fire.mp3");
		CAudio::Instance()->Load(AUDIO_ZOMBIE_HIT, "sounds\\Zombie.Hit.mp3");
		CAudio::Instance()->Load(AUDIO_EXPLOSION, "sounds\\Explosion.mp3");
		CAudio::Instance()->Load(AUDIO_DIE, "sounds\\die.mp3");
		
		//CAudio::Instance()->Load(AUDIO_END, "sounds\\World.End.mp3");
		//
		// 此OnInit動作會接到CGameStaterOver::OnInit()，所以進度還沒到100%
		//
		people.Getmapaddress(&map);
		shot.Getmapaddress(&map);
		uzi.Getmapaddress(&map);
		rocket.Getmapaddress(&map);
		arms.GetShotAddress(&shot);
		arms.GetUziAddress(&uzi);
		arms.GetRocketAddress(&rocket);
		enemy.Getmapaddress(&map);
		enemy.Getpeopleaddress(&people);
		enemy.Getrocketaddress(&rocket);
		enemy.Getshotaddress(&shot);
		enemy.Getuziaddress(&uzi);
	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		const char KEY_SPACE = 0x20;//keyboard空白建
		const char KEY_CHANGE = 0x4D;
		const char KEY_SPECIAL1 = 0x11;
		const char KEY_SPECIAL2 = 0x44;
		if (nChar == KEY_LEFT)
			people.SetMovingLeft(true);
		if (nChar == KEY_RIGHT)
			people.SetMovingRight(true);
		if (nChar == KEY_UP)
			people.SetMovingUp(true);
		if (nChar == KEY_DOWN)
			people.SetMovingDown(true);
		if (nChar == KEY_SPACE) {
			uzi.Setspace(true);
			shot.Setspace(true);
			rocket.Setspace(true);
		}
		if (nChar == KEY_CHANGE) {
			arms.change_arms = true;
		}
		if (nChar == KEY_SPECIAL1) {
			s->special = true;
		}
		if (nChar == KEY_SPECIAL2) {
			s->special2 = true;
		}
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		const char KEY_SPACE = 0x20;//keyboard空白建
		const char KEY_CHANGE = 0x4D;
		if (nChar == KEY_LEFT)
			people.SetMovingLeft(false);
		if (nChar == KEY_RIGHT)
			people.SetMovingRight(false);
		if (nChar == KEY_UP)
			people.SetMovingUp(false);
		if (nChar == KEY_DOWN)
			people.SetMovingDown(false);
		if (nChar == KEY_SPACE) {
			uzi.Setspace(false);
			shot.Setspace(false);
			rocket.Setspace(false);
		}
		if (nChar == KEY_CHANGE) {
			arms.change_arms = false;
		}
	}

	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
	{
		
		//people.SetMovingLeft(true);
	}

	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
	{
		
		//people.SetMovingLeft(false);
	}

	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
	{
		// 沒事。如果需要處理滑鼠移動的話，寫code在這裡
	}

	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
	{
		
	}

	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
	{
		
	}

	void CGameStateRun::OnShow()
	{
		total_object = 0;
		//
		//  注意：Show裡面千萬不要移動任何物件的座標，移動座標的工作應由Move做才對，
		//        否則當視窗重新繪圖時(OnDraw)，物件就會移動，看起來會很怪。換個術語
		//        說，Move負責MVC中的Model，Show負責View，而View不應更動Model。
		//
		//
		//  貼上人物 殭屍 紅色盒子 印出撿起什麼槍以及Level
		//
		whiltbackground.ShowBitmap();
		map.OnShow();
		arms.OnShow();
		people.OnShow();					
		for (int i = 0; i < 3; i++)
		{
			total_object += object_appear[i];
		}

		int total_temp = 0;
		for (int i = 0; i < 3; i++)
		{
			total_temp += temp[i];
		}

		if (arms.now_arms == 0 && people.die == false) {
			CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
			CFont f, *fp;
			f.CreatePointFont(100, "Times New Roman");	// 產生 font f; 160表示16 point的字
			fp = pDC->SelectObject(&f);					// 選用 font f
			pDC->SetBkMode(1);
			pDC->SetBkColor(RGB(255, 255, 255));
			pDC->SetTextColor(RGB(0, 0, 0));
			char str[80];								// Demo 數字對字串的轉換
			sprintf(str, "Pistol");
			pDC->TextOut(show_text_x, show_text_y, str);
			pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
			CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
		}
		if (arms.now_arms == 1 && people.die == false) {
			CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
			CFont f, *fp;
			f.CreatePointFont(100, "Times New Roman");	// 產生 font f; 160表示16 point的字
			fp = pDC->SelectObject(&f);					// 選用 font f
			pDC->SetBkMode(1);
			pDC->SetBkColor(RGB(255, 255, 255));
			pDC->SetTextColor(RGB(0, 0, 0));
			char str[80];								// Demo 數字對字串的轉換
			sprintf(str, "UZI:%d",100 - uzi.bullet);
			pDC->TextOut(show_text_x2, show_text_y2, str);
			pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
			CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
		}

		if (arms.now_arms == 2 && people.die == false) {
			CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
			CFont f, *fp;
			f.CreatePointFont(100, "Times New Roman");	// 產生 font f; 160表示16 point的字
			fp = pDC->SelectObject(&f);					// 選用 font f
			pDC->SetBkMode(1);
			pDC->SetBkColor(RGB(255, 255, 255));
			pDC->SetTextColor(RGB(0, 0, 0));
			char str[80];								// Demo 數字對字串的轉換
			sprintf(str, "Rocket:%d", 40 - rocket.bullet);
			pDC->TextOut(show_text_x3, show_text_y3, str);
			pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
			CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
		}

		if (arms.r == 1 && arms.show_text == 1 && people.die == false) {
			if (total_object > 1 && object_appear[0] == 1 && stop[0] == 0)
			{
				if (temp[0] < temp[1] || temp[0] < temp[2])
					object_y[0] -= 40 * (total_object - 1);
				stop[0] = 1;
			}
			else if(temp[0] == 0)
			{
				temp[0] = total_temp + 1;
				object_appear[0] = 1;
				object_y[0] = 400;

			}
			CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
			CFont f, *fp;
			f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
			fp = pDC->SelectObject(&f);					// 選用 font f
			pDC->SetBkMode(1);
			pDC->SetBkColor(RGB(255, 255, 255));
			pDC->SetTextColor(RGB(0, 0, 0));
			char str[80];								// Demo 數字對字串的轉換
			sprintf(str, "Picked up UZI");
			pDC->TextOut(250, object_y[0], str);
			pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
			CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
		}
		else
		{
			temp[0] = 0;
			stop[0] = 0;
			object_appear[0] = 0;
		}
		if (arms.r == 2 && arms.show_text == 1 && people.die == false) {
			if (total_object > 1 && object_appear[1] == 1 && stop[1] == 0)
			{
				if (temp[1] < temp[0] || temp[1] < temp[2])
					object_y[1] -= 40 * (total_object - 1);
				stop[1] = 1;
			}
			else if (temp[1] == 0)
			{
				temp[1] = total_temp + 1;
				object_appear[1] = 1;
				object_y[1] = 400;
			}
			CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
			CFont f, *fp;
			f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
			fp = pDC->SelectObject(&f);					// 選用 font f
			pDC->SetBkMode(1);
			pDC->SetBkColor(RGB(255, 255, 255));
			pDC->SetTextColor(RGB(0, 0, 0));
			char str[80];								// Demo 數字對字串的轉換
			sprintf(str, "Picked up Rocket");
			pDC->TextOut(240, object_y[1], str);
			pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
			CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
		}
		else
		{
			temp[1] = 0;
			stop[1] = 0;
			object_appear[1] = 0;
		}

		if (count2 < 30)
		{
			if (total_object > 1 && object_appear[2] == 1 && stop[2] == 0 )
			{
				if(temp[2] < temp[1] || temp[2] < temp[0])
					object_y[2] -= 40 * (total_object-1);
				stop[2] = 1;
			}
			else if (temp[2] == 0)
			{
				temp[2] = total_temp + 1;
				object_appear[2] = 1;
				object_y[2] = 400;
			}
			CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
			CFont f, *fp;
			f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
			fp = pDC->SelectObject(&f);					// 選用 font f
			pDC->SetBkMode(1);
			pDC->SetBkColor(RGB(255, 255, 255));
			pDC->SetTextColor(RGB(0, 0, 0));
			char str[80];								// Demo 數字對字串的轉換
			if (s->special == true)
			{
				sprintf(str, "----Level %d----", level);
			}
			else if(level<10)
			{
				sprintf(str, "----Level %d----", level + 1);
			}
			pDC->TextOut(250, object_y[2], str);
			pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
			CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
		}
		else
		{
			temp[2] = 0;
			stop[2] = 0;
			object_appear[2] = 0;
		}
		//
		//  貼上左上及右下角落的圖
		//
		enemy.On_Show();
		score.OnShow();
	}
}