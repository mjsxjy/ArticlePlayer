#include "stdafx.h"
#include "articleHandle.h"

/*
CArticleHandle���ⲿ�ӿڣ�
  1���������£�ReadArticle(CString Article)
  2���԰�ָ���ķָ��������½�������������������������£�RandOrder(CString Sparator)
  3���滻ָ���Ĺؼ��ʣ�ReplaceWord(CString OldWord, CString NewWord)
*/

CArticleHandle::CArticleHandle()
{
	srand(unsigned(int(time(NULL))));
}

CArticleHandle::~CArticleHandle()
{

}

void CArticleHandle::ReadArticle(CString Article)
{
	this->cstrArticle = Article;
}

void CArticleHandle::SeparateArticle(CString cstrArticle, CString cstrSeparator)
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


void CArticleHandle::RandAndSave()
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


void CArticleHandle::ReSet()
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
void CArticleHandle::RandNumer(int Num)
{
	int i, m;

	for (i = 1; i < Num; i++)
	{
		while (TempNumberArray[m = rand() % Num]);
		TempNumberArray[m] = i;
	}
}


CString CArticleHandle::ReplaceWord(CString OldWord, CString NewWord)
{
	this->cstrArticle.Replace(OldWord, NewWord);
	return this->cstrArticle;
}

CString CArticleHandle::RandOrder(CString Sparator)
{
	this->SeparateArticle(this->cstrArticle, Sparator);
	this->RandAndSave();
	return this->cstrArticle;
}
