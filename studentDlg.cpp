// studentDlg.cpp : implementation file
//
#include "stdafx.h"
#include "student.h"
#include "studentDlg.h"
#include "StudentScoreGraphDialog.h"
#include "ChangeStudentDataDlg.h"
#include <string>
#include<fstream>
#include <iostream>  
#include<malloc.h>
#include <string>
using namespace std;



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
//int num=0;
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg dialog

CStudentDlg::CStudentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentDlg::IDD, pParent)
{
	//m_male=0;
	//{{AFX_DATA_INIT(CStudentDlg)
	m_id = _T("");
	m_name = _T("");
	m_score = _T("");
	m_Sex = -1;
	m_Show = _T("");
	m_chinese_score = _T("");
	m_math_score = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentDlg)
	DDX_Control(pDX, IDC_EDIT_SCORE_MATH, m_MATH_SCORE);
	DDX_Control(pDX, IDC_EDIT_SCORE_CHINESE, m_CHINESE_SCORE);
	DDX_Control(pDX, IDC_EDIT_SCORE, m_SCORE);
	DDX_Control(pDX, IDC_EDIT_NAME, m_NAME);
	DDX_Control(pDX, IDC_EDIT_ID, m_ID);
	DDX_Control(pDX, IDC_LIST, m_ListControl);
	DDX_Text(pDX, IDC_EDIT_ID, m_id);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_score);
	DDX_Radio(pDX, IDC_RADIO_M, m_Sex);
	DDX_Text(pDX, IDC_EDIT_SCORE_CHINESE, m_chinese_score);
	DDX_Text(pDX, IDC_EDIT_SCORE_MATH, m_math_score);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStudentDlg, CDialog)
	//{{AFX_MSG_MAP(CStudentDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnDelete)
	ON_COMMAND(ID_MENUITEM_DISPALY, OnMenuitemDispaly)
	ON_COMMAND(ID_MENUITEM_SORT, OnMenuitemSort)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnSearch)
	ON_COMMAND(ID_MENUITEM_EXIT, OnMenuitemExit)
	ON_COMMAND(ID_MENUITEM_LEAD_IN, OnMenuitemLeadIn)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH2, OnButton_show_scoregraphdialog)
	ON_COMMAND(ID_MENUITEM_SORT_BY_ID_N, OnMenuitemSortByIdN)
	ON_COMMAND(ID_MENUITEM_SORT_BY_ID_R, OnMenuitemSortByIdR)
	ON_COMMAND(ID_MENUITEM_SORT_BY_ENGLISH_N, OnMenuitemSortByEnglishN)
	ON_COMMAND(ID_MENUITEM_SORT_BY_ENGLISH_R, OnMenuitemSortByEnglishR)
	ON_COMMAND(ID_MENUITEM_SORT_BY_CHINESE_N, OnMenuitemSortByChineseN)
	ON_COMMAND(ID_MENUITEM_SORT_BY_CHINESE_R, OnMenuitemSortByChineseR)
	ON_COMMAND(ID_MENUITEM_SORT_BY_MATH_N, OnMenuitemSortByMathN)
	ON_COMMAND(ID_MENUITEM_SORT_BY_MATH_R, OnMenuitemSortByMathR)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, OnButtonChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg message handlers

BOOL CStudentDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_ListControl.InsertColumn(0,"学号",LVCFMT_LEFT,90);
    m_ListControl.InsertColumn(1,"姓名",LVCFMT_LEFT,50);
	m_ListControl.InsertColumn(2,"性别",LVCFMT_LEFT,50);
	m_ListControl.InsertColumn(3,"英语成绩",LVCFMT_LEFT,90);
		m_ListControl.InsertColumn(5,"数学成绩",LVCFMT_LEFT,90);
			m_ListControl.InsertColumn(6,"语文成绩",LVCFMT_LEFT,90);

    
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStudentDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStudentDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStudentDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStudentDlg::OnAdd() 
{
 
	UpdateData(TRUE);
	m_ID.GetWindowText(m_id);
	m_NAME.GetWindowText(m_name);
    m_SCORE.GetWindowText(m_score);
    m_MATH_SCORE.GetWindowText(m_math_score);
	m_CHINESE_SCORE.GetWindowText(m_chinese_score);

	if(m_id==""){
        CString str = "学号不能为空!";
		MessageBox(str);
		return;
	}
	if(m_name==""){
        CString str = "姓名不能为空!";
		MessageBox(str);
		return;
	}
		if(m_score==""){
        CString str = "英语成绩不能为空!";
		MessageBox(str);
		return;
	}
		if(m_math_score==""){
        CString str = "数学成绩不能为空!";
		MessageBox(str);
		return;
	}
	if(m_chinese_score==""){
        CString str = "语文成绩不能为空!";
		MessageBox(str);
		return;
	}

	m_ListControl.InsertItem(0,m_id);
	m_ListControl.SetItemText(0,1,m_name);
	UpdateData(TRUE);
	if(m_Sex==1)
		m_ListControl.SetItemText(0,2,"女");
	else
		 m_ListControl.SetItemText(0,2,"男");

	
	m_ListControl.SetItemText(0,3,m_score); 
	m_ListControl.SetItemText(0,4,m_math_score);
	m_ListControl.SetItemText(0,5,m_chinese_score);

	//num++;
	
	UpdateData(TRUE);
	m_id="";
	m_name="";
	m_Sex=-1;
	m_score="";
	m_math_score="";
    m_chinese_score="";
	UpdateData(FALSE);

}

