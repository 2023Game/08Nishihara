#include "CVector.h"

//Set(X���W�AY���W�AZ���W�j
void CVector::Set(float x, float y, float z)
{
	mX = x;
	mY = y;
	mZ = z;
}
float CVector::X() const
{
	return mX;
}

float CVector::Y() const
{
	return mY;
}

float CVector::Z() const
{
	return mZ;
}
CVector::CVector()
//������������ǉ����Ă�������
	: mX(0.0f), mY(0.0f), mZ(0.0f)
{

}
CVector::CVector(float x, float y, float z)
	: mX(x), mY(y), mZ(z)
{

}