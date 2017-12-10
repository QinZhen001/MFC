; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CStudentDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "student.h"

ClassCount=5
Class1=CStudentApp
Class2=CStudentDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDD_DIALOG_GRAPH
Resource3=IDD_DIALOG_CHANGE_ITEM
Class4=CStudentScoreGraphDialog
Resource4=IDD_STUDENT_DIALOG
Class5=CChangeStudentDataDlg
Resource5=IDR_MENU

[CLS:CStudentApp]
Type=0
HeaderFile=student.h
ImplementationFile=student.cpp
Filter=N

[CLS:CStudentDlg]
Type=0
HeaderFile=studentDlg.h
ImplementationFile=studentDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BUTTON_ADD

[CLS:CAboutDlg]
Type=0
HeaderFile=studentDlg.h
ImplementationFile=studentDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_STUDENT_DIALOG]
Type=1
Class=CStudentDlg
ControlCount=21
Control1=IDC_STATIC,button,1342193671
Control2=IDC_LIST,SysListView32,1350631429
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_ID,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_NAME,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC_ENGLISH,static,1342308352
Control9=IDC_EDIT_SCORE,edit,1350631552
Control10=IDC_BUTTON_ADD,button,1342242816
Control11=IDC_BUTTON_DELETE,button,1342242816
Control12=IDC_BUTTON_SEARCH,button,1342242816
Control13=IDC_RADIO_M,button,1342308361
Control14=IDC_RADIO_F,button,1342177289
Control15=IDC_STATIC,button,1342178055
Control16=IDC_BUTTON_SEARCH2,button,1342242816
Control17=IDC_STATIC_ENGLISH2,static,1342308352
Control18=IDC_EDIT_SCORE_CHINESE,edit,1350631552
Control19=IDC_STATIC_ENGLISH3,static,1342308352
Control20=IDC_EDIT_SCORE_MATH,edit,1350631552
Control21=IDC_BUTTON_CHANGE,button,1342242816

[MNU:IDR_MENU]
Type=1
Class=CStudentDlg
Command1=ID_MENUITEM_DISPALY
Command2=ID_MENUITEM_LEAD_IN
Command3=ID_MENUITEM_SORT_BY_ID_N
Command4=ID_MENUITEM_SORT_BY_ID_R
Command5=ID_MENUITEM_SORT_BY_ENGLISH_N
Command6=ID_MENUITEM_SORT_BY_ENGLISH_R
Command7=ID_MENUITEM_SORT_BY_MATH_N
Command8=ID_MENUITEM_SORT_BY_MATH_R
Command9=ID_MENUITEM_SORT_BY_CHINESE_N
Command10=ID_MENUITEM_SORT_BY_CHINESE_R
Command11=ID_MENUITEM_EXIT
CommandCount=11

[ACL:IDR_MENU]
Type=1
Class=CStudentDlg
Command1=ID_MENUITEM_SORT
Command2=ID_MENUITEM_DISPALY
CommandCount=2

[CLS:CStudentScoreGraphDialog]
Type=0
HeaderFile=StudentScoreGraphDialog.h
ImplementationFile=StudentScoreGraphDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CStudentScoreGraphDialog
VirtualFilter=dWC

[DLG:IDD_DIALOG_GRAPH]
Type=1
Class=CStudentScoreGraphDialog
ControlCount=1
Control1=ID_CANCEL,button,1342242816

[DLG:IDD_DIALOG_CHANGE_ITEM]
Type=1
Class=CChangeStudentDataDlg
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC_ID,static,1342308352
Control4=IDC_EDIT_SCORE,edit,1350631552
Control5=IDC_STATIC_ENGLISH2,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_NAME,edit,1350631552
Control8=IDC_STATIC_ENGLISH3,static,1342308352
Control9=IDC_EDIT_SCORE_MATH,edit,1350631552
Control10=IDC_STATIC_ENGLISH,static,1342308352
Control11=IDC_EDIT_SCORE_CHINESE,edit,1350631552

[CLS:CChangeStudentDataDlg]
Type=0
HeaderFile=ChangeStudentDataDlg.h
ImplementationFile=ChangeStudentDataDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT_NAME

