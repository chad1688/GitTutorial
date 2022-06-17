#include "map.h"
#include "CPeople.h"
#include "Shot.h"
#include "Uzi.h"
#include "Rocket.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////
#ifndef ENEMY_H
#define ENEMY_H

	class Cenemy {
	public:
		Cenemy();
		void LoadAnimation();
		void LoadBitmap();
		void Getmapaddress(Cmap *m);									// 得到Cmap的位址
		void Getpeopleaddress(CPeople *x);		                        // 得到Cpeople的位址
		void Getshotaddress(Cshot *y);								    // 得到Cshot的位址										
		void Getuziaddress(Cuzi *z);                                    // 得到Cuzi的位址	
		void Getrocketaddress(CRocket *f);                              // 得到CRocket的位址	
		void blood_on_move();											// 敵人血量的變化
		int randx();                                                    // x座標的亂數
		int randy();                                                    // y座標的亂數
		int rand_position();	                                        // 上下左右的亂數
		void born();                                                    // 殭屍生成
		void isenemy(int x,int y,int adrress);                          // 判斷僵屍的碰撞以及給出殭屍需要走的方向
		void isenemy2(int x,int y,int adrress);                         // 判斷是否執行shot的擊退
		void isenemy3(int x, int y, int adrress, int adrress2);         // 判斷是否執行uzi的擊退
		void On_Move();
		void On_Show();
		int up[100], back[100], right[100], left[100];
		int blood[100];
		int distance_x;
		int distance_y;
		int enemy_x[100];												// 僵屍的X座標
		int enemy_y[100];                                               // 僵屍的Y座標
		int large;                                                      // 用來知道現在有幾隻殭屍
		int stop[100];
		int stop2[100];
		int stop3[100];
		int stop4[100];
		int shoted[100];                                                // 判斷是否被子彈射到
		int enemy_position;
		int is_enemy[100];
		int is_enemy2[100];
		int touch_enemy_address[100];									// 用來知道是撞到哪一隻的殭屍
		int enemy_die[100];                                             // 數目前有幾隻殭屍死亡
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
