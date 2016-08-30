
// articleDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	
// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CarticleDlg �Ի���



CarticleDlg::CarticleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CarticleDlg::IDD, pParent)
	, strArticle(_T(""))
	, strNewArt(_T(""))
	//, StrOldKey(_T(""))
	, StrNewKey(_T(""))
	//, strCombo(_T(""))
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
	//	DDX_Text(pDX, IDC_EDIT1, StrOldKey);
	DDX_Text(pDX, IDC_EDIT2, StrNewKey);
	//	DDX_CBString(pDX, IDC_COMBO1, strCombo);
	DDX_Control(pDX, IDC_COMBO1, cCombo);
	DDX_Control(pDX, IDC_COMBO2, cComboLen);
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
	ON_EN_CHANGE(IDC_ARTICLE, &CarticleDlg::OnEnChangeArticle)
	ON_BN_CLICKED(IDC_BUTTON2, &CarticleDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_NewArt, &CarticleDlg::OnEnChangeNewart)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CarticleDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &CarticleDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CarticleDlg ��Ϣ�������

BOOL CarticleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//ShowWindow(SW_MAXIMIZE);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	radioReturn = (CButton*)GetDlgItem(IDC_RADIO1);
	radioFullStop = (CButton*)GetDlgItem(IDC_RADIO2);
	radioReturn->SetCheck(1);
	cComboLen.SetCurSel(3);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CarticleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CarticleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CarticleDlg::OnBnClickedOk()
{
	ch.ReSet();
	this->UpdateData(1);
	this->NewArticle ? ch.ReadArticle(this->strArticle) : ch.ReadArticle(this->strNewArt);
	if (radioReturn->GetCheck())
		this->strNewArt = ch.RandOrder(L"\r\n");
	else
		this->strNewArt = ch.RandOrder(L"��");
	this->NewArticle = false;
	UpdateData(0);
}

void CarticleDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}


void CarticleDlg::OnBnClickedButton1()
{
	this->UpdateData(1);
	this->NewArticle ? ch.ReadArticle(this->strArticle) : ch.ReadArticle(this->strNewArt);
	int index;
	index = cCombo.GetCurSel();
	if (index != -1) cCombo.GetLBText(index, StrOldKey);
	this->strNewArt = ch.ReplaceWord(this->StrOldKey, this->StrNewKey);
	this->NewArticle = false;
	UpdateData(0);
}


BOOL CarticleDlg::DestroyWindow()
{
	return CDialogEx::DestroyWindow();
}


void CarticleDlg::OnSetfocusArticle()
{
	//�Զ�ȫѡ�����㸴��
	conArticle.SetSel(0, this->conArticle.GetWindowTextLengthW(), 0);
}

void CarticleDlg::OnEnSetfocusNewart()
{
	//�Զ�ȫѡ�����㸴��
	conNewArt.SetSel(0, this->conNewArt.GetWindowTextLengthW(), 0);
}

void CarticleDlg::OnBnClickedRadio2()
{
}


void CarticleDlg::OnEnChangeArticle()
{
	this->NewArticle = true;
}


void CarticleDlg::OnBnClickedButton2()
{
	ch.ReSet();
	cCombo.ResetContent();
	this->UpdateData(1);//
	//ch.ReadArticle(this->strArticle);
	
	this->NewArticle ? ch.ReadArticle(this->strArticle) : ch.ReadArticle(this->strNewArt);
	
	int SelectNumber = 0;
	SelectNumber = cComboLen.GetCurSel() + 2;
	ch.ScanDuplicateWords(SelectNumber);

	if (NewArticle) this->strNewArt = this->strArticle;
	std::list<CString>::const_iterator it;
	for (it = ch.DuplicateWordList.begin(); it != ch.DuplicateWordList.end(); it++)
	{
		this->cCombo.AddString(*it);
	}
	this->cCombo.SetCurSel(0);
	ch.DuplicateWordList.clear();
	this->UpdateData(0);

}


void CarticleDlg::OnEnChangeNewart()
{

}


void CarticleDlg::OnCbnSelchangeCombo1()
{
	//int index;
	//index = this->cCombo.GetCurSel();
	//cCombo.GetLBText(index, StrOldKey);
	int index;

	
}


void CarticleDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}
