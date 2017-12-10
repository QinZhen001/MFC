#if !defined(AFX_STUDENTSCOREGRAPHDIALOG_H__8BCFA11D_3137_4A3B_B248_EADA81786F78__INCLUDED_)
#define AFX_STUDENTSCOREGRAPHDIALOG_H__8BCFA11D_3137_4A3B_B248_EADA81786F78__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StudentScoreGraphDialog.h : header file
//
extern  CString the_StrID;
extern		CString the_StrName;
extern		CString the_StrSex;
extern		CString the_StrScore_English;
extern		CString the_StrScore_Math;
extern		CString the_StrScore_Chinese;

/////////////////////////////////////////////////////////////////////////////
// CStudentScoreGraphDialog dialog

class CStudentScoreGraphDialog : public CDialog
{
// Construction
public:
	CStudentScoreGraphDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStudentScoreGraphDialog)
	enum { IDD = IDD_DIALOG_GRAPH };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentScoreGraphDialog)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	virtual void CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType = adjustBorder);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStudentScoreGraphDialog)
	virtual void OnOK();
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTSCOREGRAPHDIALOG_H__8BCFA11D_3137_4A3B_B248_EADA81786F78__INCLUDED_)
