#pragma once
#ifndef CMODEL_H
#define CMODEL_H
//vector�̃C���N���[�h
//#ifndef CMATERIAL_H
//#define CMATERIAL_H
//#define MATERIAL_LEN 64 //���O�̒���
#include "CMaterial.h"
//#include "CModel.h"
///*
//�}�e���A���N���X
//�}�e���A���̃f�[�^������
//*/
//class CMaterial {
//public:
//	~CMaterial();
//	//�f�t�H���g�R���X�g���N�^
//	CMaterial();
//	//�}�e���A����L���ɂ���
//	void Enabled();
//	//�}�e���A���̖��O�̎擾
//	char* Name();
//	//�}�e���A���̖��O��ݒ肷��
//	//Name(�}�e���A���̖��O)
//	void Name(char* name);
//	//mDiffuse�z��̎擾
//	float* Diffuse();
//private:
//	//�}�e���A���|�C���^�̉ϒ���
//	std::vector<CMaterial*> mpMaterials;
//	//�}�e���A����
//	char mName[MATERIAL_NAME_LEN + 1];
//	//�g�U���̐FRGBA
//	float mDiffuse[4];
//};
//
//#endif

#include <vector>

#include "CTriangle.h"
#include "CVertex.h "
/*
���f���N���X
���f���f�[�^�̓��͂�\��
*/
class CModel
{
public:
	const std::vector<CTriangle>& Triangles() const;
	~CModel();
	//���f���t�@�C���̓���
	//Load(���f���t�@�C�����A�}�e���A���t�@�C�����j
	void Load(char* obj, char* mtl);
	//�`��
	void Render();
	void Render(const CMatrix& m);
private:
	//���_�̔z��
	CVertex* mpVertexes;
	void CreateVertexBuffer();
	//�}�e���A���|�C���^�̉ϒ���
	std::vector<CMaterial*> mpMaterials;
	std::vector<CTriangle> mTriangles;
};
#endif
