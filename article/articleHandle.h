#pragma once

class CarticleHandle
{
public:
	CarticleHandle();
	~CarticleHandle();
	CString cstrArticle;
	//递归）将文字按照cstrSeparator指定的符号分隔并传入数组中
	void SeparateArticle(CString cstrArticle, CString cstrSeparator);
	void RandPras();//随机排序
	void ReSet();
	int GetStringIndex(CString cstrTest, CString cstrKey);
private:
	static const int MAX_PRAS = 100; //最大处理的分隔符数
	int KeyIndex = 0;
	CString PraArray[MAX_PRAS];//这是一个用来存储每一分隔的数组
	CString TempPraArray[MAX_PRAS];//临时存储产生的随机数组
	int TempNumberArray[MAX_PRAS]; //临时存储产生的随机数字
	int PraCounts = 0;//存储分隔符数
	void RandNumer(int Num); //产生随机数字，并存放于TempNumberArray中
};