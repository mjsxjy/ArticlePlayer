
// articleDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CarticleDlg �Ի���
class CarticleDlg : public CDialogEx
{
// ����
public:
	CarticleDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ARTICLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();
public:
	afx_msg void OnBnClickedOk();
	CString strArticle;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	virtual BOOL DestroyWindow();
	CString strNewArt;
	CEdit conNewArt;
	afx_msg void OnSetfocusArticle();
	CEdit conArticle;
	afx_msg void OnEnSetfocusNewart();
	afx_msg void OnBnClickedRadio2();
	CString StrOldKey;
	CString StrNewKey;
private:
	//bool IsNewArticle();
	bool NewArticle;//�ж��Ƿ���������
	
public:
	afx_msg void OnEnChangeArticle();
	afx_msg void OnBnClickedButton2();
	//CString strCombo;
	CComboBox cCombo;
	afx_msg void OnEnChangeNewart();
	afx_msg void OnCbnSelchangeCombo1();
};