void CStudentDlg::OnDelete() 
{
	UpdateData(TRUE);
	int i=0,num=0,idx;
	while(m_ListControl.GetItemText(i,0)!="")
	{
		i++;
		num++;
		
	}
	m_ID.GetWindowText(m_id);
    	if(m_id==""){
        CString str = "学号为空，无法删除!";
		MessageBox(str);
		return;
	}

	for(i=0;i<num;i++)
	{
	       if(m_id==m_ListControl.GetItemText(i,0))
		   {
		      m_ListControl.DeleteItem(i);
			  break;   
		   }
	}
	UpdateData(TRUE);
	m_id="";
	UpdateData(FALSE);
    idx=m_ListControl.GetSelectionMark();
    m_ListControl.DeleteItem(idx);
    UpdateData(TRUE);
}

void CStudentDlg::OnMenuitemDispaly() 
{
	// TODO: Add your command handler code here
	ofstream  fp("D:\\student.txt",ofstream::out);
	 //fp.open("D:\\student.txt");
	string StrID,StrName,StrSex,StrScore_English,StrScore_Math,StrScore_Chinese;
	int i=0;
	int num=0;

	while(m_ListControl.GetItemText(i,0)!="")
	{
		i++;
		num++;
	}


	for(i=0;i<=num;i++)
	{
       StrID=m_ListControl.GetItemText(i,0);
	   StrName=m_ListControl.GetItemText(i,1);
	   StrSex=m_ListControl.GetItemText(i,2);
       StrScore_English=m_ListControl.GetItemText(i,3);
       StrScore_Math=m_ListControl.GetItemText(i,4);
        StrScore_Chinese=m_ListControl.GetItemText(i,5);
	   fp<<StrID<<" "<<StrName<<" "<<StrSex<<" "<<StrScore_English<<" "<<StrScore_Math<<" "<<StrScore_Chinese<<endl;
	}
	fp.close();
}

void CStudentDlg::OnMenuitemSort() 
{
    //这里是排序的一级菜单 所以为空
}

void CStudentDlg::OnSearch() 
{
	int i=0,num=0,k=0;
	CString str;
	while(m_ListControl.GetItemText(i,0)!="")
	{
		i++;
		num++;
		
	}
	for(i=0;i<num;i++)
	{
		m_ID.GetWindowText(m_id);
		if(m_ListControl.GetItemText(i,0)==m_id)
		{
			m_ListControl.SetItemState(i,LVIS_SELECTED, LVIS_SELECTED);
			str="学号："+m_ListControl.GetItemText(i,0)+"\n"+"姓名："+m_ListControl.GetItemText(i,1)+"\n"+"性别："+m_ListControl.GetItemText(i,2)+"\n"+"英语成绩："+m_ListControl.GetItemText(i,3)+"\n"+"数学成绩："+m_ListControl.GetItemText(i,4)+"\n"+"语文成绩："+m_ListControl.GetItemText(i,5);
			MessageBox(str);
			break;
		}
		else k++;
	}
	if(k==num)
    MessageBox("该学生不存在！");
	UpdateData(TRUE);
	m_id="";
	UpdateData(FALSE);
}

void CStudentDlg::OnMenuitemExit() 
{
	// TODO: Add your command handler code here
	exit(0);
	
}

void CStudentDlg::OnMenuitemLeadIn() 
{
	

    ifstream infile("D:\\student.txt");
    string s;
	int num=0;
	int step =0;
	m_ListControl.DeleteAllItems();
	while (!infile.eof())  {
     	infile >> s;
		//将string转化成CString
        CString strMfc;
        strMfc=s.c_str();

		if(num%6==0)
       	m_ListControl.InsertItem(step,strMfc);
		if(num%6==1)
		m_ListControl.SetItemText(step,1,strMfc);
        if(num%6==2)
		m_ListControl.SetItemText(step,2,strMfc);
		if(num%6==3)
		m_ListControl.SetItemText(step,3,strMfc);
	     if(num%6==4)
		m_ListControl.SetItemText(step,4,strMfc);
        if(num%6==5)
		m_ListControl.SetItemText(step,5,strMfc);

		num++;
		step= num/6;

	}
		infile.close();



	UpdateData(FALSE);

}

