#pragma once
#ifndef CMODEL_H
#define CMODEL_H
//vector�̃C���N���[�h
#include <vector>
#include "CTriangle.h"
/*
���f���N���X
���f���f�[�^�̓��͂�\��
*/
class CModel 
{
public:
	//���f���t�@�C���̓���
	//Load(���f���t�@�C�����A�}�e���A���t�@�C�����j
	void Load(char* obj, char* mtl);
	//�`��
	void Render();
private:
	std::vector<CTriangle> mTriangles;
};
#endif
