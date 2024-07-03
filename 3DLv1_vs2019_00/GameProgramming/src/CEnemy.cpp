#include "CEnemy.h"
#include "CApplication.h"

//�ړ����x
#define VELOCITY CVector(0.0f, 0.0f, 0.09f)

//�R���X�g���N�^
//CEnemy(���f��, �ʒu, ��], �g�k)
CEnemy::CEnemy(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	: mCollider1(this, &mMatrix, CVector(0.0f, 5.0f, 0.0f), 0.8f)
	, mCollider2(this, &mMatrix, CVector(0.0f, 5.0f, 20.0f), 0.8f)
	, mCollider3(this, &mMatrix, CVector(0.0f, 5.0f, -20.0f), 0.8f)

{


	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model;	//���f���̐ݒ�
	mPosition = position;	//�ʒu�̐ݒ�
	mRotation = rotation;	//��]�̐ݒ�
	mScale = scale;	//�g�k�̐ݒ�
}

//�X�V����
void CEnemy::Update() {
	//�s����X�V
	CTransform::Update();
	//�ʒu���ړ�
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
