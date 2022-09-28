#include "Notes.h"
#include "Hit.h"

Notes::Notes(int area,int time):Base(eType_Notes) {
	
	if (time <= 0) {
		state = true;
	}
	switch (area) {
	case eState_right:
		m_pos = right_pos;
		break;
	case eState_left:
		m_pos = left_pos;
		break;
	}
	m_time = time;
	m_img=COPY_RESOURCE("Notes", CImage);
	m_img.SetSize(134,134);
	m_img.SetCenter(67, 67);
}

void Notes::Draw() {
	if (state == true) {
		m_img.SetPos(m_pos);
		m_img.Draw();
	}
};
void Notes::Update() {
	if (state == true) {
		CheckHitNotes();
		m_pos.y += 8;
	}
	Timer();
}
void Notes::CheckHitNotes() {
	if (PUSH(CInput::eButton1)) {
		if (620 < m_pos.y && m_pos.y < 680 && m_pos.x == 113) {
			Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
		}
	}
	if (PUSH(CInput::eButton2)) {
		if (620 < m_pos.y && m_pos.y < 680 && m_pos.x == 1167) {
			Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
		}
	}
}
void Notes::Timer() {
	m_time--;
	if (m_time <= 0) {
		state = true;
	}
}