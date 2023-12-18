#pragma once
#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include <vector>
#include "CVector.h"
#include "CMatrix.h"
/*
三角形クラス
*/
class CTriangle {
public:
	//描画
	//Render(行列）
	void Render(const CMatrix& m);
	//UV設定
	void UV(const CVector& v0, const CVector& v1, const CVector& v2);
	//マテリアル番号の取得
	int MaterialIdx();
	//マテリアル番号の設定
	//Material(マテリアル番号)
	void MaterialIdx(int idx);
	//頂点座標設定
	//Vertex(頂点１、頂点２、頂点３)
	void Vertex(const CVector& v0, const CVector& v1, const CVector& v2);
	//法線設定
	//Normal(法線ベクトル)
	void Normal(const CVector &n);
	//描画
	void Render();
	//Norma(法線ベクトル１，法線ベクトル２，法線ベクトル3)
	void Normal(const CVector& v0, const CVector& v1, const CVector& v2);
private:
	CVector mUv[3]; //テクスチャマッピング
	int mMaterialIdx; //マテリアル番号
	//三角形の可変長配列
	std::vector<CTriangle>mTriangles;
	CVector mV[3];//頂点座標
	//CVector mN;//法線
	CVector mN[3];

};
#endif
