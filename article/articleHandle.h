#pragma once

class CArticleHandle
{

private:
	CString cstrArticle;//Ψһ�������ַ������£�
	void SeparateArticle(CString cstrArticle, CString cstrSeparator);//���ݹ飩�����ְ���cstrSeparatorָ���ķ��ŷָ���������ʱ�ڲ�������
	static const int MAX_PRAS = 100; //�����ķָ�����
	static const int MAX_WORDS = 10000; //�������ظ������ַ���
	void RandAndSave();//�����ָ����ֿ��������������򲢱���
	int KeyIndex = 0;
	CString PraArray[MAX_PRAS];//����һ�������洢ÿһ�ָ�������
	CString TempPraArray[MAX_PRAS];//��ʱ�洢�������������
	int TempNumberArray[MAX_PRAS]; //��ʱ�洢�������������
	int PraCounts = 0;//�洢�ָ�����
	void RandNumer(int Num); //����������֣��������TempNumberArray��
	typedef std::list<CString> LISTCSTRING;
	

public:
	CArticleHandle();
	~CArticleHandle();
	void ReadArticle(CString Article);

	CString OutputArticle();//���CArticleHandle��ʱ�����£�Ψһ��

	CString RandOrder(CString Sparator);//����ԭʼ����

	void ReSet();
	//�ؼ����滻���������滻�ɹ��Ĵ���
	int ReplaceWord(CString OldWord, CString NewWord);
	//ɨ����������С���ȵ���Minwordlength���ظ����ֶ������ϵĴʣ��洢��DuplicateWordList��//
	//�紫�� MinWordLength = 6����ɨ�������ظ����ֶ������ϵģ�����=6 �Ĵ�
	//�������õ����ظ��ʵĸ���
	int ScanDuplicateWords(byte MinWordLength);
	//�ظ��Ĵ��б�
	LISTCSTRING DuplicateWordList;
};