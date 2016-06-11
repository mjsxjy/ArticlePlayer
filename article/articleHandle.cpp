#include "stdafx.h"
#include "articleHandle.h"


/*
CArticleHandle类外部接口：
  1、读入文章：ReadArticle(CString Article)
  2、对按指定的分隔符对文章进行乱序操作并返回乱序后的文章：RandOrder(CString Sparator)
  3、替换指定的关键词：ReplaceWord(CString OldWord, CString NewWord)
  4、
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
	if (Article.Trim().GetLength() > 0)
		this->cstrArticle = Article;
}

void CArticleHandle::SeparateArticle(CString cstrArticle, CString cstrSeparator)
{
	if ((cstrArticle.Trim().GetLength() > 0) && (PraCounts < MAX_PRAS))
	{
		int GetSeparator = cstrArticle.Find(cstrSeparator);
		CString pra_last;
		CString pra1 = cstrArticle.Left(GetSeparator + cstrSeparator.GetLength());
		
		if (cstrSeparator.GetLength() == 2) //回车符
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

int CArticleHandle::ScanDuplicateWords(byte MinWordLength)
{
	/*********************CString与Byte数组的相互转化:****************************
	CString cs1 = "gettruckpos";
	byte buf[200];
	memcpy(buf, cs1.GetBuffer(cs1.GetLength()), cs1.GetLength());  //将cstring放入byte数组
	CString *pPhoneNum = new CString((char*)buf, cs1.GetLength()); //将byte数组转换成cstring
	CString cs2 = *pPhoneNum;
	********************************************************************************/
	wchar_t buff[MAX_WORDS];
	wmemcpy(buff, this->cstrArticle.GetBuffer(MAX_WORDS), MAX_WORDS);
	int l = wcslen(buff);
	switch (MinWordLength)
	{
	case 2:
	{
			  for (int i = 0; i < l; i++) //扫描由文章组成的字符数组
			  {
				  //比较0-1和2-3,3-4,4-5.....
				  //比较1-2和3-4,4-5,5-6,6-7....
				  //....
				  for (int j = 0; j < l; j++)
				  {
					  if (iswpunct(buff[i])) continue;
					  if ((buff[i] != ' ') && (buff[i] == buff[i + j + 2]) && (buff[i + 1] == buff[i + j + 3]))
					  {
						CString s1(buff[i]);
						CString s2(buff[i + 1]);
						DuplicateWordList.push_front(s1+s2);
					  }
				  }
			  }
			  //break;
	}
	case 3:
	{
			  for (int i = 0; i < l; i++)
			  {
				  for (int j = 0; j < l; j++)
				  {
					  if (iswpunct(buff[i])) continue;
					  if ((buff[i] != ' ') && (buff[i] == buff[i + j + 2]) && (buff[i + 1] == buff[i + j + 3]) &&
						  (buff[i + 2] == buff[i + j + 4]))
					  {
						  CString s1(buff[i]);
						  CString s2(buff[i + 1]);
						  CString s3(buff[i + 2]);
						  DuplicateWordList.push_front(s1+ s2 +s3);
					  }
				  }
			  }
			  //break;
	}
	case 4:
	{
			  for (int i = 0; i < l; i++)
			  {
				  for (int j = 0; j < l; j++)
				  {
					  if (iswpunct(buff[i])) continue;
					  if ((buff[i] != ' ') && (buff[i] == buff[i + j + 2]) && (buff[i + 1] == buff[i + j + 3]) &&
						  (buff[i + 2] == buff[i + j + 4]) && (buff[i + 3] == buff[i + j + 5]))
					  {
						  CString s1(buff[i]);
						  CString s2(buff[i + 1]);
						  CString s3(buff[i + 2]);
						  CString s4(buff[i + 3]);
						  DuplicateWordList.push_front(s1 + s2 + s3 + s4);
					  }
				  }
			  }
			  //break;
	}
	case 5:
	{
			  for (int i = 0; i < l; i++)
			  {
				  for (int j = 0; j < l; j++)
				  {
					  if (iswpunct(buff[i])) continue;
					  if ((buff[i] != ' ') && (buff[i] == buff[i + j + 2]) && (buff[i + 1] == buff[i + j + 3]) &&
						  (buff[i + 2] == buff[i + j + 4]) && (buff[i + 3] == buff[i + j + 5]) && 
						  (buff[i + 3] == buff[i + j + 5]) && (buff[i + 4] == buff[i + j + 6]))
					  {

						  CString s1(buff[i]);
						  CString s2(buff[i + 1]);
						  CString s3(buff[i + 2]);
						  CString s4(buff[i + 3]);
						  CString s5(buff[i + 4]);
						  DuplicateWordList.push_front(s1 + s2 + s3 + s4 + s5);
					  }
				  }
			  }
			  //break;
	}
	case 6:
	{
			  for (int i = 0; i < l; i++)
			  {
				  for (int j = 0; j < l; j++)
				  {
					  if (iswpunct(buff[i])) continue;
					  if ((buff[i] != ' ') && (buff[i] == buff[i + j + 2]) && (buff[i + 1] == buff[i + j + 3]) &&
						  (buff[i + 2] == buff[i + j + 4]) && (buff[i + 3] == buff[i + j + 5]) &&
						  (buff[i + 3] == buff[i + j + 5]) && (buff[i + 4] == buff[i + j + 6]) &&
						  (buff[i + 4] == buff[i + j + 6]) && (buff[i + 5] == buff[i + j + 7]))
					  {

						  CString s1(buff[i]);
						  CString s2(buff[i + 1]);
						  CString s3(buff[i + 2]);
						  CString s4(buff[i + 3]);
						  CString s5(buff[i + 4]);
						  CString s6(buff[i + 5]);
						  DuplicateWordList.push_front(s1 + s2 + s3 + s4 + s5 + s6);
					  }
				  }
			  }
			  //break;
	}
	case 7:
	{
			  for (int i = 0; i < l; i++)
			  {
				  for (int j = 0; j < l; j++)
				  {
					  if (iswpunct(buff[i])) continue;
					  if ((buff[i] != ' ') && (buff[i] == buff[i + j + 2]) && (buff[i + 1] == buff[i + j + 3]) &&
						  (buff[i + 2] == buff[i + j + 4]) && (buff[i + 3] == buff[i + j + 5]) &&
						  (buff[i + 3] == buff[i + j + 5]) && (buff[i + 4] == buff[i + j + 6]) &&
						  (buff[i + 4] == buff[i + j + 6]) && (buff[i + 5] == buff[i + j + 7]) &&
						  (buff[i + 5] == buff[i + j + 7]) && (buff[i + 6] == buff[i + j + 8]))
					  {

						  CString s1(buff[i]);
						  CString s2(buff[i + 1]);
						  CString s3(buff[i + 2]);
						  CString s4(buff[i + 3]);
						  CString s5(buff[i + 4]);
						  CString s6(buff[i + 5]);
						  CString s7(buff[i + 6]);
						  DuplicateWordList.push_front(s1 + s2 + s3 + s4 + s5 + s6 + s7);
					  }
				  }
			  }
			  //break;
	}
	case 8:
	{
			  for (int i = 0; i < l; i++)
			  {
				  for (int j = 0; j < l; j++)
				  {
					  if (iswpunct(buff[i])) continue;
					  if ((buff[i] != ' ') && (buff[i] == buff[i + j + 2]) && (buff[i + 1] == buff[i + j + 3]) &&
						  (buff[i + 2] == buff[i + j + 4]) && (buff[i + 3] == buff[i + j + 5]) &&
						  (buff[i + 3] == buff[i + j + 5]) && (buff[i + 4] == buff[i + j + 6]) &&
						  (buff[i + 4] == buff[i + j + 6]) && (buff[i + 5] == buff[i + j + 7]) &&
						  (buff[i + 5] == buff[i + j + 7]) && (buff[i + 6] == buff[i + j + 8]) &&
						  (buff[i + 6] == buff[i + j + 8]) && (buff[i + 7] == buff[i + j + 9]))
					  {

						  CString s1(buff[i]);
						  CString s2(buff[i + 1]);
						  CString s3(buff[i + 2]);
						  CString s4(buff[i + 3]);
						  CString s5(buff[i + 4]);
						  CString s6(buff[i + 5]);
						  CString s7(buff[i + 6]);
						  CString s8(buff[i + 7]);
						  DuplicateWordList.push_front(s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8);
					  }
				  }
			  }
			  //break;
	
	}
	default:
		break;
	} (MinWordLength);

	this->DuplicateWordList.sort();
	this->DuplicateWordList.unique();
//--------------------------------------------------------------------------------------------------------------
	//下面的代码本来是想处理特殊字符，如句号，空格。思路 是把list中每个元素转为CString数组，一个个判断
	//wchar_t *s = new wchar_t[DuplicateWordList.size()];

	//std::list<CString>::const_iterator it;
	//for (it = DuplicateWordList.begin(); it != DuplicateWordList.end(); it++)
	//{
	//	wmemcpy(s, *it, DuplicateWordList.size());
	//	CString ss = s;
	//	if (ss.Trim() == "")
	//	{
	//		
	//	}
	//}
	//delete[]s;
//---------------------------------------------------------------------------------------------------------------
	return this->DuplicateWordList.size();
}

void CArticleHandle::ReMoveX(CString s)
{
	//if (int(s)<41)
}