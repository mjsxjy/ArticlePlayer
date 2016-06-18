
// articleDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CarticleDlg 对话框
class CarticleDlg : public CDialogEx
{
// 构造
public:
	CarticleDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ARTICLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
	bool NewArticle;//判断是否是新文章
	
public:
	afx_msg void OnEnChangeArticle();
	afx_msg void OnBnClickedButton2();
	//CString strCombo;
	CComboBox cCombo;
	afx_msg void OnEnChangeNewart();
	afx_msg void OnCbnSelchangeCombo1();
};
