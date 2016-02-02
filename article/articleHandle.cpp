#include "stdafx.h"
#include "articleHandle.h"

CarticleHandle::CarticleHandle()
{

}

CarticleHandle::~CarticleHandle()
{

}


BOOLEAN CarticleHandle::GetParagraphs(CString cstrArticle)
{
	if (cstrArticle.Trim().GetLength() <= 0) return FALSE;
	if (PraCounts >= MAX_PRAS) return FALSE;
	CString cstrReturn("\r\n");
	int GetReturn = cstrArticle.Find('\r', 0);
	CString pra1 = cstrArticle.Left(GetReturn + cstrReturn.GetLength());
	CString pra_last = cstrArticle.Right(cstrArticle.GetLength() - GetReturn);

	if (GetReturn != -1)
	{
		PraArray[PraCounts] = pra1;
		PraCounts++;
		this->GetParagraphs(pra_last);
		return FALSE;
	}
	else
	{
		//Ϊ����֮������������������һ�εĻ��з�
		PraArray[PraCounts] = pra_last + cstrReturn;
		PraCounts++;
		return TRUE;
	}
}


void CarticleHandle::RandPras()
{
	if (PraCounts > 0)
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

void CarticleHandle::RandNumer(int Num)
{
	if (Num <= 1)
		exit;
	srand((unsigned)time(NULL));
	int i, m;
	for (i = 1; i < Num; i++)
	{
		while (TempNumberArray[m = rand() % Num]);
		TempNumberArray[m] = i;
	}
}