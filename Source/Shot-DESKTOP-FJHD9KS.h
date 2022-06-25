#include "map.h"
namespace game_framework {

#ifndef SHOT_H
#define SHOT_H

	class Cshot {
	public:
		Cshot();
		void LoadBitmap();
		void shot_OnMove();                         // �l�u������1
		void shot_OnMove2();                        // �l�u������2
		void shot_OnShow();
		void Setspace(bool flag);                   // �]�w�O�_���ť���
		void Getmapaddress(Cmap *m);
		int	gunx_up, guny_up,gunx_down,guny_down,gunx_right,guny_right,gunx_left,guny_left, mapx, mapy;
		int isobject;
		int temp_gunx;                              // ���ʮɪ�X
		int temp_guny;                              // ���ʮɪ�Y
		bool isMovingright;
		bool isMovingleft;
		bool isMovingup;
		bool isMovingdown;
		int infrontof1, left, right, back;
		int space;                                  // �p�G�O0�N��a�ϤW�S�l�u
		int shot_stop;                              // �l�u���쪫��
		int temp_infrontof;
		int temp_right;
		int temp_left;
		int temp_back;
		bool is_space;                              // �O�_���ť���
	protected:
		CMovingBitmap shot_infrontof;
		CMovingBitmap shot_left;
		CMovingBitmap shot_back;
		CMovingBitmap shot_right;
		Cmap *map;
		
		int temp_bullet;
		int count;
		
		
	};
#endif
}
