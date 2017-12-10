// ChangeStudentDataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "student.h"
#include "ChangeStudentDataDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChangeStudentDataDlg dialog


CChangeStudentDataDlg::CChangeStudentDataDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeStudentDataDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangeStudentDataDlg)
	m_id = _T("");
	m_name = _T("");
	m_english_score = _T("");
	m_chinese_score = _T("");
	m_math_score = _T("");
	//}}AFX_DATA_INIT
}


void CChangeStudentDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangeStudentDataDlg)
	DDX_Text(pDX, IDC_STATIC_ID, m_id);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_english_score);
	DDX_Text(pDX, IDC_EDIT_SCORE_CHINESE, m_chinese_score);
	DDX_Text(pDX, IDC_EDIT_SCORE_MATH, m_math_score);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChangeStudentDataDlg, CDialog)
	//{{AFX_MSG_MAP(CChangeStudentDataDlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_STATIC_ID, OnStaticId)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangeStudentDataDlg message handlers

void CChangeStudentDataDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
        m_id = "此学生学号:"+the_StrID;
		m_math_score = the_StrScore_Math;
        m_english_score = the_StrScore_English;
		m_chinese_score = the_StrScore_Chinese;
		m_name = the_StrName;
		UpdateData(FALSE);

}

void CChangeStudentDataDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CChangeStudentDataDlg::OnOK() 
{
    UpdateData(TRUE);
	the_StrName = m_name;
    the_StrScore_English = m_english_score;
    the_StrScore_Math = m_math_score;
    the_StrScore_Chinese = m_chinese_score;
	CDialog::OnOK();
}

void CChangeStudentDataDlg::OnStaticId() 
{
	// TODO: Add your control notification handler code here
	
}
