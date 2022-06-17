#include "map.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�����H��
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
#ifndef CPEOPLE_H
#define CPEOPLE_H
	class CPeople 
	{
	public:
		CPeople();
		int  GetX1();					                       // �H�����W�� x �y��
		int  GetY1();					                       // �H�����W�� y �y��
		int  GetX2();					                       // �H���k�U�� x �y��
		int  GetY2();					                       // �H���k�U�� y �y��
		bool GetisMovingup();								   // �O�_���W
		bool GetisMovingdown();								   // �O�_���U
		bool GetisMovingright();		                       // �O�_���k
		bool GetisMovingleft();								   // �O�_����
		void Setmonser_touch(bool flag);                       // �O�_�Q�L�ͥ���
		void hit_OnMove();                                     // �Q���쪺�ʧ@
		int count;
		int timer;
		void Getmapaddress(Cmap *m);                            // ��omap����}
		void Initialize();				                        // �]�w�H������l��
		void LoadBitmap();
		void LoadAnimation(); 
		void OnMove();					                        // ���ʤH��
		void people_touch_redbox();                             // �B�z�H���������l
		void blood_OnMove();	                                // �H����q�ܤ�
		void OnShow();					                        // �N�H���ϧζK��e��
		void SetMovingDown(bool flag);	                        // �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	                        // �]�w�O�_���b��������
		void SetMovingRight(bool flag);                         // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	                        // �]�w�O�_���b���W����
		void SetXY(int nx, int ny);		                        // �]�w�H�����W���y��*/
		int x, y;					                            // �H�����W���y��
		int infrontof1 = 1, left = 0, right = 0, back = 0;
		int red_box_appear3[4];
		int add_arms;
		bool Map_Moving_right;
		bool Map_Moving_left;
		bool Map_Moving_up;
		bool Map_Moving_down;
		int enemy_x[100], enemy_y[100];
		int distance_x;
		int distance_y;
		int large;
		int stop;
		bool pickup;
		bool monster_touch;
		int choose_map;
		bool die;
		int blood_index;
		int hit;
		int count_hit;
		int stop2 ;
		int stop3;
		int stop4;
	protected:
		CMovingBitmap start_infrontof;
		CMovingBitmap start_left;
		CMovingBitmap start_back;
		CMovingBitmap start_right;
		CMovingBitmap blood[10];
		CAnimation animation_left;		// �H�����ʵe
		CAnimation animation_infrontof;
		CAnimation animation_right;
		CAnimation animation_back;
		CAnimation up_die;
		CAnimation down_die;
		CAnimation right_die;
		CAnimation left_die;
		Cmap *map;
		
		int map_x = 6, map_y = 7;	//�H���b�a�Ϫ���m
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool is_space;
	};
#endif
}