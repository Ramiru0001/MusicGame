#include "Score.h"
#include "ScoreTemp.h"
Score::Score() :Base(eType_Score){
	score = ScoreTemp::ScoreNow;
	ImageSet();
	//m_img[1] = COPY_RESOURCE("Number", CImage);
}


void Score::Draw() {
	int i = 0;
	Temp = score;
	//m_img[1].Draw();
	//printf("%d::Temp\n", Temp);
	
	while (i<5) {
		int k;
		k = Temp % 10;
		Temp = Temp / 10;
		//printf("%d::k\n", k);
		m_img[k].SetPos(700-i*40,0);
		m_img[k].Draw();
		i++;
	}
	//m_kill = true;
}
void Score::ImageSet() {
	for (int i = 0; i < 10; i++) {
		m_img[i] = COPY_RESOURCE("Number", CImage);
		m_img[i].SetRect(i*39, 0, (i+1) * 39, 77);
		m_img[i].SetSize(40, 77);
	}
}
void Score::NumberSet() {
	
}

void Score::Update() {
	score = ScoreTemp::ScoreNow;
}