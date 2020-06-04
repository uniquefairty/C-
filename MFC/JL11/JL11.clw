; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CJL11Dlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "JL11.h"

ClassCount=3
Class1=CJL11App
Class2=CJL11Dlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDR_MENU1
Resource2=IDR_MAINFRAME
Resource3=IDD_JL11_DIALOG
Resource4=IDD_ABOUTBOX
Resource5=IDR_QUICKMENU
Resource6=IDR_TOOLBAR1

[CLS:CJL11App]
Type=0
HeaderFile=JL11.h
ImplementationFile=JL11.cpp
Filter=N
LastObject=ID_ABOUT

[CLS:CJL11Dlg]
Type=0
HeaderFile=JL11Dlg.h
ImplementationFile=JL11Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_QUICK_WHITE

[CLS:CAboutDlg]
Type=0
HeaderFile=JL11Dlg.h
ImplementationFile=JL11Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_JL11_DIALOG]
Type=1
Class=CJL11Dlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552

[MNU:IDR_MENU1]
Type=1
Class=CJL11Dlg
Command1=ID_FILE_EXIT
Command2=ID_MESS_TEXT
Command3=ID_MESS_ELLIPSE
Command4=ID_ABOUT
CommandCount=4

[MNU:IDR_QUICKMENU]
Type=1
Class=CJL11Dlg
Command1=ID_QUICK_SHOW
Command2=ID_QUICK_HIDE
Command3=ID_QUICK_RED
Command4=ID_QUICK_BLUE
Command5=ID_QUICK_WHITE
CommandCount=5

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=ID_MESS_TEXT
Command2=ID_MESS_ELLIPSE
Command3=ID_ABOUT
CommandCount=3

