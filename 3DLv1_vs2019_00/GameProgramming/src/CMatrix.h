#pragma once
#ifndef CMATRIX_H
#define CMATRIX_H
/*
�}�g���N�X�N���X
�S�s�S��̍s��f�[�^�������܂�
*/
class CVector;
class CMatrix
{
public:
	CVector VectorZ() const; //Z���x�N�g���̎擾
	CVector VectorX() const; //X���x�N�g���̎擾
	CVector VectorY() const; //Y���x�N�g���̎擾

	//�t�s��擾
	CMatrix Transpose() const;
	//�s��̎擾
	float* M() const;
	//*���Z�q�̃I�[�o�[���[�h
//CMatrix * CMatrix �̉��Z���ʂ�Ԃ�
	const CMatrix operator*(const CMatrix& m) const;
	//�s��l�̑��
//M(�s��, ��, �l)
	void M(int row, int col, float value);
	//�ړ��s��̍쐬
	//Translate(�ړ���X, �ړ���Y, �ړ���Z)
	CMatrix Translate(float mx, float my, float mz);
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

