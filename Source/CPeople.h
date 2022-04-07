#include "map.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////

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
		void Getmapaddress(Cmap *m);
		void Initialize();				// �]�w���l����l��
		void LoadBitmap();
		void LoadAnimation();
		void OnMove();					// �������l
		void OnShow();					// �N���l�ϧζK��e��
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetXY(int nx, int ny);		// �]�w���l���W���y��*/
	protected:
		CMovingBitmap start_infrontof;
		CMovingBitmap start_left;
		CMovingBitmap start_back;
		CMovingBitmap start_right;
		CAnimation animation_left;		// ���l���ʵe
		CAnimation animation_infrontof;
		CAnimation animation_right;
		CAnimation animation_back;
		Cmap *map;
		int infrontof1 = 1, left = 0, right = 0, back = 0;
		int x, y;					// ���l���W���y��
		int map_x = 6, map_y = 7;	//�H���b�a�Ϫ���m
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
	};
}