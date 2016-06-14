
// Tablet.h : main header file for the Tablet application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTabletApp:
// See Tablet.cpp for the implementation of this class
//

class CTabletApp : public CWinAppEx
{
public:
	CTabletApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTabletApp theApp;
