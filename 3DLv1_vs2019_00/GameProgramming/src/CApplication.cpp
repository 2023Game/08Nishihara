#include "CApplication.h"
#include "CRectangle.h"
#include "CVector.h"
#include "CTexture.h"
#include "CTriangle.h"
#include "CMatrix.h"
#include "CTransform.h"
//OpenGL
#include"glut.h"
#include "CTaskManager.h"
#include "CCollisionManager.h"
#include "CBillBoard.h"
#include "CColliderTriangle.h"

//�N���X��static�ϐ�
CTexture CApplication::mTexture;
CCharacterManager CApplication::mCharacterManager;

#define MODEL_BACKGROUND "res\\sky.obj","res\\sky.mtl" //�w�i���f���f�[�^�̎w��
#define SOUND_BGM "res\\mario.wav" //BGM�����t�@�C��
#define SOUND_OVER "res\\mdai.wav" //�Q�[���I�[�o�[�����t�@�C��
#define MODEL_OBJ "res\\f14.obj","res\\f14.mtl" //���f���f�[�^�̎w��"res\\obj.obj","res\\obj.mtl"
//�G�A���@���f��
#define MODEL_C5 "res\\c5.obj", "res\\c5.mtl"


CCharacterManager* CApplication::CharacterManager()
{
	return &mCharacterManager;
}

CTexture* CApplication::Texture()
{
	return &mTexture;
}
//CApplication::CApplication()
//{
//	
//}
void CApplication::Start()
{
	//�w�i���f������O�p�R���C�_�𐶐�
//�e�C���X�^���X�Ɛe�s��͂Ȃ�
	mColliderMesh.Set(nullptr, nullptr, &mBackGround);

	//�O�p�R���C�_�̊m�F
	mColliderTriangle.Set(nullptr, nullptr
		, CVector(-50.0f, 0.0f, -50.0f)
		, CVector(-50.0f, 0.0f, 50.0f)
		, CVector(50.0f, 0.0f, -50.0f));

	mColliderTriangle2.Set(nullptr, nullptr
		, CVector(50.0f, 0.0f, 50.0f)
		, CVector(50.0f, 0.0f, -50.0f)
		, CVector(-50.0f, 0.0f, 50.0f));

	    


	mPlayer.Model(&mModel);
	mPlayer.Scale(CVector(0.1f, 0.1f, 0.1f));
	mPlayer.Position(CVector(0.0f, 0.0f, -3.0f));
	mPlayer.Rotation(CVector(0.0f, 180.0f, 0.0f));

	//mCharacter.Model(&mModel);
	//mCharacter.Scale(CVector(0.1f, 0.1f, 0.1f));
	CMatrix matrix;
	matrix.Print();
	mBackGround.Load(MODEL_BACKGROUND);
 mEye = CVector(1.0f, 2.0f, 3.0f);
 mModel.Load(MODEL_OBJ); //���f���t�@�C���̓���
	//C5���f���̓ǂݍ���
 mModelC5.Load(MODEL_C5);
 //�G�@�̃C���X�^���X�쐬
 new CEnemy(&mModelC5, CVector(0.0f, 10.0f, -100.0f),
	 CVector(), CVector(0.1f, 0.1f, 0.1f));

 new CEnemy(&mModelC5, CVector(30, 10, -130), CVector(), CVector(0.1f, 0.1f, 0.1f));
 //�r���{�[�h�̐���
 new CBillBoard(CVector(-6.0f, 3.0f, -10.0f), 1.0f, 1.0f);


}

