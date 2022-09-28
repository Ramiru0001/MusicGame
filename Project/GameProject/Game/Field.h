#pragma once
#include "../Base/Base.h"

class Field : public Base {
private:
	//�摜�I�u�W�F�N�g�i�O�i�j
	CImage m_foreground;
	//�摜�I�u�W�F�N�g�i���i�j
	CImage m_town;
	//�摜�I�u�W�F�N�g�i�ŉ��i�j
	CImage m_sky;
	//�n�ʂ̍���
	float m_ground_y;

public:
	/// �R���X�g���N�^
	Field();
	/// �`��
	void Draw();

	/// �n�ʂ̍������擾
	float GetGroundY() {
		return m_ground_y;
	}
};