#pragma once
#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include <vector>
#include "CVector.h"
/*
三角形クラス
*/
class CTriangle {
public:
	//頂点座標設定
	//Vertex(頂点１、頂点２、頂点３)
	void Vertex(const CVector& v0, const CVector& v1, const CVector& v2);
	//法線設定
	//Normal(法線ベクトル)
	void Normal(const CVector &n);
	//描画
	void Render();
private:
	//三角形の可変長配列
	std::vector<CTriangle>mTriangles;
	CVector mV[3];//頂点座標
	CVector mN;//法線
};
#endif