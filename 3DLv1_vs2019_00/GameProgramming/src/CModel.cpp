#include "CModel.h"
//�W�����o�͂̃C���N���[�h
#include <stdio.h>
//���f���t�@�C���̓���
//Load(���f���t�@�C�����A�}�e���A���t�@�C����)
void CModel::Load(char* obj, char* mtl)
{
	//�t�@�C���|�C���^�ϐ��̍쐬
	FILE* fp;
	//�t�@�C������f�[�^�����
	//���̓G���A���쐬����
	char buf[256];

	//�t�@�C���̃I�[�v��
	//fopen(�t�@�C�����A���[�h)
	//�I�[�v���ł��Ȃ�����NULL��Ԃ�
	fp = fopen(mtl, "r");
	//�t�@�C���I�[�v���G���[�̔���
	//fg��NULL�̎��̓G���[
	if (fp == NULL)
	{
		//�R���\�[���ɃG���[���o�͂��Ė߂�
		printf("%s file open error\n", mtl);
		return;
	}
	//�t�@�C������P�s����
	//fgets(���̓G���A�A�G���A�T�C�Y�A�t�@�C���|�C���^)
	//�t�@�C���̍Ō�ɂȂ��NULL��Ԃ�
	while (fgets(buf, sizeof(buf), fp) != NULL)
	{
		//���͂����l���R���\�[���ɏo�͂���
		printf("%s", buf);
	}
	//�t�@�C���̃N���[�Y
	fclose(fp);

	fp = fopen(obj, "r");
	if (fp == NULL)
	{
		printf("% file open error\n", obj);
		return;
	}
	while (fgets(buf, sizeof(buf), fp) != NULL)
	{
		printf("%s", buf);
	}
	fclose(fp);



}