void CStudentDlg::OnButton_show_scoregraphdialog() 
{

	int i=0,num=0,k=0;
	CString str;
	while(m_ListControl.GetItemText(i,0)!="")
	{
		i++;
		num++;
		
	}
	for(i=0;i<num;i++)
	{
		m_ID.GetWindowText(m_id);
		if(m_ListControl.GetItemText(i,0)==m_id)
		{
			the_StrID = m_ListControl.GetItemText(i,0);
            the_StrName = m_ListControl.GetItemText(i,1);
			the_StrSex = m_ListControl.GetItemText(i,2);	
			the_StrScore_English = m_ListControl.GetItemText(i,3);
			the_StrScore_Math = m_ListControl.GetItemText(i,4);
			the_StrScore_Chinese = m_ListControl.GetItemText(i,5);
			break;
		}
		else k++;
	}
	if(k==num){
		 MessageBox("该学生不存在！");
		 UpdateData(TRUE);
	     m_id="";
        	UpdateData(FALSE);
	}else{
		CStudentScoreGraphDialog graphDialog;
        graphDialog.DoModal();
	
	}
   
	

   
}



void CStudentDlg::OnMenuitemSortByIdN() 
{
   CString StrText1,StrText2;
    int num,i,flag,j;
	int score1,score2;
	num=0;
	i=0;
	while(m_ListControl.GetItemText(i,0)!="")
	{
		num++;
		i++;
	}
	struct StudentItem ListItem[100];

	for(i=0;i<num;i++)
	{
		ListItem[i].StrID=m_ListControl.GetItemText(i,0);
        ListItem[i].StrName=m_ListControl.GetItemText(i,1);
		ListItem[i].StrSex=m_ListControl.GetItemText(i,2);
		ListItem[i].StrScore_English=m_ListControl.GetItemText(i,3);
		ListItem[i].StrScore_Math=m_ListControl.GetItemText(i,4);
    	ListItem[i].StrScore_Chinese=m_ListControl.GetItemText(i,5);
	}

	for(i=num-1;i>=0;i--)
	{
		UpdateData(TRUE);
         m_ListControl.DeleteItem(i);
        UpdateData(FALSE);
	}

	for(i=0;i<num-1;i++)
	{
		flag=1;
		for(j=0;j<num-i-1;j++)
		{
			StrText1=ListItem[j].StrID;
			score1=_tcstoul(StrText1,NULL,10);
			StrText2=ListItem[j+1].StrID;
			score2=_tcstoul(StrText2,NULL,10);

			if(score1<score2)
			{
				struct StudentItem TempItem;

				TempItem.StrID=ListItem[j].StrID;
                TempItem.StrName=ListItem[j].StrName;
				TempItem.StrSex=ListItem[j].StrSex;
				TempItem.StrScore_English=ListItem[j].StrScore_English;
				TempItem.StrScore_Math=ListItem[j].StrScore_Math;
				TempItem.StrScore_Chinese=ListItem[j].StrScore_Chinese;

				ListItem[j].StrID=ListItem[j+1].StrID;
                ListItem[j].StrName=ListItem[j+1].StrName;
				ListItem[j].StrSex=ListItem[j+1].StrSex;
				ListItem[j].StrScore_English=ListItem[j+1].StrScore_English;
	            ListItem[j].StrScore_Math=ListItem[j+1].StrScore_Math;
				 ListItem[j].StrScore_Chinese=ListItem[j+1].StrScore_Chinese;

				ListItem[j+1].StrID=TempItem.StrID;
				ListItem[j+1].StrName=TempItem.StrName;
				ListItem[j+1].StrSex=TempItem.StrSex;
				ListItem[j+1].StrScore_English=TempItem.StrScore_English;
                	ListItem[j+1].StrScore_Math=TempItem.StrScore_Math;
						ListItem[j+1].StrScore_Chinese=TempItem.StrScore_Chinese;
				
				flag=0;
			}
		}
		if(flag==1)
			break;
	}


	for(i=0;i<num;i++)
	{
		m_ListControl.InsertItem(0,ListItem[i].StrID);
		m_ListControl.SetItemText(0,1,ListItem[i].StrName);
		m_ListControl.SetItemText(0,2,ListItem[i].StrSex);
		m_ListControl.SetItemText(0,3,ListItem[i].StrScore_English);
			m_ListControl.SetItemText(0,4,ListItem[i].StrScore_Math);
     	m_ListControl.SetItemText(0,5,ListItem[i].StrScore_Chinese);

	}
	
}


