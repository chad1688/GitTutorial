#include "map.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
#ifndef CPEOPLE_H
#define CPEOPLE_H
	class CPeople 
	{
	public:
		CPeople();
		int  GetX1();					// ���l���W�� x �y��
		int  GetY1();					// ���l���W�� y �y��
		int  GetX2();					// ���l�k�U�� x �y��
		int  GetY2();					// ���l�k�U�� y �y��
		bool GetisMovingup();
		bool GetisMovingdown();
		bool GetisMovingright();
		bool GetisMovingleft();
		void Setmonser_touch(bool flag);
		void hit_OnMove();
		int count;
		int timer;
		void Getmapaddress(Cmap *m);
		void Initialize();				// �]�w���l����l��
		void LoadBitmap();
		void LoadAnimation();
		void OnMove();					// �������l
		void people_touch_redbox();
		void blood_OnMove();
		void OnShow();					// �N���l�ϧζK��e��
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetXY(int nx, int ny);		// �]�w���l���W���y��*/
		int x, y;					// ���l���W���y��
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
		CAnimation animation_left;		// ���l���ʵe
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