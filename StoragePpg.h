#if !defined(AFX_STORAGEPPG_H__44E8AE6F_007C_4525_A8AA_2C55FF529223__INCLUDED_)
#define AFX_STORAGEPPG_H__44E8AE6F_007C_4525_A8AA_2C55FF529223__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// StoragePpg.h : Declaration of the CStoragePropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CStoragePropPage : See StoragePpg.cpp.cpp for implementation.

class CStoragePropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CStoragePropPage)
	DECLARE_OLECREATE_EX(CStoragePropPage)

// Constructor
public:
	CStoragePropPage();

// Dialog Data
	//{{AFX_DATA(CStoragePropPage)
	enum { IDD = IDD_PROPPAGE_STORAGE };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CStoragePropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STORAGEPPG_H__44E8AE6F_007C_4525_A8AA_2C55FF529223__INCLUDED)