void CStudentDlg::OnMenuitemSortByIdR() 
{
 CString StrText1,StrText2;
    int num,i,flag,j;
	int score1,score2;
	num=0;
	i=0;
	while(m_ListControl.GetItemText(i,0)!="")
	{
		num++;
		i++;
	}
	struct StudentItem ListItem[100];

	for(i=0;i<num;i++)
	{
		ListItem[i].StrID=m_ListControl.GetItemText(i,0);
        ListItem[i].StrName=m_ListControl.GetItemText(i,1);
		ListItem[i].StrSex=m_ListControl.GetItemText(i,2);
		ListItem[i].StrScore_English=m_ListControl.GetItemText(i,3);
		ListItem[i].StrScore_Math=m_ListControl.GetItemText(i,4);
    	ListItem[i].StrScore_Chinese=m_ListControl.GetItemText(i,5);
	}

	for(i=num-1;i>=0;i--)
	{
		UpdateData(TRUE);
         m_ListControl.DeleteItem(i);
        UpdateData(FALSE);
	}

	for(i=0;i<num-1;i++)
	{
		flag=1;
		for(j=0;j<num-i-1;j++)
		{
			StrText1=ListItem[j].StrID;
			score1=_tcstoul(StrText1,NULL,10);
			StrText2=ListItem[j+1].StrID;
			score2=_tcstoul(StrText2,NULL,10);

			if(score1>score2)
			{
				struct StudentItem TempItem;

				TempItem.StrID=ListItem[j].StrID;
                TempItem.StrName=ListItem[j].StrName;
				TempItem.StrSex=ListItem[j].StrSex;
				TempItem.StrScore_English=ListItem[j].StrScore_English;
				TempItem.StrScore_Math=ListItem[j].StrScore_Math;
				TempItem.StrScore_Chinese=ListItem[j].StrScore_Chinese;

				ListItem[j].StrID=ListItem[j+1].StrID;
                ListItem[j].StrName=ListItem[j+1].StrName;
				ListItem[j].StrSex=ListItem[j+1].StrSex;
				ListItem[j].StrScore_English=ListItem[j+1].StrScore_English;
	            ListItem[j].StrScore_Math=ListItem[j+1].StrScore_Math;
				 ListItem[j].StrScore_Chinese=ListItem[j+1].StrScore_Chinese;

				ListItem[j+1].StrID=TempItem.StrID;
				ListItem[j+1].StrName=TempItem.StrName;
				ListItem[j+1].StrSex=TempItem.StrSex;
				ListItem[j+1].StrScore_English=TempItem.StrScore_English;
                	ListItem[j+1].StrScore_Math=TempItem.StrScore_Math;
						ListItem[j+1].StrScore_Chinese=TempItem.StrScore_Chinese;
				
				flag=0;
			}
		}
		if(flag==1)
			break;
	}
	for(i=0;i<num;i++)
	{
		m_ListControl.InsertItem(0,ListItem[i].StrID);
		m_ListControl.SetItemText(0,1,ListItem[i].StrName);
		m_ListControl.SetItemText(0,2,ListItem[i].StrSex);
		m_ListControl.SetItemText(0,3,ListItem[i].StrScore_English);
			m_ListControl.SetItemText(0,4,ListItem[i].StrScore_Math);
     	m_ListControl.SetItemText(0,5,ListItem[i].StrScore_Chinese);

	}
	
}

void CStudentDlg::OnMenuitemSortByEnglishN() 
{
	CString StrText1,StrText2;
    int num,i,flag,j;
	int score1,score2;
	num=0;
	i=0;
	while(m_ListControl.GetItemText(i,3)!="")
	{
		num++;
		i++;
	}
	struct StudentItem ListItem[100];

	for(i=0;i<num;i++)
	{
		ListItem[i].StrID=m_ListControl.GetItemText(i,0);
        ListItem[i].StrName=m_ListControl.GetItemText(i,1);
		ListItem[i].StrSex=m_ListControl.GetItemText(i,2);
		ListItem[i].StrScore_English=m_ListControl.GetItemText(i,3);
		ListItem[i].StrScore_Math=m_ListControl.GetItemText(i,4);
    	ListItem[i].StrScore_Chinese=m_ListControl.GetItemText(i,5);
	}

	for(i=num-1;i>=0;i--)
	{
		UpdateData(TRUE);
         m_ListControl.DeleteItem(i);
        UpdateData(FALSE);
	}

	for(i=0;i<num-1;i++)
	{
		flag=1;
		for(j=0;j<num-i-1;j++)
		{
			StrText1=ListItem[j].StrScore_English;
			score1=_tcstoul(StrText1,NULL,10);
			StrText2=ListItem[j+1].StrScore_English;
			score2=_tcstoul(StrText2,NULL,10);

			if(score1<score2)
			{
				struct StudentItem TempItem;

				TempItem.StrID=ListItem[j].StrID;
                TempItem.StrName=ListItem[j].StrName;
				TempItem.StrSex=ListItem[j].StrSex;
				TempItem.StrScore_English=ListItem[j].StrScore_English;
				TempItem.StrScore_Math=ListItem[j].StrScore_Math;
				TempItem.StrScore_Chinese=ListItem[j].StrScore_Chinese;




				ListItem[j].StrID=ListItem[j+1].StrID;
                ListItem[j].StrName=ListItem[j+1].StrName;
				ListItem[j].StrSex=ListItem[j+1].StrSex;
				ListItem[j].StrScore_English=ListItem[j+1].StrScore_English;
	            ListItem[j].StrScore_Math=ListItem[j+1].StrScore_Math;
				 ListItem[j].StrScore_Chinese=ListItem[j+1].StrScore_Chinese;

      

				ListItem[j+1].StrID=TempItem.StrID;
				ListItem[j+1].StrName=TempItem.StrName;
				ListItem[j+1].StrSex=TempItem.StrSex;
				ListItem[j+1].StrScore_English=TempItem.StrScore_English;
                	ListItem[j+1].StrScore_Math=TempItem.StrScore_Math;
						ListItem[j+1].StrScore_Chinese=TempItem.StrScore_Chinese;
				
				flag=0;
			}
		}
		if(flag==1)
			break;
	}


	for(i=0;i<num;i++)
	{
		m_ListControl.InsertItem(0,ListItem[i].StrID);
		m_ListControl.SetItemText(0,1,ListItem[i].StrName);
		m_ListControl.SetItemText(0,2,ListItem[i].StrSex);
		m_ListControl.SetItemText(0,3,ListItem[i].StrScore_English);
			m_ListControl.SetItemText(0,4,ListItem[i].StrScore_Math);
     	m_ListControl.SetItemText(0,5,ListItem[i].StrScore_Chinese);

	}
	
}

