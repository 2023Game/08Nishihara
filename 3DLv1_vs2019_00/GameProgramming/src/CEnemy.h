#pragma once
#ifndef CENEMY_H
#define CENEMY_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
#include "CCollider.h"
/*
�G�l�~�[�N���X
�L�����N�^�N���X
*/
class CEnemy :public CCharacter3
{
private:
	//�R���C�_
	CCollider mCollider1;
	CCollider mCollider2;
	CCollider mCollider3;

public:
	//�Փˏ���
//Collision(�R���C�_1, �R���C�_2)
	void Collision(CCollider* m, CCollider* o);

	//�m�F�p���\�b�h�@�폜�\��
	//void CEnemy::Render() 
	//{
	//	CCharacter3::Render();
	//	mCollider1.Render();
	//	mCollider2.Render();
	//	mCollider3.Render();
	//}

	//�R���X�g���N�^
	//CEnemy(���f��, �ʒu, ��], �g�k)
	CEnemy(CModel* model, const CVector& position,
		const CVector& rotation, const CVector& scale);
	//�X�V����
	void Update();

};
#endif // !CE 

//#include "CCharacter.h"

//class CEnemy : public CCharacter
//{
//public:
//	//CEnemy(X���W,Y���W,��,����,�摜�E,�摜��,�摜��,�摜��,�e�N�X�`���̃|�C���^)
//	CEnemy(float x, float y, float w, float h, float l, float r, float b, float t, CTexture* pt);
//	void Update();
//	bool Collision(CRectangle* rect);
//	void Collision();
//	void Collision(CCharacter* m, CCharacter* o);
//};