#pragma once

class CArticleHandle
{

private:
	CString cstrArticle;//唯一操作的字符（文章）
	void SeparateArticle(CString cstrArticle, CString cstrSeparator);//（递归）将文字按照cstrSeparator指定的符号分隔并传入临时内部数组中
	static const int MAX_PRAS = 100; //最大处理的分隔符数
	static const int MAX_WORDS = 10000; //最大处理的重复词语字符数
	void RandAndSave();//将按分隔符分开后的文章随机排序并保存
	int KeyIndex = 0;
	CString PraArray[MAX_PRAS];//这是一个用来存储每一分隔的数组
	CString TempPraArray[MAX_PRAS];//临时存储产生的随机数组
	int TempNumberArray[MAX_PRAS]; //临时存储产生的随机数字
	int PraCounts = 0;//存储分隔符数
	void RandNumer(int Num); //产生随机数字，并存放于TempNumberArray中
	typedef std::list<CString> LISTCSTRING;
	

public:
	CArticleHandle();
	~CArticleHandle();
	void ReadArticle(CString Article);

	CString OutputArticle();//输出CArticleHandle此时的文章（唯一）

	CString RandOrder(CString Sparator);//读入原始文章

	void ReSet();
	//关键词替换，返回是替换成功的次数
	int ReplaceWord(CString OldWord, CString NewWord);
	//扫描文章中最小长度等于Minwordlength且重复出现二次以上的词，存储到DuplicateWordList中//
	//如传入 MinWordLength = 6，则扫描所有重复出现二次以上的，长度=6 的词
	//返回最后得到的重复词的个数
	int ScanDuplicateWords(byte MinWordLength);
	//重复的词列表
	LISTCSTRING DuplicateWordList;
};