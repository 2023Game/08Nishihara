#pragma once
#ifndef CMATRIX_H
#define CMATRIX_H
/*
}gNXNX
SsSñÌsñf[^ðµ¢Ü·
*/

class CMatrix
{
public:
	//tsñæ¾
	CMatrix Transpose() const;
	//sñÌæ¾
	float* M() const;
	//*ZqÌI[o[[h
//CMatrix * CMatrix ÌZÊðÔ·
	const CMatrix operator*(const CMatrix& m) const;
	//sñlÌãü
//M(s, ñ, l)
	void M(int row, int col, float value);
	//Ú®sñÌì¬
	//Translate(Ú®ÊX, Ú®ÊY, Ú®ÊZ)
	CMatrix Translate(float mx, float my, float mz);
	//ñ]sñiX²jÌì¬
//RotateX(px)
	CMatrix RotateX(float degree);
	CMatrix RotateZ(float degree);
	//ñ]sñiY²jÌì¬
	//RotateY(px)
	CMatrix RotateY(float degree);
	//sñlÌæ¾
    //M(s, ñ)
    //mM[s][ñ]ðæ¾
	float M(int r, int c) const;
	//gåk¬sñÌì¬
	// Scale({¦XA{¦YA{¦Z)
	CMatrix Scale(float sx, float sy, float sz);
	//\¦mFp
	//SSÌsñf[^ðÝè
	void Print();
	//ftHgRXgN^
	CMatrix();
	//PÊsñÌì¬
	CMatrix Identity();
private:
	//SSÌsñf[^ðÝè
	float mM[4][4];
};
#endif

