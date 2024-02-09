#include "CApplication.h"
#include "CRectangle.h"
#include "CVector.h"
#include "CTexture.h"
#include "CTriangle.h"
#include "CMatrix.h"
//OpenGL
#include"glut.h"

//クラスのstatic変数
CTexture CApplication::mTexture;
CCharacterManager CApplication::mCharacterManager;

#define MODEL_BACKGROUND "res\\sky.obj","res\\sky.mtl" //背景モデルデータの指定
#define SOUND_BGM "res\\mario.wav" //BGM音声ファイル
#define SOUND_OVER "res\\mdai.wav" //ゲームオーバー音声ファイル
#define MODEL_OBJ "res\\f14.obj","res\\f14.mtl" //モデルデータの指定"res\\obj.obj","res\\obj.mtl"

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
 mModel.Load(MODEL_OBJ); //モデルファイルの入力
}

void CApplication::Update()
{
	//頂点１、頂点２，頂点３、法線データの作成
	CVector v0, v1, v2, n;
	//法線を上向きで設定する
	n. Set(0.0f, 1.0f, 0.0f);
	//頂点１の座標を設定する
	v0.Set(0.0f, 0.0f, 0.5f);
	//頂点２の座標を設定する
	v1.Set(1.0f, 0.0f, 0.0f);
	//頂点３の座標を設定する
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

	//視点の設定
	//gluLookAt(視点X、視点Y、視点Z、中心X、中心Y、中心Z、上向X、上向Y、上向Z）
	gluLookAt(mEye.X(),mEye.Y(),mEye.Z(), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);


	mModel.Render(CMatrix().RotateX(90.0f));
	mBackGround.Render();
}
