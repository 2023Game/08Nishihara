#include "CApplication.h"
#include "CRectangle.h"
#include "CVector.h"
#include "CTexture.h"
#include "CTriangle.h"
#include "CMatrix.h"
#include "CTransform.h"
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

	mPlayer.Model(&mModel);
	mPlayer.Scale(CVector(0.1f, 0.1f, 0.1f));
	mPlayer.Position(CVector(0.0f, 0.0f, -3.0f));
	mPlayer.Rotation(CVector(0.0f, 180.0f, 0.0f));

	mCharacter.Model(&mModel);
	mCharacter.Scale(CVector(0.1f, 0.1f, 0.1f));
	CMatrix matrix;
	matrix.Print();
	mBackGround.Load(MODEL_BACKGROUND);
 mEye = CVector(1.0f, 2.0f, 3.0f);
 mModel.Load(MODEL_OBJ); //モデルファイルの入力
}

void CApplication::Update()
{
	mTaskManager.Update();
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
	//gluLookAt(mEye.X(),mEye.Y(),mEye.Z(), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	//mCharacter.Update();
	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める
	e = mPlayer.Position() + CVector(0.0f, 1.0f, -3.0f) * mPlayer.MatrixRotate();
		//注視点を求める
	c = mPlayer. Position();
	//上方向を求める
	u = CVector(0.0f, 1.0f, 0.0f) *mPlayer.MatrixRotate();
		//カメラの設定
		gluLookAt(e.X(), e.Y(), e.Z(), c.X(), c.Y(), c.Z(), u.X(), u.Y(), u.Z());

	//mCharacter.Render();
	mPlayer.Update();
	mPlayer.Render();
	//mModel.Render(CMatrix().RotateZ(90.0f));
	//mModel.Render(CMatrix().RotateX(90.0f));
	mBackGround.Render();
	//mModel.Render(CMatrix().Translate(-2.0f, 0.0f, -15.0f));
		CMatrix matrix, position, rotation, scale;
	position.Translate(0.5f, 1.8f, 0.5f); //移動行列設定
	rotation.RotateY(180.0f); //回転行列設定
	scale.Scale(0.1f, 0.1f, 0.1f); //拡大縮小行列設定
	matrix = scale * rotation * position; //合成行列設定
	//mModel.Render(matrix); //モデルの描画

	CTransform trans; //変換行列インスタンスの作成
	trans.Position(CVector(0.5f, 1.8f, 0.5f)); //位置の設定
	trans.Rotation(CVector(-10.0f, -20.0f, -30.0f)); //回転の設定
	trans.Scale(CVector(0.1f, 0.1f, 0.1f)); //拡大縮小の設定
	trans.Update(); //行列の更新
	//mModel.Render(trans.Matrix());
	//mPlayer.bullet.Update();
	//mPlayer.bullet.Render();
		//タスクマネージャの更新
	mTaskManager.Update();
	//タスクマネージャの描画
	mTaskManager.Render();




}

CTaskManager CApplication::mTaskManager;
CTaskManager* CApplication::TaskManager()
{
	return &mTaskManager;
}
