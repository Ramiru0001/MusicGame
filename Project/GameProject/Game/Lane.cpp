#include "Lane.h"

Lane::Lane() :Base(eType_Lane) {
	m_img = COPY_RESOURCE("Lane", CImage);
	m_img.SetSize(1280,720);
}
void Lane::Draw() {
	m_img.Draw();
}