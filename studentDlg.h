// studentDlg.h : header file
//

#if !defined(AFX_STUDENTDLG_H__3C0D896C_3FD9_4C3F_A5C6_0C014DF42A5D__INCLUDED_)
#define AFX_STUDENTDLG_H__3C0D896C_3FD9_4C3F_A5C6_0C014DF42A5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg dialog
extern  CString the_StrID;
extern		CString the_StrName;
extern		CString the_StrSex;
extern		CString the_StrScore_English;
extern		CString the_StrScore_Math;
extern		CString the_StrScore_Chinese;

class CStudentDlg : public CDialog
{
// Construction
private:
	//int num=0;
public:
	//int num;
	CStudentDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStudentDlg)
	enum { IDD = IDD_STUDENT_DIALOG };
	CEdit	m_MATH_SCORE;
	CEdit	m_CHINESE_SCORE;
	CEdit	m_SCORE;
	CEdit	m_NAME;
	CEdit	m_ID;
	CListCtrl	m_ListControl;
	CString	m_id;
	CString	m_name;
	CString	m_score;
	int		m_Sex;
	CString	m_Show;
	CString	m_chinese_score;
	CString	m_math_score;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStudentDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnMenuitemDispaly();
	afx_msg void OnMenuitemSort();
	afx_msg void OnSearch();
	afx_msg void OnMenuitemExit();
	afx_msg void OnMenuitemLeadIn();
	afx_msg void OnButton_show_scoregraphdialog();
	afx_msg void OnMenuitemSortByIdN();
	afx_msg void OnMenuitemSortByIdR();
	afx_msg void OnMenuitemSortByEnglishN();
	afx_msg void OnMenuitemSortByEnglishR();
	afx_msg void OnMenuitemSortByChineseN();
	afx_msg void OnMenuitemSortByChineseR();
	afx_msg void OnMenuitemSortByMathN();
	afx_msg void OnMenuitemSortByMathR();
	afx_msg void OnButtonChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTDLG_H__3C0D896C_3FD9_4C3F_A5C6_0C014DF42A5D__INCLUDED_)
