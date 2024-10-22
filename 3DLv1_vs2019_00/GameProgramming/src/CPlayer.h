#pragma once
#ifndef CPLAYER_H
#define CPLAYER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
#include "CInput.h"
#include "CBullet.h"
#include "CColliderLine.h"

/*
�v���C���[�N���X
�L�����N�^�N���X���p��
*/

class CPlayer : public CCharacter3
{
public:
	void Collision(CCollider* c, int range);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
	//CBullet bullet;
	CPlayer();
	//CPlayer(�ʒu, ��], �X�P�[��)
	CPlayer(const CVector& pos, const CVector& rot
		, const CVector& scale);
	//�X�V����
	void Update();
private:
	CInput mInput;
	CColliderLine mLine; //�����R���C�_
	CColliderLine mLine2;
	CColliderLine mLine3;

};

#endif


//private:
	//float mVy;	//Y�����x
	//CInput mInput;
//public:
	//void Collision();
	//void Collision(CCharacter* m, CCharacter* o);
	//CPlayer(float x, float y, float w, float h, CTexture* pt);
	//void Update();
//