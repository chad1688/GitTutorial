/*
 * mygame.h: 本檔案儲遊戲本身的class的interface
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
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/

#include "CPeople.h"
#include "map.h"
#include "Shot.h"
#include "Arms.h"
#include "Uzi.h"
#include "Rocket.h"
#include "enemy.h"
#include "Score.h"
namespace game_framework {
	///////////////////////////////s//////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	enum AUDIO_ID {				// 定義各種音效的編號
		AUDIO_DING,				// 0
		AUDIO_LAKE,				// 1
		AUDIO_NTUT,				// 2
		AUDIO_HITFLOOR,
		AUDIO_PICKUP,
		AUDIO_PISTOL,
		AUDIO_UZI,
		AUDIO_ROCKET,
		AUDIO_ZOMBIE_HIT,
		AUDIO_EXPLOSION,
		AUDIO_DIE,
		AUDIO_END
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyDown(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap logo;								// csie的logo
		CMovingBitmap start;							// start
		CMovingBitmap start2;
		CMovingBitmap introduction;                     // 介紹按鈕
		CMovingBitmap introduction2;                    // 按鈕按下
		CMovingBitmap introduction_text;                // 介紹文字
		CMovingBitmap about_text;                       // about文字
		CMovingBitmap about;                            // about按鈕
		CMovingBitmap about2;                           // 按鈕按下
		CMovingBitmap background;						// background
		CMovingBitmap arrow_back;                       // 後退鍵
		CMovingBitmap text;                           
		CMovingBitmap map1;                             // 地圖圖片
		CMovingBitmap map2;                             // 地圖圖片
		CMovingBitmap map3;                             // 地圖圖片
		CMovingBitmap arrow1;                           // 左邊箭頭
		CMovingBitmap arrow2;                           // 左邊箭頭按下
		CMovingBitmap arrow3;                           // 右邊箭頭
		CMovingBitmap arrow4;                           // 右邊箭頭按下
		CMovingBitmap character;                        // 人物圖片
		bool choose_state = false;                      // true進去選地圖畫面
		bool touch_arrow1 = false;                      // 是否觸碰鍵頭
		bool touch_arrow3 = false;                      // 是否觸碰鍵頭
		bool touch_start = false;                       // 是否觸碰start
		bool touch_introduction = false;                // 是否觸碰introduction
		bool touch_about = false;                       // 是否觸碰about
		bool touch_back = true;                         // 是否觸碰back
		int  touch[3] = { 0,0,0 };                      
		int select_purpose = 0;                         // 判斷是要進start about introduction
		int temp = 0;
		int temp2 = 0;
		
	};
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnKeyDown(UINT, UINT, UINT);               // 處理鍵盤動作
		void OnKeyUp(UINT, UINT, UINT);                 // 處理鍵盤動作
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作 
		void OnRButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnRButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap	whiltbackground;
		CMovingBitmap	background;	                    // 背景圖
		CPeople			people;		                    // 人物
		Cmap			map;                            // 地圖
		Cshot			shot;                         
		CArms			arms;
		Cuzi            uzi;
		CRocket			rocket;
		Cenemy	        enemy;		                    //敵人
		CScore			score;
		int show_text_x;
		int show_text_y;
		int show_text_x2;
		int show_text_y2;
		int show_text_x3;
		int show_text_y3;
		int total_blood;
		int object_y[3] = { 400, 400, 400 };
		int object_appear[3] = { 0,0,0 };
		int total_object;
		int temp[3] = { 0,0,0 };
		int stop[3] = { 0,0,0 };
		int test = 0;
		int count = 0;
		int count2 = 0;
		int level=0;
		int kill_all = 0;
		int count_music_shot = 0;
		int count_music_uzi = 0;
		int count_music_rocket = 0;
		int temp_i = 101;
		bool music_stop = false;
		bool music_stop2 = false;
		bool music_stop3 = false;
		int  music_stop4 = 0;
		int die_count = 0;
		
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap lose;
		CMovingBitmap retry;
		CMovingBitmap menu;
		CMovingBitmap win;
		CScore score;
	};

}