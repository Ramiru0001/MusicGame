#include "Movie.h"
#include <Gllibrary.h>


Movie::Movie(int State):Base(eType_Movie) {
	//SOUND("Pokapokanohoshi")->Play(true);
	state = State;
	switch (state) {
	case eState_Pokahoshi:
		count = 41;
		//MovieFPS = 60/24;
		break;
	case eState_Roki:
		count = 32;
		//MovieFPS = 60/19.97;
		break;
	}
	FPSCount = MovieFPS;
}
void Movie::Update() {
	count--;
	/*FPSCount--;
	if (FPSCount <= 0) {
		FPSCount += MovieFPS;
	}*/
	if (count == 0) {
		switch (state) {
		case eState_Pokahoshi:
			Pokahoshi();
			break;
		case eState_Roki:
			Roki();
			break;
		}
		video->Play();
	}
}
void Movie::Draw() {
	if (count <= 0 /*&& FPSCount <= 0*/) {
		video->Draw();
	}
}
void Movie::Pokahoshi() {
	video= new CVideo("Movie/‚Û‚©‚Û‚©‚Ì¯.mp4");
	//video->Play();
}
void Movie::Roki() {
	video = new CVideo("Movie/roki.mp4");
	//video->Play();
}
Movie::~Movie() {
	video->Stop();
}