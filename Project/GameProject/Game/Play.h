#pragma once
#include <Gllibrary.h>
#include "../Base/Base.h"

class Play:public Base {
public:
	enum  {
		eState_Pokapokanohoshi,
		eState_Roki,
	};
	float OneNote;
	int m_count=0;
	int m_state;
	int m_time;
	int PlayTime;
	float NotesCount;
	//FILE* fopen;
public:
	Play(int state);
	~Play();
	void Update();
	void Pokapokanohoshi();
	void Roki();
	//void Collision();
	void NotesPreset(int state);
	void NotesSetUp();
};