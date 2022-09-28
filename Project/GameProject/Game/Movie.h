#pragma once
#include<Gllibrary.h>
#include "../Base/Base.h"

class Movie :public Base {
public:
	enum {
		eState_Pokahoshi,
		eState_Roki,
	};
	float MovieFPS;
	float FPSCount;
	int count;
	int state;
	CVideo* video;
public:
	Movie::Movie(int state);
	Movie::~Movie();
	void Update();
	void Draw();
	void Load();
	void Roki();
	void Pokahoshi();
};