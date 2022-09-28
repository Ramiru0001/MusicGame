#include <iostream>
#include <fstream>
#include "Play.h"
#include "Lane.h"
#include "Notes.h"
#include "Movie.h"
#include "Score.h"
#include "ScoreTemp.h"
#include "SelectScene.h"
#include "../Base/Base.h"

Play::Play(int state):Base(eType_Play) {
	m_state = state;
	ScoreTemp::ScoreNow = 0;
	switch (m_state) {
	case eState_Pokapokanohoshi:
		Pokapokanohoshi();
		break;
	case eState_Roki:
		Roki();
		break;
	}
}
void Play::Update() {
	/*if (PUSH(CInput::eButton3)) {
		SOUND("Pokapokanohoshi")->Stop();
	}*/
	//Base::Add(new Score);
	if (PlayTime <= 0) {
		m_kill = true;
	}
	PlayTime--;
};
void Play::Pokapokanohoshi() {
	Base::Add(new Movie(m_state));
	Base::Add(new Lane());
	//Base::Add(new Notes(1, 0));
	/*for (float i = 0; i < 14441; i+=47.55) {
		int n = i;
		Base::Add(new Notes(0, n));
	}*/
	OneNote = 7.925;
	NotesSetUp();
	Base;; Add(new Score());
	PlayTime = 6200;
	std::cout << OneNote;
}
void Play::Roki() {
	Base::Add(new Movie(m_state));
	Base::Add(new Lane());
	//Base::Add(new Notes(1, 0));
	/*for (float i = -10; i < 14441; i += 47.55) {
		int n = i;
		Base::Add(new Notes(0, n));
	}*/
	OneNote = 12;
	NotesSetUp();
	Base;; Add(new Score());
	PlayTime = 7685;
}
Play::~Play() {
	std::ofstream Pfile("Score/Pokahoshi.txt", std::ios_base::app | std::ios_base::in);
	std::ofstream Rfile("Score/Roki.txt", std::ios_base::app | std::ios_base::in);
	switch (m_state) {
	case eState_Pokapokanohoshi:
		/*FILE* fopen;
		fopen_s(&fopen, "Score/Pokahoshi.txt", "a");
		fprintf(fopen, "%d", ScoreTemp::ScoreNow);*/
		//std::ofstream Pfile("Score/Pokahoshi.txt", std::ios_base::app | std::ios_base::in);
		Pfile << ScoreTemp::ScoreNow << std::endl;
		//std::cout << "Done !" << std::endl;
		break;
	case eState_Roki:
		//std::ofstream Rfile("Score/Roki.txt", std::ios_base::app | std::ios_base::in);
		Rfile << ScoreTemp::ScoreNow << std::endl;
		//std::cout << "Done !" << std::endl;
		break;
	}
	Base::KillAll();
	Base::Add(new SelectScene());
}
void Play::NotesPreset(int state) {
	int m = OneNote;
	/*for (int i = 0; i < 6; i++) {
		m = i * OneNote;
	}*/
	switch (state) {
	case 0:
		Base::Add(new Notes(0, OneNote * 0 + NotesCount));
		Base::Add(new Notes(0, OneNote * 2 + NotesCount));
		Base::Add(new Notes(0, OneNote * 4 + NotesCount));
		break;
	case 1:
		Base::Add(new Notes(1, OneNote * 0 + NotesCount));
		Base::Add(new Notes(1, OneNote * 4 + NotesCount));
		Base::Add(new Notes(0, OneNote * 5 + NotesCount));
		break;
	case 2:
		Base::Add(new Notes(1, OneNote * 0 + NotesCount));
		Base::Add(new Notes(1, OneNote * 4 + NotesCount));
		Base::Add(new Notes(0, OneNote * 0 + NotesCount));
		Base::Add(new Notes(0, OneNote * 4 + NotesCount));
		break;
	case 3:
		Base::Add(new Notes(1, OneNote * 4 + NotesCount));
		Base::Add(new Notes(0, OneNote * 4 + NotesCount));
		break;
	case 4:
		Base::Add(new Notes(0, OneNote * 0 + NotesCount));
		break;
	case 5:
		Base::Add(new Notes(0, OneNote * 0 + NotesCount));
		Base::Add(new Notes(1, OneNote * 3 + NotesCount));
		Base::Add(new Notes(1, OneNote * 4 + NotesCount));
		break;
	case 6:
		Base::Add(new Notes(1, OneNote * 0 + NotesCount));
		Base::Add(new Notes(0, OneNote * 3 + NotesCount));
		Base::Add(new Notes(0, OneNote * 4 + NotesCount));
		break;
	case 7:
		Base::Add(new Notes(0, OneNote * 0 + NotesCount));
		Base::Add(new Notes(0, OneNote * 3 + NotesCount));
		Base::Add(new Notes(0, OneNote * 4 + NotesCount));
		Base::Add(new Notes(1, OneNote * 0 + NotesCount));
		Base::Add(new Notes(1, OneNote * 3 + NotesCount));
		Base::Add(new Notes(1, OneNote * 4 + NotesCount));
		break;
	case 8:
		Base::Add(new Notes(0, OneNote * 0 + NotesCount));
		Base::Add(new Notes(0, OneNote * 2 + NotesCount));
		Base::Add(new Notes(0, OneNote * 4 + NotesCount));
		Base::Add(new Notes(1, OneNote * 1 + NotesCount));
		Base::Add(new Notes(1, OneNote * 3 + NotesCount));
		break;
	case 9:
		Base::Add(new Notes(1, OneNote * 0 + NotesCount));
		Base::Add(new Notes(0, OneNote * 0 + NotesCount));
		break;
	case 10:
		break;
	case 11:
		Base::Add(new Notes(0, OneNote * 0 + NotesCount));
		Base::Add(new Notes(0, OneNote * 2 + NotesCount));
		Base::Add(new Notes(0, OneNote * 4 + NotesCount));
		Base::Add(new Notes(1, OneNote * 0 + NotesCount));
		Base::Add(new Notes(1, OneNote * 2 + NotesCount));
		Base::Add(new Notes(1, OneNote * 4 + NotesCount));
		break;
	case 12:
		Base::Add(new Notes(1, OneNote * 0 + NotesCount));
		Base::Add(new Notes(1, OneNote * 2 + NotesCount));
		Base::Add(new Notes(1, OneNote * 4 + NotesCount));
		Base::Add(new Notes(0, OneNote * 1 + NotesCount));
		break;
	case 13:
		Base::Add(new Notes(0, OneNote * 0 + NotesCount));
		Base::Add(new Notes(0, OneNote * 2 + NotesCount));
		Base::Add(new Notes(0, OneNote * 4 + NotesCount));
		Base::Add(new Notes(1, OneNote * 1 + NotesCount));
		break;
	case 14:
		Base::Add(new Notes(0, OneNote * 0 + NotesCount));
		Base::Add(new Notes(0, OneNote * 3 + NotesCount));
		Base::Add(new Notes(1, OneNote * 0 + NotesCount));
		Base::Add(new Notes(1, OneNote * 3 + NotesCount));
		break;
	case 15:
		Base::Add(new Notes(1, OneNote * 0 + NotesCount));
		Base::Add(new Notes(1, OneNote * 2 + NotesCount));
		Base::Add(new Notes(1, OneNote * 4 + NotesCount));
		Base::Add(new Notes(0, OneNote * 1 + NotesCount));
		Base::Add(new Notes(0, OneNote * 3 + NotesCount));
		break;
	}
	switch (m_state) {
	case eState_Pokapokanohoshi:
		NotesCount += 47.55;
		break;
	case eState_Roki:
		NotesCount += 96;
	}
	/*for (int i = 0; i < 6; i++) {
		std::cout << OneNote * i  << std::endl;
	}
	std::cout <<OneNote;*/
}
void Play::NotesSetUp() {
	NotesCount = 0;
	switch (m_state) {
	case eState_Pokapokanohoshi:
		NotesPreset(0);
		NotesPreset(1);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(10);
		NotesPreset(4);
		NotesPreset(10);
		NotesPreset(8);
		NotesPreset(3);
		NotesPreset(4);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(10);
		NotesPreset(5);
		NotesPreset(6);
		NotesPreset(10);
		NotesPreset(1);
		NotesPreset(1);
		NotesPreset(3);
		NotesPreset(9);
		NotesPreset(0);
		NotesPreset(1);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(10);
		NotesPreset(4);
		NotesPreset(10);
		NotesPreset(8);
		NotesPreset(3);
		NotesPreset(2);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(10);
		NotesPreset(5);
		NotesPreset(6);
		NotesPreset(10);
		NotesPreset(1);
		NotesPreset(1);
		NotesPreset(3);
		NotesPreset(9);
		NotesPreset(0);
		NotesPreset(1);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(10);
		NotesPreset(4);
		NotesPreset(10);
		NotesPreset(8);
		NotesPreset(5);
		NotesPreset(2);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(10);
		NotesPreset(5);
		NotesPreset(6);
		NotesPreset(10);
		NotesPreset(1);
		NotesPreset(1);
		NotesPreset(3);
		NotesPreset(9);
		NotesPreset(0);
		NotesPreset(1);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(10);
		NotesPreset(4);
		NotesPreset(10);
		NotesPreset(8);
		NotesPreset(1);
		NotesPreset(2);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(10);
		NotesPreset(5);
		NotesPreset(6);
		NotesPreset(10);
		NotesPreset(1);
		NotesPreset(1);
		NotesPreset(3);
		NotesPreset(9);
		NotesPreset(0);
		NotesPreset(1);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(10);
		NotesPreset(4);
		NotesPreset(10);
		NotesPreset(8);
		NotesPreset(1);
		NotesPreset(2);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(10);
		NotesPreset(5);
		NotesPreset(6);
		NotesPreset(9);
		NotesPreset(1);
		NotesPreset(1);
		NotesPreset(3);
		NotesPreset(9);
		NotesPreset(0);
		NotesPreset(1);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(10);
		NotesPreset(4);
		NotesPreset(10);
		NotesPreset(8);
		NotesPreset(1);
		NotesPreset(2);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(10);
		NotesPreset(5);
		NotesPreset(6);
		NotesPreset(10);
		NotesPreset(1);
		NotesPreset(1);
		NotesPreset(3);
		NotesPreset(9);
		break;
	case eState_Roki:
		//NotesPreset(10);
		NotesPreset(10);
		NotesPreset(0);
		NotesPreset(1);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(4);
		NotesPreset(8);
		NotesPreset(15);
		NotesPreset(2);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(5);
		NotesPreset(6);
		NotesPreset(7);
		NotesPreset(1);
		NotesPreset(1);
		NotesPreset(3);
		NotesPreset(9);
		NotesPreset(0);
		NotesPreset(1);
		NotesPreset(2);
		NotesPreset(8);
		NotesPreset(15);
		NotesPreset(2);
		NotesPreset(2);
		NotesPreset(5);
		NotesPreset(6);
		NotesPreset(7);
		NotesPreset(1);
		NotesPreset(1);
		NotesPreset(3);
		NotesPreset(9);
		NotesPreset(0);
		NotesPreset(1);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(4);
		NotesPreset(8);
		NotesPreset(15);
		NotesPreset(2);
		NotesPreset(2);
		NotesPreset(5);
		NotesPreset(6);
		NotesPreset(7);
		NotesPreset(1);
		NotesPreset(1);
		NotesPreset(3);
		NotesPreset(0);
		NotesPreset(1);
		NotesPreset(2);
		NotesPreset(4);
		NotesPreset(8);
		NotesPreset(15);
		NotesPreset(2);
		NotesPreset(2);
		NotesPreset(5);
		NotesPreset(6);
		NotesPreset(7);
		NotesPreset(1);
		NotesPreset(1);
		NotesPreset(3);
		NotesPreset(0);
		NotesPreset(1);
		NotesPreset(2);
		NotesPreset(9);
		NotesPreset(4);
		NotesPreset(8);
		NotesPreset(15);
		NotesPreset(2);
		NotesPreset(2);
		NotesPreset(5);
		NotesPreset(6);
		NotesPreset(7);
		NotesPreset(1);
		NotesPreset(1);
		NotesPreset(3);
		NotesPreset(9);
		NotesPreset(0);
		NotesPreset(1);
		NotesPreset(2);
		break;
	}
}