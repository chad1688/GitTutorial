#include "map.h"
namespace game_framework {

#ifndef UZI_H
#define UZI_H

	class Cuzi {
	public:
		Cuzi();
		void LoadBitmap();
		void Getmapaddress(Cmap *m);
		void shot_OnMove();                           // �l�u������1
		void shot_OnMove2();                          // �l�u������2
		void shot_OnShow();
 		void Setspace(bool flag);                     // �]�w�O�_���ť���
		int	gunx_up, guny_up, gunx_down, guny_down, gunx_right, guny_right, gunx_left, guny_left, mapx, mapy;
		bool isMovingright;
		bool isMovingleft;
		bool isMovingup;
		bool isMovingdown;
		int empty_bullet;                             // �P�_�l�u�O�_�g��
		int bullet;                                   // �ثe�g�����l�u��
		int infrontof1, left, right, back;
		int space;                                    // �p�G�O0�N����W�S�l�u
		int temp_guny[100];
		int temp_infrontof[100];
		int temp_back[100];
		int temp_right[100];
		int temp_left[100];
		int temp_gunx[100];
		int shot_stop[100];
		bool is_space;
	protected:
		CMovingBitmap shot_infrontof[100];
		CMovingBitmap shot_left[100];
		CMovingBitmap shot_back[100];
		CMovingBitmap shot_right[100];
		Cmap *map;
		int count;
	};
#endif 
}
