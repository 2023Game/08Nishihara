#include "CPlayer.h"
#include "CApplication.h"
//#include "CGame.h"

#define TEXCOORD 168, 188, 158, 128	//�e�N�X�`���}�b�s���O
#define GRAVITY (TIPSIZE / 20.0f)	//�d�͉����x
#define JUMPV0 (TIPSIZE / 1.4f)		//�W�����v�̏���
#define ROTATION_YV CVector(0.0f, 1.0f, 0.0f) //��]���x
#define ROTATION_XV CVector(1.0f,0.0f,0.0f)//��]���x
#define VELOCITY CVector(0.0f, 0.0f, 0.1f) //�ړ����x

//CPlayer(�ʒu, ��], �X�P�[��)
CPlayer::CPlayer(const CVector& pos, const CVector& rot
	, const CVector& scale)
{
	CTransform::Update(pos, rot, scale); //�s��̍X�V
}

//�X�V����
void CPlayer::Update() 
{
	if (mInput.Key('A'))
	{
		//Y���̉�]�l�𑝉�
		mRotation=mRotation + ROTATION_YV;
	}
	//D�L�[���͂ŉ�]
	if (mInput.Key('D')) 
	{
		//Y���̉�]�l������
		mRotation = mRotation - ROTATION_YV;
	}
	
	//��L�[���͂őO�i
	if (mInput.Key(VK_UP)) 
	{
		//Z�������̒l����]�����ړ�������
		mPosition = mPosition + VELOCITY * mMatrixRotate;
	}
	if (mInput.Key('S'))
	{
		//X���̉�]�l�����Z
		mRotation = mRotation - ROTATION_XV;
	}
	if (mInput.Key('W'))
	{
		//X���̉�]�l�����Z
		mRotation = mRotation + ROTATION_XV;
	}

	//�ϊ��s��̍X�V
	CTransform::Update();
}

 

//CPlayer::CPlayer(float x, float y, float w, float h, CTexture* pt)
	//: mVy(0.0f)
//{
	//Set(x, y, w, h);
	//Texture(pt, TEXCOORD);
	//mTag = ETag::EPLAYER;
//}

//void CPlayer::Update()
//{
//	if (mInput.Key(VK_SPACE))
//	{
//		CApplication::CharacterManager()->Add(
//			new CBullet(X(), Y() + H() + 10.0f
//				, 3.0f, 10.0f, 1396, 1420, 750, 592, CApplication::Texture()));
//	}
//	if (mInput.Key('A'))
//	{
//		float x = X() - 4.0f;
//		X(x);
//	}
//
//	if (mInput.Key('D'))
//	{
//		float x = X() + 4.0f;
//		X(x);
//	}
//
//	if (mInput.Key('J') 
//		&& mState != EState::EJUMP
//		&& mVy >= 0.0f)
//	{
//		mVy = JUMPV0;
//		mState = EState::EJUMP;
//	}
//
//	Y(Y() + mVy);
//	mVy -= GRAVITY;
//}
//
//void CPlayer::Collision()
//{
//	CApplication::CharacterManager()->Collision(this);
//}
//
//void CPlayer::Collision(CCharacter* m, CCharacter* o)
//{
//	float x, y;
//	switch (o->Tag())
//	{
//	case ETag::EPLAYER:
//		break;
//	default:
//		if (CRectangle::Collision(o, &x, &y))
//		{
//			X(X() + x);
//			Y(Y() + y);
//			if (x == 0.0f)
//			{
//				mVy = 0.0f;
//				mState = EState::EMOVE;
//			}
//		}
//	}
//}
