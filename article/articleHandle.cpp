#include "stdafx.h"
#include "articleHandle.h"

CarticleHandle::CarticleHandle()
{

}

CarticleHandle::~CarticleHandle()
{

}

INT CarticleHandle::GetSeparator(CString Separator)
{
	return 1;

}

//git test2
void CarticleHandle::SeparateArticle(CString cstrArticle, CString cstrSeparator)
{
	if ((cstrArticle.Trim().GetLength() > 0)&& (PraCounts<=MAX_PRAS))
	{
		int GetSeparator = cstrArticle.Find(cstrSeparator);
		CString pra_last;
		CString pra1 = cstrArticle.Left(GetSeparator + cstrSeparator.GetLength());
		
		if (cstrSeparator.GetLength() == 2)
			pra_last = cstrArticle.Right(cstrArticle.GetLength() - GetSeparator); //为回车符时不能-1
		else
		{
			pra_last = cstrArticle.Right(cstrArticle.GetLength() - GetSeparator - 1);
		}
		if (GetSeparator != -1)
		{
			PraArray[PraCounts] = pra1;
			PraCounts++;
			this->SeparateArticle(pra_last, cstrSeparator);//递归调用
		}
		else
		{
			//为方便之后乱序操作，补上最后一段的换行符
			PraArray[PraCounts] = pra_last + L"\r\n";
			PraCounts++;
		}
	}
}


void CarticleHandle::RandPras()
{
	if ((this->CheckInput()))
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
	if (this->CheckInput())
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
}

void CarticleHandle::RandNumer(int Num)
{
	//srand((unsigned)time(NULL));
	int i, m;
	for (i = 1; i < Num; i++)
	{
		while (TempNumberArray[m = rand() % Num]);
		TempNumberArray[m] = i;
	}
}
boolean CarticleHandle::CheckInput()
{
	if ((PraCounts <= MAX_PRAS) && (PraCounts > 0))
		return true;
	else
		return false;
}