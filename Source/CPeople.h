#include "map.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的人物
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////
#ifndef CPEOPLE_H
#define CPEOPLE_H
	class CPeople 
	{
	public:
		CPeople();
		int  GetX1();					                       // 人物左上角 x 座標
		int  GetY1();					                       // 人物左上角 y 座標
		int  GetX2();					                       // 人物右下角 x 座標
		int  GetY2();					                       // 人物右下角 y 座標
		bool GetisMovingup();								   // 是否按上
		bool GetisMovingdown();								   // 是否按下
		bool GetisMovingright();		                       // 是否按右
		bool GetisMovingleft();								   // 是否按左
		void Setmonser_touch(bool flag);                       // 是否被殭屍打到
		void hit_OnMove();                                     // 被打到的動作
		int count;
		int timer;
		void Getmapaddress(Cmap *m);                            // 獲得map的位址
		void Initialize();				                        // 設定人物為初始值
		void LoadBitmap();
		void LoadAnimation(); 
		void OnMove();					                        // 移動人物
		void people_touch_redbox();                             // 處理人物踩到紅盒子
		void blood_OnMove();	                                // 人物血量變化
		void OnShow();					                        // 將人物圖形貼到畫面
		void SetMovingDown(bool flag);	                        // 設定是否正在往下移動
		void SetMovingLeft(bool flag);	                        // 設定是否正在往左移動
		void SetMovingRight(bool flag);                         // 設定是否正在往右移動
		void SetMovingUp(bool flag);	                        // 設定是否正在往上移動
		void SetXY(int nx, int ny);		                        // 設定人物左上角座標*/
		int x, y;					                            // 人物左上角座標
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
		CAnimation animation_left;		// 人物的動畫
		CAnimation animation_infrontof;
		CAnimation animation_right;
		CAnimation animation_back;
		CAnimation up_die;
		CAnimation down_die;
		CAnimation right_die;
		CAnimation left_die;
		Cmap *map;
		
		int map_x = 6, map_y = 7;	//人物在地圖的位置
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		bool is_space;
	};
#endif
}