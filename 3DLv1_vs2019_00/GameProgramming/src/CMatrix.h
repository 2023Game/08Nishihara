#pragma once
#ifndef CMATRIX_H
#define CMATRIX_H
/*
�}�g���N�X�N���X
�S�s�S��̍s��f�[�^�������܂�
*/

class CMatrix
{
public:
	//��]�s��iX���j�̍쐬
//RotateX(�p�x)
	CMatrix RotateX(float degree);
	CMatrix RotateZ(float degree);
	//��]�s��iY���j�̍쐬
	//RotateY(�p�x)
	CMatrix RotateY(float degree);
	//�s��l�̎擾
    //M(�s, ��)
    //mM[�s][��]���擾
	float M(int r, int c) const;
	//�g��k���s��̍쐬
	// Scale(�{��X�A�{��Y�A�{��Z)
	CMatrix Scale(float sx, float sy, float sz);
	//�\���m�F�p
	//�S���S�̍s��f�[�^��ݒ�
	void Print();
	//�f�t�H���g�R���X�g���N�^
	CMatrix();
	//�P�ʍs��̍쐬
	CMatrix Identity();
private:
	//�S���S�̍s��f�[�^��ݒ�
	float mM[4][4];
};
#endif

