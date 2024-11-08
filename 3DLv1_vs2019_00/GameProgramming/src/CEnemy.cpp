#include "CEnemy.h"
#include "CApplication.h"
#include "CEffect.h"

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
void CEnemy::Update() 
{
	//�s����X�V
	CTransform::Update();
	//�ʒu���ړ�
	mPosition = mPosition + VELOCITY * mMatrixRotate;
}
void CEnemy::Collision()
{
	mCollider1.ChangePriority();
	mCollider2.ChangePriority();
	mCollider3.ChangePriority();
	//�Փˏ��������s
	CCollisionManager::Instance()->Collision(&mCollider1, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mCollider2, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mCollider3, COLLISIONRANGE);

}


//Collision(�R���C�_1, �R���C�_2)
void CEnemy::Collision(CCollider* m, CCollider* o)
{
	//����̃R���C�_�^�C�v�̔���
	switch (o->Type())
	{
	case CCollider::EType::ESPHERE: //���R���C�_�̎�
		//�R���C�_��m��y���Փ˂��Ă��邩����
		if (CCollider::Collision(m, o)) 
		{
			//�G�t�F�N�g����
			new CEffect(o->Parent()->Position(), 1.0f, 1.0f, "exp.tga", 4, 4, 2);
			//�Փ˂��Ă��鎞�͖����ɂ���
			//mEnabled = false;
		}
		break;
	case CCollider::EType::ETRIANGLE: //�O�p�R���C�_�̎�
		CVector adjust; //�����l
		//�O�p�R���C�_�Ƌ��R���C�_�̏Փ˔���
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{	//�Փ˂��Ȃ��ʒu�܂Ŗ߂�
			mPosition = mPosition + adjust;
		}
		break;
		////�R���C�_��m��o���Փ˂��Ă��邩����
		//if (CCollider::Collision(m, o)) 
		//{
		//	//�Փ˂��Ă��鎞�͖����ɂ���
		//		   //�G�t�F�N�g����
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