void CStudentDlg::OnMenuitemSortByEnglishR() 
{
CString StrText1,StrText2;
    int num,i,flag,j;
	int score1,score2;
	num=0;
	i=0;
	while(m_ListControl.GetItemText(i,3)!="")
	{
		num++;
		i++;
	}
	struct StudentItem ListItem[100];

	for(i=0;i<num;i++)
	{
		ListItem[i].StrID=m_ListControl.GetItemText(i,0);
        ListItem[i].StrName=m_ListControl.GetItemText(i,1);
		ListItem[i].StrSex=m_ListControl.GetItemText(i,2);
		ListItem[i].StrScore_English=m_ListControl.GetItemText(i,3);
		ListItem[i].StrScore_Math=m_ListControl.GetItemText(i,4);
    	ListItem[i].StrScore_Chinese=m_ListControl.GetItemText(i,5);
	}

	for(i=num-1;i>=0;i--)
	{
		UpdateData(TRUE);
         m_ListControl.DeleteItem(i);
        UpdateData(FALSE);
	}

	for(i=0;i<num-1;i++)
	{
		flag=1;
		for(j=0;j<num-i-1;j++)
		{
			StrText1=ListItem[j].StrScore_English;
			score1=_tcstoul(StrText1,NULL,10);
			StrText2=ListItem[j+1].StrScore_English;
			score2=_tcstoul(StrText2,NULL,10);

			if(score1>score2)
			{
				struct StudentItem TempItem;

				TempItem.StrID=ListItem[j].StrID;
                TempItem.StrName=ListItem[j].StrName;
				TempItem.StrSex=ListItem[j].StrSex;
				TempItem.StrScore_English=ListItem[j].StrScore_English;
				TempItem.StrScore_Math=ListItem[j].StrScore_Math;
				TempItem.StrScore_Chinese=ListItem[j].StrScore_Chinese;




				ListItem[j].StrID=ListItem[j+1].StrID;
                ListItem[j].StrName=ListItem[j+1].StrName;
				ListItem[j].StrSex=ListItem[j+1].StrSex;
				ListItem[j].StrScore_English=ListItem[j+1].StrScore_English;
	            ListItem[j].StrScore_Math=ListItem[j+1].StrScore_Math;
				 ListItem[j].StrScore_Chinese=ListItem[j+1].StrScore_Chinese;

      

				ListItem[j+1].StrID=TempItem.StrID;
				ListItem[j+1].StrName=TempItem.StrName;
				ListItem[j+1].StrSex=TempItem.StrSex;
				ListItem[j+1].StrScore_English=TempItem.StrScore_English;
                	ListItem[j+1].StrScore_Math=TempItem.StrScore_Math;
						ListItem[j+1].StrScore_Chinese=TempItem.StrScore_Chinese;
				
				flag=0;
			}
		}
		if(flag==1)
			break;
	}


	for(i=0;i<num;i++)
	{
		m_ListControl.InsertItem(0,ListItem[i].StrID);
		m_ListControl.SetItemText(0,1,ListItem[i].StrName);
		m_ListControl.SetItemText(0,2,ListItem[i].StrSex);
		m_ListControl.SetItemText(0,3,ListItem[i].StrScore_English);
			m_ListControl.SetItemText(0,4,ListItem[i].StrScore_Math);
     	m_ListControl.SetItemText(0,5,ListItem[i].StrScore_Chinese);

	}
	
}

