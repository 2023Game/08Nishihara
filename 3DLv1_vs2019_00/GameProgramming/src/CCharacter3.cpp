#include "CCharacter3.h"
#include "CApplication.h"

void CCharacter3::Model(CModel* m)
{
	mpModel = m;
}

//�`�揈��
void CCharacter3::Render()
{
	mpModel->Render(mMatrix);
}
CCharacter3::~CCharacter3() 
{
	//�^�X�N���X�g����폜
	CApplication::TaskManager()->Remove(this);
}
