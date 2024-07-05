#pragma once
#include "CCharacter.h"
#ifndef CBULLET_H
#define CBULLET_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
//�O�p�`�N���X�̃C���N���[�h
#include "CTriangle.h"
#include"CCollider.h"

/*
�e�N���X
�O�p�`���΂�
*/
class CBullet : public CCharacter3 
{
public:

	CBullet();
	//���Ɖ��s���̐ݒ�
	//Set(��, ���s)
	void Set(float w, float d);
	//�X�V
	void Update();
	//�`��
	void Render();
private:
	CCollider mCollider;
	//�O�p�`
	CTriangle mT;
	//��������
	int mLife;

};


#endif // !CBULLET_H

//
//class CBullet : public CCharacter
//{
//public:
//	//�Փˏ����Q
//	void Collision();
//	//�Փˏ����S
//	//Collision(�����̃|�C���^, �Փˑ���̃|�C���^)
//	void Collision(CCharacter* m, CCharacter* o);
//	//CBullet(X���W,Y���W,��,����,�摜�E,�摜��,�摜��,�摜��,�e�N�X�`���̃|�C���^)
//	CBullet(float x, float y, float w, float h,float l, float r, float b, float t, CTexture* pt);
//	CBullet();
//	void Update();
//	//void Render();
//	bool Collision(CRectangle* rect);
//};