void CStudentDlg::OnMenuitemSortByChineseN() 
{
	CString StrText1,StrText2;
    int num,i,flag,j;
	int score1,score2;
	num=0;
	i=0;
	while(m_ListControl.GetItemText(i,0)!="")
	{
		num++;
		i++;
	}
	struct StudentItem ListItem[100];

	for(i=0;i<num;i++)
	{
		ListItem[i].StrID=m_ListControl.GetItemText(i,0);
        ListItem[i].StrName=m_ListControl.GetItemText(i,1);
		ListItem[i].StrSex=m_ListControl.GetItemText(i,2);
		ListItem[i].StrScore_English=m_ListControl.GetItemText(i,3);
		ListItem[i].StrScore_Math=m_ListControl.GetItemText(i,4);
    	ListItem[i].StrScore_Chinese=m_ListControl.GetItemText(i,5);
	}

	for(i=num-1;i>=0;i--)
	{
	    	UpdateData(TRUE);
         m_ListControl.DeleteItem(i);
          UpdateData(FALSE);
	}

	for(i=0;i<num-1;i++)
	{
		flag=1;
		for(j=0;j<num-i-1;j++)
		{
			StrText1=ListItem[j].StrScore_Chinese;
			score1=_tcstoul(StrText1,NULL,10);
			StrText2=ListItem[j+1].StrScore_Chinese;
			score2=_tcstoul(StrText2,NULL,10);

			if(score1<score2)
			{
				struct StudentItem TempItem;

				TempItem.StrID=ListItem[j].StrID;
                TempItem.StrName=ListItem[j].StrName;
				TempItem.StrSex=ListItem[j].StrSex;
				TempItem.StrScore_English=ListItem[j].StrScore_English;
				TempItem.StrScore_Math=ListItem[j].StrScore_Math;
				TempItem.StrScore_Chinese=ListItem[j].StrScore_Chinese;

				ListItem[j].StrID=ListItem[j+1].StrID;
                ListItem[j].StrName=ListItem[j+1].StrName;
				ListItem[j].StrSex=ListItem[j+1].StrSex;
				ListItem[j].StrScore_English=ListItem[j+1].StrScore_English;
	            ListItem[j].StrScore_Math=ListItem[j+1].StrScore_Math;
				 ListItem[j].StrScore_Chinese=ListItem[j+1].StrScore_Chinese;

				ListItem[j+1].StrID=TempItem.StrID;
				ListItem[j+1].StrName=TempItem.StrName;
				ListItem[j+1].StrSex=TempItem.StrSex;
				ListItem[j+1].StrScore_English=TempItem.StrScore_English;
                	ListItem[j+1].StrScore_Math=TempItem.StrScore_Math;
						ListItem[j+1].StrScore_Chinese=TempItem.StrScore_Chinese;
				
				flag=0;
			}
		}
		if(flag==1)
			break;
	}
	for(i=0;i<num;i++)
	{
		m_ListControl.InsertItem(0,ListItem[i].StrID);
		m_ListControl.SetItemText(0,1,ListItem[i].StrName);
		m_ListControl.SetItemText(0,2,ListItem[i].StrSex);
		m_ListControl.SetItemText(0,3,ListItem[i].StrScore_English);
			m_ListControl.SetItemText(0,4,ListItem[i].StrScore_Math);
     	m_ListControl.SetItemText(0,5,ListItem[i].StrScore_Chinese);

	}
	
}

void CStudentDlg::OnMenuitemSortByChineseR() 
{
	CString StrText1,StrText2;
    int num,i,flag,j;
	int score1,score2;
	num=0;
	i=0;
	while(m_ListControl.GetItemText(i,0)!="")
	{
		num++;
		i++;
	}
	struct StudentItem ListItem[100];

	for(i=0;i<num;i++)
	{
		ListItem[i].StrID=m_ListControl.GetItemText(i,0);
        ListItem[i].StrName=m_ListControl.GetItemText(i,1);
		ListItem[i].StrSex=m_ListControl.GetItemText(i,2);
		ListItem[i].StrScore_English=m_ListControl.GetItemText(i,3);
		ListItem[i].StrScore_Math=m_ListControl.GetItemText(i,4);
    	ListItem[i].StrScore_Chinese=m_ListControl.GetItemText(i,5);
	}

	for(i=num-1;i>=0;i--)
	{
	    	UpdateData(TRUE);
         m_ListControl.DeleteItem(i);
          UpdateData(FALSE);
	}

	for(i=0;i<num-1;i++)
	{
		flag=1;
		for(j=0;j<num-i-1;j++)
		{
			StrText1=ListItem[j].StrScore_Chinese;
			score1=_tcstoul(StrText1,NULL,10);
			StrText2=ListItem[j+1].StrScore_Chinese;
			score2=_tcstoul(StrText2,NULL,10);

			if(score1>score2)
			{
				struct StudentItem TempItem;

				TempItem.StrID=ListItem[j].StrID;
                TempItem.StrName=ListItem[j].StrName;
				TempItem.StrSex=ListItem[j].StrSex;
				TempItem.StrScore_English=ListItem[j].StrScore_English;
				TempItem.StrScore_Math=ListItem[j].StrScore_Math;
				TempItem.StrScore_Chinese=ListItem[j].StrScore_Chinese;

				ListItem[j].StrID=ListItem[j+1].StrID;
                ListItem[j].StrName=ListItem[j+1].StrName;
				ListItem[j].StrSex=ListItem[j+1].StrSex;
				ListItem[j].StrScore_English=ListItem[j+1].StrScore_English;
	            ListItem[j].StrScore_Math=ListItem[j+1].StrScore_Math;
				 ListItem[j].StrScore_Chinese=ListItem[j+1].StrScore_Chinese;

				ListItem[j+1].StrID=TempItem.StrID;
				ListItem[j+1].StrName=TempItem.StrName;
				ListItem[j+1].StrSex=TempItem.StrSex;
				ListItem[j+1].StrScore_English=TempItem.StrScore_English;
                	ListItem[j+1].StrScore_Math=TempItem.StrScore_Math;
						ListItem[j+1].StrScore_Chinese=TempItem.StrScore_Chinese;
				
				flag=0;
			}
		}
		if(flag==1)
			break;
	}
	for(i=0;i<num;i++)
	{
		m_ListControl.InsertItem(0,ListItem[i].StrID);
		m_ListControl.SetItemText(0,1,ListItem[i].StrName);
		m_ListControl.SetItemText(0,2,ListItem[i].StrSex);
		m_ListControl.SetItemText(0,3,ListItem[i].StrScore_English);
			m_ListControl.SetItemText(0,4,ListItem[i].StrScore_Math);
     	m_ListControl.SetItemText(0,5,ListItem[i].StrScore_Chinese);

	}
	
}

