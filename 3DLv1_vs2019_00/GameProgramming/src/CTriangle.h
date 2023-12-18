#pragma once
#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include <vector>
#include "CVector.h"
#include "CMatrix.h"
/*
�O�p�`�N���X
*/
class CTriangle {
public:
	//�`��
	//Render(�s��j
	void Render(const CMatrix& m);
	//UV�ݒ�
	void UV(const CVector& v0, const CVector& v1, const CVector& v2);
	//�}�e���A���ԍ��̎擾
	int MaterialIdx();
	//�}�e���A���ԍ��̐ݒ�
	//Material(�}�e���A���ԍ�)
	void MaterialIdx(int idx);
	//���_���W�ݒ�
	//Vertex(���_�P�A���_�Q�A���_�R)
	void Vertex(const CVector& v0, const CVector& v1, const CVector& v2);
	//�@���ݒ�
	//Normal(�@���x�N�g��)
	void Normal(const CVector &n);
	//�`��
	void Render();
	//Norma(�@���x�N�g���P�C�@���x�N�g���Q�C�@���x�N�g��3)
	void Normal(const CVector& v0, const CVector& v1, const CVector& v2);
private:
	CVector mUv[3]; //�e�N�X�`���}�b�s���O
	int mMaterialIdx; //�}�e���A���ԍ�
	//�O�p�`�̉ϒ��z��
	std::vector<CTriangle>mTriangles;
	CVector mV[3];//���_���W
	//CVector mN;//�@��
	CVector mN[3];

};
#endif
