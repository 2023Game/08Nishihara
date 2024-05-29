#include "CBullet.h"
#include "CApplication.h"

//幅と奥行きの設定
//Set(幅, 奥行)
void CBullet::Set(float w, float d) 
{
	//スケール設定
	mScale = CVector(1.0f, 1.0f, 1.0f);
	//三角形の頂点設定→ヒント 3
	mT.Vertex(CVector(w, 0.0f, 0.0f), CVector(0.0f, 0.0f, -d), CVector(-w, 0.0f, 0.0f));

	//三角形の法線設定
	mT.Normal(CVector(0.0f, 1.0f, 0.0f));
}

//更新
void CBullet::Update() 
{
	CTransform::Update();
	//位置更新　進行方向へ１進む→ヒント 17
	mPosition = mPosition + CVector(0.0f, 0.0f, 1.0f) * mMatrixRotate;

}

//描画
void CBullet::Render() 
{
	//DIFFUSE黄色設定
	float c[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	//三角形描画→ヒント 12
	mT.Render(mMatrix);
}


//CBullet::CBullet(float x, float y, float w, float h, float l, float r, float b, float t, CTexture* pt)
//{
//	Set(x, y, w, h);
//	Texture(pt, l, r, b, t);
//	mState = EState::EMOVE;
//	mTag = ETag::EBULLET;
//}
//
//CBullet::CBullet()
//{
//	mState = EState::ESTOP;
//	mTag = ETag::EBULLET;
//}
//
//void CBullet::Update()
//{
//	if (mState == EState::EMOVE)
//	{
//		float y = Y() + H();
//		if (y > 620.0f)
//		{
//			y = 0.0f;
//		}
//		/*if (y > 600)
//		{
//			y = 700.0f;
//		}*/
//		Y(y);
//	}
//}

//void CBullet::Render()
//{
//	glColor3f(1.0f, 1.0f, 0.0f);
//	CRectangle::Render();
//	glColor3f(1.0f, 1.0f, 1.0f);
//}

//bool CBullet::Collision(CRectangle* rect)
//{
//	if (CRectangle::Collision(rect))
//	{
//		mState = EState::ESTOP;
//		return true;
//	}
//	return false;
//}

//void CBullet::Collision()
//{
//	CApplication::CharacterManager()->Collision(this);
//}
//
//void CBullet::Collision(CCharacter* m, CCharacter* o)
//{
//	switch (o->Tag())
//	{
//	case ETag::EBULLET:
//		break;
//	default:
//		if (CRectangle::Collision(o))
//		{
//			mState = EState::ESTOP;
//			mEnabled = false;
//		}
//	}
//}

