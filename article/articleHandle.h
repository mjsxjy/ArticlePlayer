#pragma once
class CarticleHandle
{
public:
	CarticleHandle();
	~CarticleHandle();
	CString cstrArticle;

	BOOLEAN GetParagraphs(CString cstrArticle);//（递归）将文字按照段落传入数组中
	void RandPras();//随机排序段落
	void ReSet();
private:
	static const int MAX_PRAS = 50; //最大处理的字然段数
	CString PraArray[MAX_PRAS];//这是一个用来存储每一段的数组
	CString TempPraArray[MAX_PRAS];//临时存储产生的随机数组
	int TempNumberArray[MAX_PRAS]; //临时存储产生的随机数字
	int PraCounts = 0;//存储字然段数
	void RandNumer(int Num); //产生随机数字，并存放于TempNumberArray中

};
