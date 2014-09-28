// StoragePpg.cpp : Implementation of the CStoragePropPage property page class.

#include "stdafx.h"
#include "Storage.h"
#include "StoragePpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CStoragePropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CStoragePropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CStoragePropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CStoragePropPage, "STORAGE.StoragePropPage.1",
	0xfbf1b104, 0xd3b9, 0x4d00, 0x96, 0x19, 0xc6, 0x39, 0x11, 0xc9, 0x76, 0x35)


/////////////////////////////////////////////////////////////////////////////
// CStoragePropPage::CStoragePropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CStoragePropPage

BOOL CStoragePropPage::CStoragePropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_STORAGE_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CStoragePropPage::CStoragePropPage - Constructor

CStoragePropPage::CStoragePropPage() :
	COlePropertyPage(IDD, IDS_STORAGE_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CStoragePropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CStoragePropPage::DoDataExchange - Moves data between page and properties

void CStoragePropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CStoragePropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CStoragePropPage message handlers
