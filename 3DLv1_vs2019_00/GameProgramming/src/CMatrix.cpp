#include "CMatrix.h"
//�W�����o�͊֐��̃C���N���[�h
#include <stdio.h>

void CMatrix::Print()
{
	printf("%10f %10f %10f %10f��n",
		mM[0][0], mM[0][1], mM[0][2], mM[0][3]);
	printf("%10f %10f %10f %10f��n",
		mM[1][0], mM[1][1], mM[1][2], mM[1][3]);
	printf("%10f %10f %10f %10f��n",
		mM[2][0], mM[2][1], mM[2][2], mM[2][3]);
	printf("%10f %10f %10f %10f��n",
		mM[3][0], mM[3][1], mM[3][2], mM[3][3]);
}
//�f�t�H���g�R���X�g���N�^
CMatrix::CMatrix()
{
	Identity();

}
//�P�ʍs��̍쐬
CMatrix CMatrix::Identity()
{
	//�S�Ă̗v�f��0.0f�������܂�
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mM[i][j] = 0.0f;
		}
	}
	//�K�v�ȗv�f��1.0f�������܂��B

	//���̍s��Ԃ�
	return *this;
}