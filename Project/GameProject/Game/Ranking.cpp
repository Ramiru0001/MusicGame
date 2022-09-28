#include "Ranking.h"
#include "SoundNum.h"
#include <Gllibrary.h>
#include <iostream>
#include <fstream>

Ranking::Ranking(int state) :Base(eType_Ranking) {
	switch (state) {
	case eState_Pokahoshi:
		Pokahoshi();
		break;
	case eState_Roki:
		Roki();
		break;
	}
	ImageSet();
}
void Ranking::Draw() {
	//m_scoreを[0]から順番に10個出力
	for (int i = 0; i <= max && i<10; i++) {
		int Temp = m_score[i];
		int m = 0;
		while (Temp >= 1) {
			int k = Temp % 10;
			Temp = Temp / 10;
			//printf("%d::k\n", k);
			m_img[k].SetPos(928/*1048*/ - 15 * (m + 1), 157 + 30 + 45 * i);
			m_img[k].Draw();
			m++;
		}
	}
}
void Ranking::ImageSet(){
	for (int i = 0; i < 10; i++) {
		m_img[i] = COPY_RESOURCE("Number", CImage);
		m_img[i].SetRect(i * 39, 0, (i + 1) * 39, 77);
		m_img[i].SetSize(15,30);
	}
}
void Ranking::Pokahoshi() {
	std::fstream file("Score/Pokahoshi.txt", std::ios::in);

	//データの読み取り
	int i = 0;
	for (i = 0; i < 10000; i++) {
		file >> data[i];
		m_score[i] = atoi(data[i].c_str());
		//std::cout << data << std::endl;
		//m_score[i] = data;

		file.seekp(+2, std::ios::cur);
		if (file.eof()) {
			i--;
			break;
		}
	}
	max = i;
	//大きい順に並べ替え
	for (int k = max; k >= 1; k--) {
		for (int m = k - 1; m >= 0; m--) {
			if (m_score[k] > m_score[m]) {
				int w = m_score[k];
				m_score[k] = m_score[m];
				m_score[m] = w;
			}
		}
	}
}
void Ranking::Roki() {
	std::fstream file("Score/Roki.txt", std::ios::in);

	//データの読み取り
	int i = 0;
	for (i = 0; i < 10000; i++) {
		file >> data[i];
		m_score[i] = atoi(data[i].c_str());
		//std::cout << data << std::endl;
		//m_score[i] = data;

		file.seekp(+2, std::ios::cur);
		if (file.eof()) {
			i--;
			break;
		}
	}
	max = i;
	//大きい順に並べ替え
	for (int k = max; k >= 1; k--) {
		for (int m = k - 1; m >= 0; m--) {
			if (m_score[k] > m_score[m]) {
				int w = m_score[k];
				m_score[k] = m_score[m];
				m_score[m] = w;
			}
		}
	}
}
void Ranking::Update() {
	SoundNum = SoundNum::SoundNumber;
	switch (SoundNum) {
	case eState_Pokahoshi:
		Pokahoshi();
		break;
	case eState_Roki:
		Roki();
		break;
	}
}