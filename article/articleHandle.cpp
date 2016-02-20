#include "stdafx.h"
#include "articleHandle.h"

/*
CArticleHandle类外部接口：
  1、读入文章：ReadArticle(CString Article)
  2、对按指定的分隔符对文章进行乱序操作并返回乱序后的文章：RandOrder(CString Sparator)
  3、替换指定的关键词：ReplaceWord(CString OldWord, CString NewWord)
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

//产生Num-1范围内不重复的随机数思密达~
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