void CApplication::Update()
{

	CTaskManager::Instance()->Update();
	//�R���W�����}�l�[�W���̏Փˏ���
	CCollisionManager::Instance()->Collision();
	//���_�P�A���_�Q�C���_�R�A�@���f�[�^�̍쐬
	CVector v0, v1, v2, n;
	//�@����������Őݒ肷��
	n. Set(0.0f, 1.0f, 0.0f);
	//���_�P�̍��W��ݒ肷��
	v0.Set(0.0f, 0.0f, 0.5f);
	//���_�Q�̍��W��ݒ肷��
	v1.Set(1.0f, 0.0f, 0.0f);
	//���_�R�̍��W��ݒ肷��
	v2.Set(0.0f, 0.0f, -0.5f);

	if (mInput.Key('J'))
	{
		mEye = mEye - CVector(0.1f, 0.0f, 0.0f);
	}
	if (mInput.Key('L'))
	{
		mEye = mEye + CVector(0.1f, 0.0f, 0.0f);
	}
	if (mInput.Key('I'))
	{
		mEye = mEye - CVector(0.0f, 0.0f, 0.1f);
	}
	if (mInput.Key('K'))
	{
		mEye = mEye + CVector(0.0f, 0.0f, 0.1f);
	}
	if (mInput.Key('O'))
	{
		mEye = mEye + CVector(0.0f, 0.1f, 0.0f);
	}
	if (mInput.Key('M'))
	{
		mEye = mEye - CVector(0.0f, 0.1f, 0.0f);
	}

	//���_�̐ݒ�
	//gluLookAt(���_X�A���_Y�A���_Z�A���SX�A���SY�A���SZ�A���X�A���Y�A���Z�j
	//gluLookAt(mEye.X(),mEye.Y(),mEye.Z(), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	//mCharacter.Update();
	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A�����_�A�����
	//���_�����߂�
	e = mPlayer.Position() + CVector(-0.2f, 1.0f, -3.0f) * mPlayer.MatrixRotate();
		//�����_�����߂�
	c = mPlayer. Position();
	//����������߂�
	u = CVector(0.0f, 1.0f, 0.0f) *mPlayer.MatrixRotate();
		//�J�����̐ݒ�
	gluLookAt(e.X(), e.Y(), e.Z(), c.X(), c.Y(), c.Z(), u.X(), u.Y(), u.Z());
	//���f���r���[�s��̎擾
	glGetFloatv(GL_MODELVIEW_MATRIX, mModelViewInverse.M());
	//�t�s��̎擾
	mModelViewInverse = mModelViewInverse.Transpose();
	mModelViewInverse.M(0, 3, 0);
	mModelViewInverse.M(1, 3, 0);
	mModelViewInverse.M(2, 3, 0);

	//mCharacter.Render();

	//mModel.Render(CMatrix().RotateZ(90.0f));
	//mModel.Render(CMatrix().RotateX(90.0f));
	mBackGround.Render();
	//mModel.Render(CMatrix().Translate(-2.0f, 0.0f, -15.0f));
		CMatrix matrix, position, rotation, scale;
	position.Translate(0.5f, 1.8f, 0.5f); //�ړ��s��ݒ�
	rotation.RotateY(180.0f); //��]�s��ݒ�
	scale.Scale(0.1f, 0.1f, 0.1f); //�g��k���s��ݒ�
	matrix = scale * rotation * position; //�����s��ݒ�
	//mModel.Render(matrix); //���f���̕`��

	CTransform trans; //�ϊ��s��C���X�^���X�̍쐬
	trans.Position(CVector(0.5f, 1.8f, 0.5f)); //�ʒu�̐ݒ�
	trans.Rotation(CVector(-10.0f, -20.0f, -30.0f)); //��]�̐ݒ�
	trans.Scale(CVector(0.1f, 0.1f, 0.1f)); //�g��k���̐ݒ�
	trans.Update(); //�s��̍X�V
	//mModel.Render(trans.Matrix());
	//mPlayer.bullet.Update();
	//mPlayer.bullet.Render();
		//�^�X�N�}�l�[�W���̍X�V
	CTaskManager::Instance()->Delete();
	//�^�X�N�}�l�[�W���̕`��
	CTaskManager::Instance()->Render();

	CCollisionManager::Instance()->Render();



}

CMatrix CApplication::mModelViewInverse;

const CMatrix& CApplication::ModelViewInverse()
{
	return mModelViewInverse;
}


//CTaskManager CApplication::mTaskManager;
//CTaskManager* CApplication::TaskManager()
//{
	//return &mTaskManager;
//}
