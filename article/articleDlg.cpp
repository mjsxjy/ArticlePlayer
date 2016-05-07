
// articleDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "article.h"
#include "articleDlg.h"
#include "afxdialogex.h"
#include "articleHandle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CArticleHandle ch;
CButton* radioReturn;
CButton* radioFullStop;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	
// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:

};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CarticleDlg 对话框



CarticleDlg::CarticleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CarticleDlg::IDD, pParent)
	, strArticle(_T(""))
	, strNewArt(_T(""))
	, StrOldKey(_T(""))
	, StrNewKey(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CarticleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ARTICLE, strArticle);
	DDX_Text(pDX, IDC_NewArt, strNewArt);
	DDX_Control(pDX, IDC_NewArt, conNewArt);
	DDX_Control(pDX, IDC_ARTICLE, conArticle);
	DDX_Text(pDX, IDC_EDIT1, StrOldKey);
	DDX_Text(pDX, IDC_EDIT2, StrNewKey);
}

BEGIN_MESSAGE_MAP(CarticleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CarticleDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CarticleDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CarticleDlg::OnBnClickedButton1)
	ON_EN_SETFOCUS(IDC_ARTICLE, &CarticleDlg::OnSetfocusArticle)
	ON_EN_SETFOCUS(IDC_NewArt, &CarticleDlg::OnEnSetfocusNewart)
	ON_BN_CLICKED(IDC_RADIO2, &CarticleDlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CarticleDlg 消息处理程序

BOOL CarticleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//ShowWindow(SW_MAXIMIZE);

	// TODO:  在此添加额外的初始化代码
	radioReturn = (CButton*)GetDlgItem(IDC_RADIO1);
	radioFullStop = (CButton*)GetDlgItem(IDC_RADIO2);
	radioReturn->SetCheck(1);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CarticleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CarticleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CarticleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CarticleDlg::OnBnClickedOk()
{
	ch.ReSet();
	this->UpdateData(1);
	this->IsNewArticle() ? ch.ReadArticle(this->strNewArt) : ch.ReadArticle(this->strArticle);
	if (radioReturn->GetCheck())
		this->strNewArt = ch.RandOrder(L"\r\n");
	else
		this->strNewArt = ch.RandOrder(L"。");
	UpdateData(0);
}

void CarticleDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CarticleDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	this->UpdateData(1);
	this->IsNewArticle() ? ch.ReadArticle(this->strNewArt) : ch.ReadArticle(this->strArticle);
	this->strNewArt = ch.ReplaceWord(this->StrOldKey, this->StrNewKey);
	UpdateData(0);
}


BOOL CarticleDlg::DestroyWindow()
{
	// TODO:  在此添加专用代码和/或调用基类
	return CDialogEx::DestroyWindow();
}


void CarticleDlg::OnSetfocusArticle()
{
	//自动全选，方便复制
	conArticle.SetSel(0, this->conArticle.GetWindowTextLengthW(), 0);
}

void CarticleDlg::OnEnSetfocusNewart()
{
	//自动全选，方便复制
	conNewArt.SetSel(0, this->conNewArt.GetWindowTextLengthW(), 0);
}

void CarticleDlg::OnBnClickedRadio2()
{
	// TODO:  在此添加控件通知处理程序代码
}

//判断本类里的strNewArt是否为空
bool CarticleDlg::IsNewArticle()
{
	if (this->strNewArt != "")
		return true;
	else
		return false;
}
