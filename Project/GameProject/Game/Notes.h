#pragma once
#include <Gllibrary.h>
#include "../Base/Base.h"

class Notes:public Base{
public:
	enum {
		eState_right,
		eState_left,
	};
	//false‚Ìê‡time‚ª0‚É‚È‚é‚Ü‚Å‘Ò‹@
	bool state=false;
	int m_time;
	CImage m_img;
	CVector2D right_pos= CVector2D(113, 0);
	CVector2D left_pos = CVector2D(1167, 0);
	CVector2D m_pos;
public:
	Notes(int area,int time);
    void Draw();
	void Update();
	void Collision();
	void CheckHitNotes();
	void Timer();
};