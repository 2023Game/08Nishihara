#pragma once
#ifndef CMATRIX_H
#define CMATRIX_H
/*
マトリクスクラス
４行４列の行列データを扱います
*/

class CMatrix
{
public:
	//表示確認用
	//４ｘ４の行列データを設定
	void Print();
	//デフォルトコンストラクタ
	CMatrix();
	//単位行列の作成
	CMatrix Identity();
private:
	//４ｘ４の行列データを設定
	float mM[4][4];
};
#endif