void CStudentDlg::OnMenuitemSortByMathN() 
{
		CString StrText1,StrText2;
    int num,i,flag,j;
	int score1,score2;
	num=0;
	i=0;
	while(m_ListControl.GetItemText(i,0)!="")
	{
		num++;
		i++;
	}
	struct StudentItem ListItem[100];

	for(i=0;i<num;i++)
	{
		ListItem[i].StrID=m_ListControl.GetItemText(i,0);
        ListItem[i].StrName=m_ListControl.GetItemText(i,1);
		ListItem[i].StrSex=m_ListControl.GetItemText(i,2);
		ListItem[i].StrScore_English=m_ListControl.GetItemText(i,3);
		ListItem[i].StrScore_Math=m_ListControl.GetItemText(i,4);
    	ListItem[i].StrScore_Chinese=m_ListControl.GetItemText(i,5);
	}

	for(i=num-1;i>=0;i--)
	{
	    	UpdateData(TRUE);
         m_ListControl.DeleteItem(i);
          UpdateData(FALSE);
	}

	for(i=0;i<num-1;i++)
	{
		flag=1;
		for(j=0;j<num-i-1;j++)
		{
			StrText1=ListItem[j].StrScore_Math;
			score1=_tcstoul(StrText1,NULL,10);
			StrText2=ListItem[j+1].StrScore_Math;
			score2=_tcstoul(StrText2,NULL,10);

			if(score1<score2)
			{
				struct StudentItem TempItem;

				TempItem.StrID=ListItem[j].StrID;
                TempItem.StrName=ListItem[j].StrName;
				TempItem.StrSex=ListItem[j].StrSex;
				TempItem.StrScore_English=ListItem[j].StrScore_English;
				TempItem.StrScore_Math=ListItem[j].StrScore_Math;
				TempItem.StrScore_Chinese=ListItem[j].StrScore_Chinese;

				ListItem[j].StrID=ListItem[j+1].StrID;
                ListItem[j].StrName=ListItem[j+1].StrName;
				ListItem[j].StrSex=ListItem[j+1].StrSex;
				ListItem[j].StrScore_English=ListItem[j+1].StrScore_English;
	            ListItem[j].StrScore_Math=ListItem[j+1].StrScore_Math;
				 ListItem[j].StrScore_Chinese=ListItem[j+1].StrScore_Chinese;

				ListItem[j+1].StrID=TempItem.StrID;
				ListItem[j+1].StrName=TempItem.StrName;
				ListItem[j+1].StrSex=TempItem.StrSex;
				ListItem[j+1].StrScore_English=TempItem.StrScore_English;
                	ListItem[j+1].StrScore_Math=TempItem.StrScore_Math;
						ListItem[j+1].StrScore_Chinese=TempItem.StrScore_Chinese;
				
				flag=0;
			}
		}
		if(flag==1)
			break;
	}
	for(i=0;i<num;i++)
	{
		m_ListControl.InsertItem(0,ListItem[i].StrID);
		m_ListControl.SetItemText(0,1,ListItem[i].StrName);
		m_ListControl.SetItemText(0,2,ListItem[i].StrSex);
		m_ListControl.SetItemText(0,3,ListItem[i].StrScore_English);
			m_ListControl.SetItemText(0,4,ListItem[i].StrScore_Math);
     	m_ListControl.SetItemText(0,5,ListItem[i].StrScore_Chinese);

	}
	
}

