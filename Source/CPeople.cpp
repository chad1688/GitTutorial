#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CPeople.h"
#include "map.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CPeople::CPeople()
	{
		Initialize();
	}

	void CPeople::Getmapaddress(Cmap *m) {
		map = m;
		
	}

	int CPeople::GetX1()
	{
		return x;
	}

	int CPeople::GetY1()
	{
		return y;
	}

	int CPeople::GetX2()
	{
		return x + animation.Width();
	}

	int CPeople::GetY2()
	{
		return y + animation.Height();
	}

	void CPeople::Initialize()
	{
		const int X_POS = 300;
		const int Y_POS = 300;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}

	void CPeople::LoadStartinfrontof() {
		start_infrontof.LoadBitmap("RES/infrontof3.bmp", RGB(184, 184, 184));
	}

	void CPeople::LoadStartleft() {
		start_left.LoadBitmap("RES/left3.bmp", RGB(184, 184, 184));
	}

	void CPeople::LoadStartright() {
		start_right.LoadBitmap("RES/right3.bmp", RGB(184, 184, 184));
	}

	void CPeople::LoadStartback() {
		start_back.LoadBitmap("RES/back3.bmp", RGB(184, 184, 184));
	}
	void CPeople::LoadBitmapleft()
	{
		animation.AddBitmap("RES/left.bmp", RGB(184, 184, 184));
		animation.AddBitmap("RES/left2.bmp", RGB(184, 184, 184));
		animation.AddBitmap("RES/left3.bmp", RGB(184, 184, 184));
	}

	void CPeople::LoadBitmapinfrontof()
	{
		animation2.AddBitmap("RES/inforntof.bmp", RGB(184, 184, 184));
		animation2.AddBitmap("RES/infrontof2.bmp", RGB(184, 184, 184));
		animation2.AddBitmap("RES/infrontof3.bmp", RGB(184, 184, 184));
	}

	void CPeople::LoadBitmapright()
	{
		animation3.AddBitmap("RES/right.bmp", RGB(184, 184, 184));
		animation3.AddBitmap("RES/right2.bmp", RGB(184, 184, 184));
		animation3.AddBitmap("RES/right3.bmp", RGB(184, 184, 184));
	}

	void CPeople::LoadBitmapback()
	{
		animation4.AddBitmap("RES/back.bmp", RGB(184, 184, 184));
		animation4.AddBitmap("RES/back2.bmp", RGB(184, 184, 184));
		animation4.AddBitmap("RES/back3.bmp", RGB(184, 184, 184));
	}


	void CPeople::OnMove()
	{
		const int STEP_SIZE = 5;
		
		if (isMovingLeft) {
			if (map->x < 0) {
				if (x > 300) {
					x -= STEP_SIZE;
					animation.OnMove();
				}
				else {
					map->OnMove_right();
					animation.OnMove();
				}
			}
			else {
				if (x == 0) {
					x = STEP_SIZE;
					animation.OnMove();
				}
				else {
					x -= STEP_SIZE;
					animation.OnMove();
				}
			}
		}
		if (isMovingRight) {
			if (map->x > -855) {
				if (x < 300) {
					x += STEP_SIZE;
					animation3.OnMove();
				}
				else {
					map->OnMove_left();
					animation3.OnMove();
				}
			}
			else {
				if (x == 605) {
					animation3.OnMove();
				}
				else {
					x += STEP_SIZE;
					animation3.OnMove();
				}
			}
		}
		if (isMovingUp) {
			if (map->y < 0) {
				if (y > 300) {
					y -= STEP_SIZE;
					animation2.OnMove();
				}
				else {
					map->OnMove_down();
					animation2.OnMove();
				}
			}
			else {
				if (y == 0) {
					y = STEP_SIZE;
					animation2.OnMove();
				}
				else {
					y -= STEP_SIZE;
					animation2.OnMove();
				}
			}
		}
		if (isMovingDown) {
			if (map->y > -150) {
				if (y < 300) {
					y += STEP_SIZE;
					animation4.OnMove();
				}
				else {
					map->OnMove_up();
					animation4.OnMove();
				}
			}
			else {
				if (y == 445) {
					animation4.OnMove();
				}
				else {
					y += STEP_SIZE;
					animation4.OnMove();
				}
			}

		}
		
		
	}

	void CPeople::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CPeople::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CPeople::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CPeople::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void CPeople::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void CPeople::OnShow()
	{
		if (infrontof1 == 1) {
			start_infrontof.SetTopLeft(x, y);
			start_infrontof.ShowBitmap();
		}
		if (left == 1) {
			start_left.SetTopLeft(x, y);
			start_left.ShowBitmap();
		}
		if (right == 1) {
			start_right.SetTopLeft(x, y);
			start_right.ShowBitmap();
		}
		if (back == 1) {
			start_back.SetTopLeft(x, y);
			start_back.ShowBitmap();
		}
		if (isMovingLeft) {
			left = 1;
			infrontof1 = 0;
			back = 0;
			right = 0;
			animation.SetTopLeft(x, y);
			animation.OnShow();
		}
		if (isMovingUp) {
			infrontof1 = 1;
			left = 0;
			right = 0;
			back = 0;
			animation2.SetTopLeft(x, y);
			animation2.OnShow();
		}
		if (isMovingRight) {
			infrontof1 = 0;
			left = 0;
			right = 1;
			back = 0;
			animation3.SetTopLeft(x, y);
			animation3.OnShow();
		}
		if (isMovingDown) {
			infrontof1 = 0;
			left = 0;
			right = 0;
			back = 1;
			animation4.SetTopLeft(x, y);
			animation4.OnShow();
		}
	}
}