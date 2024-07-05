#pragma once
#include "CCharacter.h"
#ifndef CBULLET_H
#define CBULLET_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
//三角形クラスのインクルード
#include "CTriangle.h"
#include"CCollider.h"

/*
弾クラス
三角形を飛ばす
*/
class CBullet : public CCharacter3 
{
public:

	CBullet();
	//幅と奥行きの設定
	//Set(幅, 奥行)
	void Set(float w, float d);
	//更新
	void Update();
	//描画
	void Render();
private:
	CCollider mCollider;
	//三角形
	CTriangle mT;
	//生存時間
	int mLife;

};


#endif // !CBULLET_H

//
//class CBullet : public CCharacter
//{
//public:
//	//衝突処理２
//	void Collision();
//	//衝突処理４
//	//Collision(自分のポインタ, 衝突相手のポインタ)
//	void Collision(CCharacter* m, CCharacter* o);
//	//CBullet(X座標,Y座標,幅,高さ,画像右,画像左,画像下,画像上,テクスチャのポインタ)
//	CBullet(float x, float y, float w, float h,float l, float r, float b, float t, CTexture* pt);
//	CBullet();
//	void Update();
//	//void Render();
//	bool Collision(CRectangle* rect);
//};