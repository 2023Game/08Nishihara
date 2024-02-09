#include "CApplication.h"
#include "CRectangle.h"
#include "CVector.h"
#include "CTexture.h"
#include "CTriangle.h"
#include "CMatrix.h"
//OpenGL
#include"glut.h"

//�N���X��static�ϐ�
CTexture CApplication::mTexture;
CCharacterManager CApplication::mCharacterManager;

#define MODEL_BACKGROUND "res\\sky.obj","res\\sky.mtl" //�w�i���f���f�[�^�̎w��
#define SOUND_BGM "res\\mario.wav" //BGM�����t�@�C��
#define SOUND_OVER "res\\mdai.wav" //�Q�[���I�[�o�[�����t�@�C��
#define MODEL_OBJ "res\\f14.obj","res\\f14.mtl" //���f���f�[�^�̎w��"res\\obj.obj","res\\obj.mtl"

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
	CMatrix matrix;
	matrix.Print();
	mBackGround.Load(MODEL_BACKGROUND);
 mEye = CVector(1.0f, 2.0f, 3.0f);
 mModel.Load(MODEL_OBJ); //���f���t�@�C���̓���
}

void CApplication::Update()
{
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
	gluLookAt(mEye.X(),mEye.Y(),mEye.Z(), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);


	mModel.Render(CMatrix().RotateX(90.0f));
	mBackGround.Render();
}
