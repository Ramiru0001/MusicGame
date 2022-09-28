#pragma once
#include <Gllibrary.h>
#include "../Base/Base.h"

class SelectScene :public Base {
	enum {
		eState_Pokahoshi,
		eState_Roki,
	};
public:
	CImage background;
	CImage parts;
	CImage Pokahoshi;
	CImage SelectPokahoshi;
	CImage Roki;
	CImage SelectRoki;
	CImage arrow;
	CImage ranking;
	CImage Guest;
	int SoundNum;
public:
	SelectScene();
	void AllImageSet();
	void Draw();
	void Update();
	void SetMusic();
	void KillMusic();
	void SetArrow();
};