#include "stdafx.h"
#include "articleHandle.h"

CarticleHandle::CarticleHandle()
{
	srand(unsigned(int(time(NULL))));
}

CarticleHandle::~CarticleHandle()
{

}


void CarticleHandle::SeparateArticle(CString cstrArticle, CString cstrSeparator)
{
	if ((cstrArticle.Trim().GetLength() > 0) && (PraCounts < MAX_PRAS))
	{
		int GetSeparator = cstrArticle.Find(cstrSeparator);
		CString pra_last;
		CString pra1 = cstrArticle.Left(GetSeparator + cstrSeparator.GetLength());
		
		if (cstrSeparator.GetLength() == 2)
			pra_last = cstrArticle.Right(cstrArticle.GetLength() - GetSeparator); //Ϊ�س���ʱ����-1
		else
		{
			pra_last = cstrArticle.Right(cstrArticle.GetLength() - GetSeparator - 1);
		}
		if (GetSeparator != -1)
		{
			PraArray[PraCounts] = pra1;
			PraCounts++;
			this->SeparateArticle(pra_last, cstrSeparator);//�ݹ����
		}
		else
		{
			//Ϊ����֮������������������һ�εĻ��з�
			PraArray[PraCounts] = pra_last + L"\r\n";
			PraCounts++;
		}
	}
}


void CarticleHandle::RandPras()
{
	CString s;
	this->RandNumer(PraCounts);
	for (int i = 0; i < PraCounts; i++)
	{
		TempPraArray[i] = PraArray[TempNumberArray[i]];
		s += TempPraArray[i];
	}
	this->cstrArticle = s;
}


void CarticleHandle::ReSet()
{
	this->cstrArticle = "";

	for (int i = 0; i < PraCounts; i++)
	{
		PraArray[i] = "";
		TempNumberArray[i] = 0;
		TempPraArray[i] = "";
	}

	PraCounts = 0;
}

//����Num-1��Χ�ڲ��ظ��������˼�ܴ�~
void CarticleHandle::RandNumer(int Num)
{
	int i, m;

	for (i = 1; i < Num; i++)
	{
		while (TempNumberArray[m = rand() % Num]);
		TempNumberArray[m] = i;
	}
}

//�����ؼ��ʵ�ͬʱ�����滻
int CarticleHandle::GetStringIndex(CString cstrTest, CString cstrKey)
{
	return this->cstrArticle.Replace(cstrKey, _T("����"));
}