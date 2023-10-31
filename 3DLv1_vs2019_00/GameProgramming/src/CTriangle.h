#pragma once
#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include <vector>
#include "CVector.h"
/*
�O�p�`�N���X
*/
class CTriangle {
public:
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
	//�O�p�`�̉ϒ��z��
	std::vector<CTriangle>mTriangles;
	CVector mV[3];//���_���W
	//CVector mN;//�@��
	CVector mN[3];

};
#endif