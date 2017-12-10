#if !defined(AFX_CHANGESTUDENTDATADLG_H__8F27F66D_7956_4F77_9700_9824E6D295B0__INCLUDED_)
#define AFX_CHANGESTUDENTDATADLG_H__8F27F66D_7956_4F77_9700_9824E6D295B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChangeStudentDataDlg.h : header file
//
extern      CString the_StrID;
extern		CString the_StrName;
extern		CString the_StrSex;
extern		CString the_StrScore_Chinese;
extern		CString the_StrScore_Math;
extern		CString the_StrScore_English;
/////////////////////////////////////////////////////////////////////////////
// CChangeStudentDataDlg dialog

class CChangeStudentDataDlg : public CDialog
{
// Construction
public:
	CChangeStudentDataDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChangeStudentDataDlg)
	enum { IDD = IDD_DIALOG_CHANGE_ITEM };
	CString	m_id;
	CString	m_name;
	CString	m_english_score;
	CString	m_chinese_score;
	CString	m_math_score;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeStudentDataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChangeStudentDataDlg)
	afx_msg void OnPaint();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnStaticId();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGESTUDENTDATADLG_H__8F27F66D_7956_4F77_9700_9824E6D295B0__INCLUDED_)
