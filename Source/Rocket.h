#include "map.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
#ifndef Rocket_H
#define Rocket_H

	class CRocket {
	public:
		CRocket();
		void LoadBitmap();
		void shot_OnMove();                                    // �l�u������
		void shot_OnMove2();                                   // �l�u������2
		void Getmapaddress(Cmap *m);
		void shot_OnShow();
		void Setspace(bool flag);
		int	gunx_up, guny_up, gunx_down, guny_down, gunx_right, guny_right, gunx_left, guny_left, mapx, mapy;
		int space_mapx, space_mapy;                            // ���o���U�ť���ɪ�XY
		bool isMovingright;
		bool isMovingleft;
		bool isMovingup;
		bool isMovingdown;
		int empty_bullet;                                      // �P�_�l�u�O�_�g��
		int bullet;                                            // �ثe�g�X�X�o�l�u
		int infrontof1, left, right, back;
		int space;                                             // 0�N��a�ϤW�S�l�u
		int show;
		int temp_guny[40];                                     // ���ʮɪ�Y
		int temp_infrontof[40];                                // �o�g�ɤH���¤W
		int temp_back[40];                                     // �o�g�ɤH���¤U
		int temp_right[40];                                    // �o�g�ɤH���¥k
		int temp_left[40];                                     // �o�g�ɤH���¥�
		int temp_gunx[40];                                     // ���ʮɪ�X
		int shot_stop[40];                                     // ���쪫��
		int boomx;                                             // �z���e����X
		int boomy;                                             // �z���e����Y
		bool is_space;                                         // �O�_�M�ť���                 
		bool right_isobject;                                   // �H���k��O�_�S����
		bool left_isobject;                                    // �H������O�_�S����
		bool up_isobject;                                      // �H���W��O�_�S����
		bool down_isobject;                                    // �H���U��O�_�S����
		int stop;
	protected:
		CMovingBitmap shot_infrontof[100];
		CMovingBitmap shot_left[100];
		CMovingBitmap shot_back[100];
		CMovingBitmap shot_right[100];
		CMovingBitmap boom;
		//CAnimation  shot_infrontof;
		//CAnimation	shot_left;
		//CAnimation	shot_right;
		//CAnimation	shot_back;
		Cmap *map;
		int temp_bullet[40];
		int count;
		int count2;
	};
#endif // !MAP_H
}
