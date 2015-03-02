#if !defined(AFX_STORAGECTL_H__E3181810_85E4_40F1_B76D_A6DB3C4794B0__INCLUDED_)
#define AFX_STORAGECTL_H__E3181810_85E4_40F1_B76D_A6DB3C4794B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// StorageCtl.h : Declaration of the CStorageCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CStorageCtrl : See StorageCtl.cpp for implementation.

class CStorageCtrl : public COleControl
{
	DECLARE_DYNCREATE(CStorageCtrl)

// Constructor
public:
	CStorageCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStorageCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CStorageCtrl();

	DECLARE_OLECREATE_EX(CStorageCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CStorageCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CStorageCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CStorageCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CStorageCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CStorageCtrl)
	afx_msg BSTR Get(LPCTSTR key);
	afx_msg BSTR Set(LPCTSTR key, LPCTSTR value);
	afx_msg BSTR Clear();
	afx_msg BSTR Plus(LPCTSTR key);
	afx_msg BSTR Insert(LPCTSTR key, LPCTSTR value);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CStorageCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CStorageCtrl)
	dispidGet = 1L,
	dispidSet = 2L,
	dispidClear = 3L,
	dispidPlus = 4L,
	dispidInsert = 5L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STORAGECTL_H__E3181810_85E4_40F1_B76D_A6DB3C4794B0__INCLUDED)
