#pragma once
#ifndef CMODEL_H
#define CMODEL_H
//vectorのインクルード
//#ifndef CMATERIAL_H
//#define CMATERIAL_H
//#define MATERIAL_LEN 64 //名前の長さ
#include "CMaterial.h"
//#include "CModel.h"
///*
//マテリアルクラス
//マテリアルのデータを扱う
//*/
//class CMaterial {
//public:
//	~CMaterial();
//	//デフォルトコンストラクタ
//	CMaterial();
//	//マテリアルを有効にする
//	void Enabled();
//	//マテリアルの名前の取得
//	char* Name();
//	//マテリアルの名前を設定する
//	//Name(マテリアルの名前)
//	void Name(char* name);
//	//mDiffuse配列の取得
//	float* Diffuse();
//private:
//	//マテリアルポインタの可変長列
//	std::vector<CMaterial*> mpMaterials;
//	//マテリアル名
//	char mName[MATERIAL_NAME_LEN + 1];
//	//拡散光の色RGBA
//	float mDiffuse[4];
//};
//
//#endif

#include <vector>

#include "CTriangle.h"
#include "CVertex.h "
/*
モデルクラス
モデルデータの入力や表示
*/
class CModel
{
public:
	const std::vector<CTriangle>& Triangles() const;
	~CModel();
	//モデルファイルの入力
	//Load(モデルファイル名、マテリアルファイル名）
	void Load(char* obj, char* mtl);
	//描画
	void Render();
	void Render(const CMatrix& m);
private:
	//頂点の配列
	CVertex* mpVertexes;
	void CreateVertexBuffer();
	//マテリアルポインタの可変長列
	std::vector<CMaterial*> mpMaterials;
	std::vector<CTriangle> mTriangles;
};
#endif
