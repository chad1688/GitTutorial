#include "Shot.h"
#include "Uzi.h"
#include "Rocket.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
#ifndef ARMS_H
#define ARMS_H

	class CArms{
	public:
		CArms();
		void GetShotAddress(Cshot *shot);					// ��oCshot����}
		void GetUziAddress(Cuzi *uzi);						// ��oCuzi����}
		void GetRocketAddress(CRocket *rocket);				// ��oCRocket����}
		int randint();										// ���ü� 1�Ouzi 2�Orocket
		void OnMove();
		void OnShow();
		int add_arms = 0;									// �P�_�O�_�����Ⲱ�l 0�O�S�� 1�O��
		bool change_arms;									// �P�_�O�_���j
		int show_text;										// 0����ܤ�r 1��ܤ�r
		int count2;											// �p���r��ܮɶ�
		int now_arms;										// �ثe���Z��
		bool die;											// �H���O�_���`
		int r;
		int my_arms[3];										// �P�_�{�b�֦��ƻ�Z��
	protected:
		Cuzi *uzi;
		Cshot *shot;
		CRocket *rocket;
		int touch_up;
		int touch_down;
		int count;
		int newarms_address;
		
	};
#endif // !MAP_H
}
