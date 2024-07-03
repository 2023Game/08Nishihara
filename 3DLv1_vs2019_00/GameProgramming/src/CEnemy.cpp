#include "CEnemy.h"
#include "CApplication.h"

//移動速度
#define VELOCITY CVector(0.0f, 0.0f, 0.09f)

//コンストラクタ
//CEnemy(モデル, 位置, 回転, 拡縮)
CEnemy::CEnemy(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	: mCollider1(this, &mMatrix, CVector(0.0f, 5.0f, 0.0f), 0.8f)
	, mCollider2(this, &mMatrix, CVector(0.0f, 5.0f, 20.0f), 0.8f)
	, mCollider3(this, &mMatrix, CVector(0.0f, 5.0f, -20.0f), 0.8f)

{


	//モデル、位置、回転、拡縮を設定する
	mpModel = model;	//モデルの設定
	mPosition = position;	//位置の設定
	mRotation = rotation;	//回転の設定
	mScale = scale;	//拡縮の設定
}

//更新処理
void CEnemy::Update() {
	//行列を更新
	CTransform::Update();
	//位置を移動
	mPosition = mPosition + VELOCITY * mMatrixRotate;
}


//CEnemy::CEnemy(float x, float y, float w, float h, float l, float r, float b, float t, CTexture* pt)
//{
	//Set(x, y, w, h);
	//Texture(pt, l, r, b, t);
	//mTag = ETag::EENEMY;
//}

//void CEnemy::Update()
//{
	//if(mState == EState::EMOVE)
	//{
		//float x = X() + 8;
		//if (x > 800.0f)
		//{
			//x = 0.0f;
		//}
		//X(x);
	//}
//}

//bool CEnemy::Collision(CRectangle* rect)
//{
	//if (CRectangle::Collision(rect))
	//{
		//Texture(Texture(), 1946, 2172, 920, 664);
		//mState = EState::ESTOP;
		//return true;
	//}
	//return false;
//}

//void CEnemy::Collision()
//{
	//CApplication::CharacterManager()->Collision(this);
//}

//void CEnemy::Collision(CCharacter* m, CCharacter* o)
//{
	//switch (o->Tag())
	//{
	//case ETag::EENEMY:
		//break;
	//default:
	//	if (CRectangle::Collision(o))
	//	{
	//		mState = EState::ESTOP;
	//		mEnabled = false;
	//	}
//	}
//}
