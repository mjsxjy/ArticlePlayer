#pragma once

class CarticleHandle
{
public:
	CarticleHandle();
	~CarticleHandle();
	CString cstrArticle;
	//SeparateArticle���ݹ飩�����ְ���cstrSeparatorָ���ķ��ŷָ�������������
	void SeparateArticle(CString cstrArticle, CString cstrSeparator);

	void RandPras();//�������

	void ReSet();
private:
	static const int MAX_PRAS = 50; //��������Ȼ����
	CString PraArray[MAX_PRAS];//����һ�������洢ÿһ�ε�����
	CString TempPraArray[MAX_PRAS];//��ʱ�洢�������������
	int TempNumberArray[MAX_PRAS]; //��ʱ�洢�������������
	int PraCounts = 0;//�洢��Ȼ����
	void RandNumer(int Num); //����������֣��������TempNumberArray��
	INT GetSeparator(CString Separator);
	boolean CheckInput();
};