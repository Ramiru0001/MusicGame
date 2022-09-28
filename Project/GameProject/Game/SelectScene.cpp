#include "SelectScene.h"
#include "Play.h"
#include "Ranking.h"
#include "SoundNum.h"

SelectScene::SelectScene():Base(eType_SelectScene) {
	AllImageSet();
	SoundNum = 0;
	SOUND("Pokahoshi")->Play(true);
	SoundNum::SoundNumber = 0;
	Base::Add(new Ranking(0));
}
void SelectScene::Draw() {
	background.Draw();
	ranking.Draw();
	Guest.Draw();

	switch (SoundNum) {
	case eState_Pokahoshi:
		Roki.Draw();
		arrow.Draw();
		SelectPokahoshi.Draw();
		break;
	case eState_Roki:
		Pokahoshi.Draw();
		arrow.Draw();
		SelectRoki.Draw();
		break;
	}
}
void SelectScene::AllImageSet() {
	background = COPY_RESOURCE("SelectSceme_backGround", CImage);
	Pokahoshi = COPY_RESOURCE("SelectScene_parts", CImage);
	Pokahoshi.SetRect(13,19,463,103);
	Pokahoshi.SetSize(463 - 13, 103 - 19);
	Pokahoshi.SetPos(116,134);
	SelectPokahoshi = COPY_RESOURCE("SelectScene_parts", CImage);
	SelectPokahoshi.SetRect(462, 15, 990, 105);
	SelectPokahoshi.SetSize(990 -462, 105 - 15);
	SelectPokahoshi.SetPos(108, 130);
	Roki = COPY_RESOURCE("SelectScene_parts", CImage);
	Roki.SetRect(13,120,166,188);
	Roki.SetSize(166 - 13, 188 - 120);
	Roki.SetPos(116, 242);
	SelectRoki = COPY_RESOURCE("SelectScene_parts", CImage);
	SelectRoki.SetRect(467,105,642,197);
	SelectRoki.SetSize(642-467, 197-105);
	SelectRoki.SetPos(113, 230);
	arrow = COPY_RESOURCE("SelectScene_parts", CImage);
	arrow.SetRect(23, 305, 89, 371);
	arrow.SetSize(89 - 23, 371 - 305);
	arrow.SetPos(37, 144);
	ranking = COPY_RESOURCE("SelectScene_parts", CImage);
	ranking.SetRect(16,191,246,246);
	ranking.SetSize(246 - 16, 246 - 191);
	ranking.SetPos(773, 88);
	Guest = COPY_RESOURCE("SelectScene_parts", CImage);
	Guest.SetRect(16,246,142,293);
	Guest.SetSize(142 - 16, 293 - 246);
	Guest.SetPos(21,11);
}
void SelectScene::Update() {
	if (PUSH(CInput::eUp)) {
		if(SoundNum > 0){
			SoundNum--;
		}
		SoundNum::SoundNumber = SoundNum;
		KillMusic();
		SetMusic();
		SetArrow();
	}
	if (PUSH(CInput::eDown)) {
		if (SoundNum < 1) {
			SoundNum++;
		}
		SoundNum::SoundNumber = SoundNum;
		KillMusic();
		SetMusic();
		SetArrow();
	}

	if (PUSH(CInput::eButton10)) {
		KillMusic();
		Base::KillAll();
		Base::Add(new Play(SoundNum));
	}

	//SetMusic(SoundNum);
}
void SelectScene::SetMusic() {
	switch (SoundNum) {
	case eState_Pokahoshi:
		SOUND("Pokahoshi")->Play(true);
		break;
	case eState_Roki:
		SOUND("Roki")->Play(true);
		break;
	} 
}
void SelectScene::KillMusic() {
	SOUND("Pokahoshi")->Stop();
	SOUND("Roki")->Stop();
}
void SelectScene::SetArrow() {
	switch (SoundNum) {
	case eState_Pokahoshi:
		arrow.SetPos(37, 144);
		break;
	case eState_Roki:
		arrow.SetPos(37, 244);
		break;
	}
}
