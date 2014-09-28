#if !defined(AFX_STORAGE_H__B46845A9_EFD0_4A3A_A55E_2DD1C0ED6F43__INCLUDED_)
#define AFX_STORAGE_H__B46845A9_EFD0_4A3A_A55E_2DD1C0ED6F43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Storage.h : main header file for STORAGE.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStorageApp : See Storage.cpp for implementation.

class CStorageApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STORAGE_H__B46845A9_EFD0_4A3A_A55E_2DD1C0ED6F43__INCLUDED)
