#include "Hit.h"
#include "Score.h"
#include "ScoreTemp.h"

Hit::Hit(const CVector2D& pos):Base(eType_Hit) {
	m_img = COPY_RESOURCE("Hit", CImage);
	m_pos.x = pos.x;
	m_img.SetSize(156,156);
	m_img.SetCenter(78,78);
	m_count = 15;
	ScoreTemp::ScoreNow += ScoreTemp::ScoreUp;
	//printf("%d", ScoreTemp::ScoreNow);
}
void Hit::Draw() {
	m_img.SetPos(m_pos.x, 656);
	m_img.Draw();
}
void Hit::Update() {
	m_count--;
	if (m_count <= 0) {
		m_kill = true;
	}
}