#include "CEnemy.h"
#include "CApplication.h"
#include "CEffect.h"

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
void CEnemy::Update() 
{
	//行列を更新
	CTransform::Update();
	//位置を移動
	mPosition = mPosition + VELOCITY * mMatrixRotate;
}
void CEnemy::Collision()
{
	mCollider1.ChangePriority();
	mCollider2.ChangePriority();
	mCollider3.ChangePriority();
	//衝突処理を実行
	CCollisionManager::Instance()->Collision(&mCollider1, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mCollider2, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mCollider3, COLLISIONRANGE);

}


//Collision(コライダ1, コライダ2)
void CEnemy::Collision(CCollider* m, CCollider* o)
{
	//相手のコライダタイプの判定
	switch (o->Type())
	{
	case CCollider::EType::ESPHERE: //球コライダの時
		//コライダのmとyが衝突しているか判定
		if (CCollider::Collision(m, o)) 
		{
			//エフェクト生成
			new CEffect(o->Parent()->Position(), 1.0f, 1.0f, "exp.tga", 4, 4, 2);
			//衝突している時は無効にする
			//mEnabled = false;
		}
		break;
	case CCollider::EType::ETRIANGLE: //三角コライダの時
		CVector adjust; //調整値
		//三角コライダと球コライダの衝突判定
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{	//衝突しない位置まで戻す
			mPosition = mPosition + adjust;
		}
		break;
		////コライダのmとoが衝突しているか判定
		//if (CCollider::Collision(m, o)) 
		//{
		//	//衝突している時は無効にする
		//		   //エフェクト生成
		//	new CEffect(o->Parent()->Position(), 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		//	mEnabled = false;
		//}
	}
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
