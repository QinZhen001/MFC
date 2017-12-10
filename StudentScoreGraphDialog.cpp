// StudentScoreGraphDialog.cpp : implementation file
//
#include "resource.h"
#include "stdafx.h"
#include "student.h"
#include "studentDlg.h"
#include "StudentScoreGraphDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


extern      CString the_StrID;
extern		CString the_StrName;
extern		CString the_StrSex;
extern		CString the_StrScore_Chinese;
extern		CString the_StrScore_Math;
extern		CString the_StrScore_English;


/////////////////////////////////////////////////////////////////////////////
// CStudentScoreGraphDialog dialog


CStudentScoreGraphDialog::CStudentScoreGraphDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentScoreGraphDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentScoreGraphDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CStudentScoreGraphDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentScoreGraphDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStudentScoreGraphDialog, CDialog)
	//{{AFX_MSG_MAP(CStudentScoreGraphDialog)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_RBUTTONDBLCLK()
	ON_BN_CLICKED(ID_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentScoreGraphDialog message handlers

void CStudentScoreGraphDialog::OnOK() 
{

}

BOOL CStudentScoreGraphDialog::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::Create(IDD, pParentWnd);
}

int CStudentScoreGraphDialog::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DoModal();
}

BOOL CStudentScoreGraphDialog::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::OnNotify(wParam, lParam, pResult);
}

void CStudentScoreGraphDialog::OnPaint() 
{

	//绘图
	//矩形 宽度50
	//底部高：200（y值）
	//顶部高：20（y值）
	//所以每个分值 占1.8个单位
	//最终分数的顶部为 (200-(20+(int)(对应科目分数*1.8))
      	CPaintDC dc(this); // device context for painting

        CDC *pDC = GetDC(); 
        CBrush brush,*pOldBrush;
        brush.CreateSolidBrush(RGB(255,0,0));
        pOldBrush = pDC->SelectObject(&brush);
        int rc_width = 50;
         
        
		int english_score = _ttoi(the_StrScore_English);
			int math_score = _ttoi(the_StrScore_Math);
				int chinese_score = _ttoi(the_StrScore_Chinese);

        for(int i=0;i<3;i++){
		     CRect rc_score(100+i*rc_width,200-(20+(int)(english_score*1.8)),150+i*rc_width,200);
			 CRect rc_subject(100+i*rc_width,180,150+i*rc_width,250);
			 if(i==0){
				 pDC->Rectangle(100+i*rc_width,200-(20+(int)(english_score*1.8)),150+i*rc_width,200);
			    pDC->DrawText(the_StrScore_English,rc_score,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
                pDC->DrawText("英语",rc_subject,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			 }
             
			 if(i==1){
				  pDC->Rectangle(100+i*rc_width,200-(20+(int)(math_score*1.8)),150+i*rc_width,200);
			    pDC->DrawText(the_StrScore_Math,rc_score,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
                pDC->DrawText("数学",rc_subject,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			 }
             
			 if(i==2){
				  pDC->Rectangle(100+i*rc_width,200-(20+(int)(chinese_score*1.8)),150+i*rc_width,200);
			    pDC->DrawText(the_StrScore_Chinese,rc_score,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
				 pDC->DrawText("语文",rc_subject,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			 }
             
		}
       
       
      

  

		CString  str="学号："+the_StrID+"  姓名："+the_StrName+"  性别："+the_StrSex;
        CRect rc_student_info(150,250,600,280);
		pDC->DrawText(str,rc_student_info,DT_CENTER|DT_VCENTER|DT_SINGLELINE);


        pDC->SelectObject(pOldBrush);
        brush.DeleteObject();
        ReleaseDC(pDC);

	
}

void CStudentScoreGraphDialog::CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CDialog::CalcWindowRect(lpClientRect, nAdjustType);
}

int CStudentScoreGraphDialog::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	

	
	return 0;
}

BOOL CStudentScoreGraphDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStudentScoreGraphDialog::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnRButtonDblClk(nFlags, point);
}

void CStudentScoreGraphDialog::OnCancel() 
{
    	CDialog::OnCancel();
}
