#include "map.h"
#include "CPeople.h"
#include "Shot.h"
#include "Uzi.h"
#include "Rocket.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
#ifndef ENEMY_H
#define ENEMY_H

	class Cenemy {
	public:
		Cenemy();
		void LoadAnimation();
		void LoadBitmap();
		void Getmapaddress(Cmap *m);									// �o��Cmap����}
		void Getpeopleaddress(CPeople *x);		                        // �o��Cpeople����}
		void Getshotaddress(Cshot *y);								    // �o��Cshot����}										
		void Getuziaddress(Cuzi *z);                                    // �o��Cuzi����}	
		void Getrocketaddress(CRocket *f);                              // �o��CRocket����}	
		void blood_on_move();											// �ĤH��q���ܤ�
		int randx();                                                    // x�y�Ъ��ü�
		int randy();                                                    // y�y�Ъ��ü�
		int rand_position();	                                        // �W�U���k���ü�
		void born();                                                    // �L�ͥͦ�
		void isenemy(int x,int y,int adrress);                          // �P�_���ͪ��I���H�ε��X�L�ͻݭn������V
		void isenemy2(int x,int y,int adrress);                         // �P�_�O�_����shot�����h
		void isenemy3(int x, int y, int adrress, int adrress2);         // �P�_�O�_����uzi�����h
		void On_Move();
		void On_Show();
		int up[100], back[100], right[100], left[100];
		int blood[100];
		int distance_x;
		int distance_y;
		int enemy_x[100];												// ���ͪ�X�y��
		int enemy_y[100];                                               // ���ͪ�Y�y��
		int large;                                                      // �ΨӪ��D�{�b���X���L��
		int stop[100];
		int stop2[100];
		int stop3[100];
		int stop4[100];
		int shoted[100];                                                // �P�_�O�_�Q�l�u�g��
		int enemy_position;
		int is_enemy[100];
		int is_enemy2[100];
		int touch_enemy_address[100];									// �ΨӪ��D�O������@�����L��
		int enemy_die[100];                                             // �ƥثe���X���L�ͦ��`
		int temp;
		int temp2;
		int choose_map;
		int count_hit;
		int score;
	protected:
		CAnimation animation_left;	
		CAnimation animation_infrontof;
		CAnimation animation_right;
		CAnimation animation_back;
		CAnimation animation_back_attack[100];
		CAnimation animation_up_attack[100];
		CAnimation animation_right_attack[100];
		CAnimation animation_left_attack[100];
		CMovingBitmap shoted_up;
		CMovingBitmap shoted_back;
		CMovingBitmap shoted_right;
		CMovingBitmap shoted_left;
		Cmap *map;
		CPeople *people;
		Cshot *shot;
		Cuzi *uzi;
		CRocket *rocket;
		int count[100];
		int count2[100];
		int count3[100];
		int count4[100];
		int attack_back[100];
		int attack_up[100];
		int attack_right[100];
		int attack_left[100];
	};
#endif // !MAP_H
}
