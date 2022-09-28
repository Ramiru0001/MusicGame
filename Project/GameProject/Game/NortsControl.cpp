#include "NortsControl.h"
#include "Notes.h"

void NortsControl::Notes1(int time) {

	m_time = time;
	if (m_time <= 0) {
		Base::Add(new Notes(CVector2D(113, 0)));
	}
	printf("%d", m_time);
}