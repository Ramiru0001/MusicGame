#pragma once
#include<Gllibrary.h>
#include "../Base/Base.h"

class Hit :public Base {
public:
	int m_count;
	CImage m_img;
	CVector2D m_pos;
public:
	Hit(const CVector2D& pos);
	//~Hit();
	void Draw();
	void Update();
};
