/*
 * mygame.h: ���ɮ��x�C��������class��interface
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

	enum AUDIO_ID {				// �w�q�U�ح��Ī��s��
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
	// �o��class���C�����C���}�Y�e������
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyDown(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap logo;								// csie��logo
		CMovingBitmap start;							// start
		CMovingBitmap start2;
		CMovingBitmap introduction;                     // ���Ы��s
		CMovingBitmap introduction2;                    // ���s���U
		CMovingBitmap introduction_text;                // ���Ф�r
		CMovingBitmap about_text;                       // about��r
		CMovingBitmap about;                            // about���s
		CMovingBitmap about2;                           // ���s���U
		CMovingBitmap background;						// background
		CMovingBitmap arrow_back;                       // ��h��
		CMovingBitmap text;                           
		CMovingBitmap map1;                             // �a�ϹϤ�
		CMovingBitmap map2;                             // �a�ϹϤ�
		CMovingBitmap map3;                             // �a�ϹϤ�
		CMovingBitmap arrow1;                           // ����b�Y
		CMovingBitmap arrow2;                           // ����b�Y���U
		CMovingBitmap arrow3;                           // �k��b�Y
		CMovingBitmap arrow4;                           // �k��b�Y���U
		CMovingBitmap character;                        // �H���Ϥ�
		bool choose_state = false;                      // true�i�h��a�ϵe��
		bool touch_arrow1 = false;                      // �O�_Ĳ�I���Y
		bool touch_arrow3 = false;                      // �O�_Ĳ�I���Y
		bool touch_start = false;                       // �O�_Ĳ�Istart
		bool touch_introduction = false;                // �O�_Ĳ�Iintroduction
		bool touch_about = false;                       // �O�_Ĳ�Iabout
		bool touch_back = true;                         // �O�_Ĳ�Iback
		int  touch[3] = { 0,0,0 };                      
		int select_purpose = 0;                         // �P�_�O�n�istart about introduction
		int temp = 0;
		int temp2 = 0;
		
	};
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);               // �B�z��L�ʧ@
		void OnKeyUp(UINT, UINT, UINT);                 // �B�z��L�ʧ@
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@ 
		void OnRButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnRButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap	whiltbackground;
		CMovingBitmap	background;	                    // �I����
		CPeople			people;		                    // �H��
		Cmap			map;                            // �a��
		Cshot			shot;                         
		CArms			arms;
		Cuzi            uzi;
		CRocket			rocket;
		Cenemy	        enemy;		                    //�ĤH
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
	// �o��class���C�����������A(Game Over)
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap lose;
		CMovingBitmap retry;
		CMovingBitmap menu;
		CMovingBitmap win;
		CScore score;
	};

}