#pragma once

class CarticleHandle
{
public:
	CarticleHandle();
	~CarticleHandle();
	CString cstrArticle;
	//�ݹ飩�����ְ���cstrSeparatorָ���ķ��ŷָ�������������
	void SeparateArticle(CString cstrArticle, CString cstrSeparator);
	void RandPras();//�������
	void ReSet();
	int GetStringIndex(CString cstrTest, CString cstrKey);
private:
	static const int MAX_PRAS = 100; //�����ķָ�����
	int KeyIndex = 0;
	CString PraArray[MAX_PRAS];//����һ�������洢ÿһ�ָ�������
	CString TempPraArray[MAX_PRAS];//��ʱ�洢�������������
	int TempNumberArray[MAX_PRAS]; //��ʱ�洢�������������
	int PraCounts = 0;//�洢�ָ�����
	void RandNumer(int Num); //����������֣��������TempNumberArray��
};