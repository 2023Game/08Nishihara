#pragma once
#include "CFont.h"
//#include "CApplication.h"
/*
* CUi
* ���[�U�[�C���^�t�F�[�X�N���X
*/
class CUi
{
public:

	void PosY(float f);	//���x�̐ݒ�
	void RotX(float f);	//�s�b�`�̐ݒ�
	//�Q�[���N���A�\��
	void Clear();
	//�Q�[���I�[�o�[�\��
	void Over();
	//�X�^�[�g�\��
	void Start();
	//Enemy(�G�̐�)
	void Enemy(int enemy);
	CUi();
	void Hp(int hp);
	//Time(����)
	void Time(int time);
	void Render();
private:

	float mRotY;
	float mPosY;	//���x�@Y���W
	float mRotX;	//�s�b�`�@X��]�l
	int mEnemy;	//�G�̐�
	int mHp;
	int mTime;	//�o�ߎ���

	CFont mFont;


};
