#pragma once
#ifndef CCHARACTER3_H
#define CCHARACTER3_H
//変換行列クラスのインクルード
#include "CTransform.h"
//モデルクラスのインクルード
#include "CModel.h"
#include "CTask.h"
#include "CApplication.h"
/*
キャラクタークラス
ゲームキャラクタの基本的な機能を定義する
*/
class CCharacter3 : public CTransform,public CTask 
{
public:
	//デストラクタ
	~CCharacter3();
	//モデルの設定
	//Model(モデルクラスのポインタ)
	void Model(CModel* m);
	//描画処理
	void Render();
protected:
	CModel* mpModel; //モデルのポインタ
};

#endif
CCharacter3::~CCharacter3() 
{
	//タスクリストから削除
	CApplication::TaskManager()->Remove(this);
}


