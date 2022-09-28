#pragma once
#include <Gllibrary.h>
#include "../Base/Base.h"

class Lane :public Base {
public:
	CImage m_img;
public:
	Lane();
	void Draw();
};