void CStudentDlg::OnMenuitemSortByMathR() 
{
	CString StrText1,StrText2;
    int num,i,flag,j;
	int score1,score2;
	num=0;
	i=0;
	while(m_ListControl.GetItemText(i,0)!="")
	{
		num++;
		i++;
	}
	struct StudentItem ListItem[100];

	for(i=0;i<num;i++)
	{
		ListItem[i].StrID=m_ListControl.GetItemText(i,0);
        ListItem[i].StrName=m_ListControl.GetItemText(i,1);
		ListItem[i].StrSex=m_ListControl.GetItemText(i,2);
		ListItem[i].StrScore_English=m_ListControl.GetItemText(i,3);
		ListItem[i].StrScore_Math=m_ListControl.GetItemText(i,4);
    	ListItem[i].StrScore_Chinese=m_ListControl.GetItemText(i,5);
	}

	for(i=num-1;i>=0;i--)
	{
	    	UpdateData(TRUE);
         m_ListControl.DeleteItem(i);
          UpdateData(FALSE);
	}

	for(i=0;i<num-1;i++)
	{
		flag=1;
		for(j=0;j<num-i-1;j++)
		{
			StrText1=ListItem[j].StrScore_Math;
			score1=_tcstoul(StrText1,NULL,10);
			StrText2=ListItem[j+1].StrScore_Math;
			score2=_tcstoul(StrText2,NULL,10);

			if(score1>score2)
			{
				struct StudentItem TempItem;

				TempItem.StrID=ListItem[j].StrID;
                TempItem.StrName=ListItem[j].StrName;
				TempItem.StrSex=ListItem[j].StrSex;
				TempItem.StrScore_English=ListItem[j].StrScore_English;
				TempItem.StrScore_Math=ListItem[j].StrScore_Math;
				TempItem.StrScore_Chinese=ListItem[j].StrScore_Chinese;

				ListItem[j].StrID=ListItem[j+1].StrID;
                ListItem[j].StrName=ListItem[j+1].StrName;
				ListItem[j].StrSex=ListItem[j+1].StrSex;
				ListItem[j].StrScore_English=ListItem[j+1].StrScore_English;
	            ListItem[j].StrScore_Math=ListItem[j+1].StrScore_Math;
				 ListItem[j].StrScore_Chinese=ListItem[j+1].StrScore_Chinese;

				ListItem[j+1].StrID=TempItem.StrID;
				ListItem[j+1].StrName=TempItem.StrName;
				ListItem[j+1].StrSex=TempItem.StrSex;
				ListItem[j+1].StrScore_English=TempItem.StrScore_English;
                	ListItem[j+1].StrScore_Math=TempItem.StrScore_Math;
						ListItem[j+1].StrScore_Chinese=TempItem.StrScore_Chinese;
				
				flag=0;
			}
		}
		if(flag==1)
			break;
	}
	for(i=0;i<num;i++)
	{
		m_ListControl.InsertItem(0,ListItem[i].StrID);
		m_ListControl.SetItemText(0,1,ListItem[i].StrName);
		m_ListControl.SetItemText(0,2,ListItem[i].StrSex);
		m_ListControl.SetItemText(0,3,ListItem[i].StrScore_English);
			m_ListControl.SetItemText(0,4,ListItem[i].StrScore_Math);
     	m_ListControl.SetItemText(0,5,ListItem[i].StrScore_Chinese);

	}
	
}

void CStudentDlg::OnButtonChange() 
{
    	int i=0,num=0,k=0;
	CString str;
	while(m_ListControl.GetItemText(i,0)!="")
	{
		i++;
		num++;
		
	}
	for(i=0;i<num;i++)
	{
		m_ID.GetWindowText(m_id);
		if(m_ListControl.GetItemText(i,0)==m_id)
		{
			the_StrID = m_ListControl.GetItemText(i,0);
            the_StrName = m_ListControl.GetItemText(i,1);
			the_StrSex = m_ListControl.GetItemText(i,2);	
			the_StrScore_English = m_ListControl.GetItemText(i,3);
			the_StrScore_Math = m_ListControl.GetItemText(i,4);
			the_StrScore_Chinese = m_ListControl.GetItemText(i,5);
			break;
		}
		else k++;
	}
	if(k==num){
		 MessageBox("该学生不存在！");
		 UpdateData(TRUE);
	     m_id="";
        	UpdateData(FALSE);
	}else{
			CChangeStudentDataDlg dialog;
     if (IDOK==dialog.DoModal())
	{
			int i=0,num=0;
	while(m_ListControl.GetItemText(i,0)!="")
	{
		i++;
		num++;
		
	}
	for(i=0;i<num;i++)
	{
		if(m_ListControl.GetItemText(i,0)==the_StrID)
		{
          m_ListControl.SetItemText(i,1,the_StrName);
		  m_ListControl.SetItemText(i,2,the_StrSex);	
	    	 m_ListControl.SetItemText(i,3,the_StrScore_English);
		  m_ListControl.SetItemText(i,4,the_StrScore_Math);
	  	 m_ListControl.SetItemText(i,5,the_StrScore_Chinese);
			break;
		}
	
	}
     	UpdateData(FALSE);  
	}
        
	}
	
}
