#pragma once

class CArticleHandle
{
public:
	CArticleHandle();
	~CArticleHandle();
	void ReadArticle(CString Article);
	CString RandOrder(CString Sparator);
	
	void ReSet();
	//�ؼ����滻����
	CString ReplaceWord(CString OldWord, CString NewWord);
	//һ����־��Ϊ����������ɣ�Ϊ��������δ���
	BOOL IsDoen;
private:
	CString cstrArticle;//Ψһ�������ַ������£�
	//�ݹ飩�����ְ���cstrSeparatorָ���ķ��ŷָ�������������
	void SeparateArticle(CString cstrArticle, CString cstrSeparator);
	static const int MAX_PRAS = 100; //�����ķָ�����
	void RandAndSave();//�������
	int KeyIndex = 0;
	CString PraArray[MAX_PRAS];//����һ�������洢ÿһ�ָ�������
	CString TempPraArray[MAX_PRAS];//��ʱ�洢�������������
	int TempNumberArray[MAX_PRAS]; //��ʱ�洢�������������
	int PraCounts = 0;//�洢�ָ�����
	void RandNumer(int Num); //����������֣��������TempNumberArray��
};