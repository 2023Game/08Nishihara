#include "CPlayer.h"
#include "CApplication.h"
//#include "CGame.h"

#define TEXCOORD 168, 188, 158, 128	//テクスチャマッピング
#define GRAVITY (TIPSIZE / 20.0f)	//重力加速度
#define JUMPV0 (TIPSIZE / 1.4f)		//ジャンプの初速
#define ROTATION_YV CVector(0.0f, 1.0f, 0.0f) //回転速度
#define ROTATION_XV CVector(1.0f,0.0f,0.0f)//回転速度
#define VELOCITY CVector(0.0f, 0.0f, 0.1f) //移動速度

//CPlayer(位置, 回転, スケール)
CPlayer::CPlayer(const CVector& pos, const CVector& rot
	, const CVector& scale)
{
	CTransform::Update(pos, rot, scale); //行列の更新
}

//更新処理
void CPlayer::Update() 
{
	if (mInput.Key('A'))
	{
		//Y軸の回転値を増加
		mRotation=mRotation + ROTATION_YV;
	}
	//Dキー入力で回転
	if (mInput.Key('D')) 
	{
		//Y軸の回転値を減少
		mRotation = mRotation - ROTATION_YV;
	}
	
	//上キー入力で前進
	if (mInput.Key(VK_UP)) 
	{
		//Z軸方向の値を回転させ移動させる
		mPosition = mPosition + VELOCITY * mMatrixRotate;
	}
	if (mInput.Key('S'))
	{
		//X軸の回転値を減算
		mRotation = mRotation - ROTATION_XV;
	}
	if (mInput.Key('W'))
	{
		//X軸の回転値を加算
		mRotation = mRotation + ROTATION_XV;
	}

	//変換行列の更新
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
