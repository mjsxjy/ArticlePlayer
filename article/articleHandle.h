#pragma once

class CArticleHandle
{

private:
	CString cstrArticle;//Ψһ�������ַ������£�
	//�ݹ飩�����ְ���cstrSeparatorָ���ķ��ŷָ�������������
	void SeparateArticle(CString cstrArticle, CString cstrSeparator);
	static const int MAX_PRAS = 100; //�����ķָ�����
	static const int MAX_WORDS = 10000; //�������ַ���
	void RandAndSave();//�������
	int KeyIndex = 0;
	CString PraArray[MAX_PRAS];//����һ�������洢ÿһ�ָ�������
	CString TempPraArray[MAX_PRAS];//��ʱ�洢�������������
	int TempNumberArray[MAX_PRAS]; //��ʱ�洢�������������
	int PraCounts = 0;//�洢�ָ�����
	void RandNumer(int Num); //����������֣��������TempNumberArray��
	static const int MAX_DUP_WORDS = 100;

public:
	CArticleHandle();
	~CArticleHandle();
	void ReadArticle(CString Article);
	CString RandOrder(CString Sparator);

	void ReSet();
	//�ؼ����滻����
	CString ReplaceWord(CString OldWord, CString NewWord);
	//һ����־��Ϊ����������ɣ�Ϊ��������δ���
	//BOOL IsDone;
	//��ÿwordlength������ɨ���������ظ����ֵĴʵĴ�������������ֵĴ���22�Σ����ֵĴ���13�εȣ�
	int ScanArticle(byte WordLength);
	CString strDuplicateWord_2[MAX_DUP_WORDS];
	typedef std::list<CString> LISTCSTRING;
	LISTCSTRING DuplicateWordList;
};