#include "CMatrix.h"
//標準入出力関数のインクルード
#include <stdio.h>

void CMatrix::Print()
{
	printf("%10f %10f %10f %10f￥n",
		mM[0][0], mM[0][1], mM[0][2], mM[0][3]);
	printf("%10f %10f %10f %10f￥n",
		mM[1][0], mM[1][1], mM[1][2], mM[1][3]);
	printf("%10f %10f %10f %10f￥n",
		mM[2][0], mM[2][1], mM[2][2], mM[2][3]);
	printf("%10f %10f %10f %10f￥n",
		mM[3][0], mM[3][1], mM[3][2], mM[3][3]);
}
//デフォルトコンストラクタ
CMatrix::CMatrix()
{
	Identity();

}
//単位行列の作成
CMatrix CMatrix::Identity()
{
	//全ての要素に0.0fを代入します
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mM[i][j] = 0.0f;
		}
	}
	//必要な要素に1.0fを代入します。

	//この行列返す
	return *this;
}