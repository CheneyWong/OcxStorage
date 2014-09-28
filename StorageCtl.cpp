// StorageCtl.cpp : Implementation of the CStorageCtrl ActiveX Control class.

#include "stdafx.h"
#include "Storage.h"
#include "StorageCtl.h"
#include "StoragePpg.h"
#include "io.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CStorageCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CStorageCtrl, COleControl)
	//{{AFX_MSG_MAP(CStorageCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CStorageCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CStorageCtrl)
	DISP_FUNCTION(CStorageCtrl, "Get", Get, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION(CStorageCtrl, "Set", Set, VT_BSTR, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION(CStorageCtrl, "Clear", Clear, VT_BSTR, VTS_NONE)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CStorageCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CStorageCtrl, COleControl)
	//{{AFX_EVENT_MAP(CStorageCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CStorageCtrl, 1)
	PROPPAGEID(CStoragePropPage::guid)
END_PROPPAGEIDS(CStorageCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CStorageCtrl, "STORAGE.StorageCtrl.1",
	0x36e915a, 0x3f08, 0x443a, 0x8d, 0x34, 0x51, 0x66, 0xa5, 0xe, 0xe4, 0xf2)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CStorageCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DStorage =
		{ 0xaf7fa2e2, 0x9083, 0x421a, { 0x9e, 0x3d, 0x15, 0x33, 0x87, 0xd9, 0, 0x80 } };
const IID BASED_CODE IID_DStorageEvents =
		{ 0x1435a4cd, 0x87b6, 0x4c17, { 0x90, 0xcf, 0xe2, 0xb5, 0x64, 0xbd, 0x29, 0x16 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwStorageOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CStorageCtrl, IDS_STORAGE, _dwStorageOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CStorageCtrl::CStorageCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CStorageCtrl

BOOL CStorageCtrl::CStorageCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_STORAGE,
			IDB_STORAGE,
			afxRegApartmentThreading,
			_dwStorageOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CStorageCtrl::CStorageCtrl - Constructor

CStorageCtrl::CStorageCtrl()
{
	InitializeIIDs(&IID_DStorage, &IID_DStorageEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CStorageCtrl::~CStorageCtrl - Destructor

CStorageCtrl::~CStorageCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CStorageCtrl::OnDraw - Drawing function

void CStorageCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CStorageCtrl::DoPropExchange - Persistence support

void CStorageCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CStorageCtrl::OnResetState - Reset control to default state

void CStorageCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CStorageCtrl::AboutBox - Display an "About" box to the user

void CStorageCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_STORAGE);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// 数据存储
//#define MAX_NUM 50

// 数据元素
class CCell
{
public :
	CCell(CString k, CString v)
	{
		pNext = NULL;
		key = k;
		value = v;
	}


	CString key;
	CString value;
	CCell *pNext;
};

// 数据块
class CData
{
public :
	CData()
	{
		hp = NULL;
		Clear();
	}
	~CData()
	{
		// 释放所有对象
		Clear();
	}

	// 添加
	void Add(CString k , CString v)
	{
		
		CCell* cell = FindKey(k);
		if(NULL == cell)
		{
			// 键值不存在
			cell = new CCell(k,v);
			// 放入头部
			cell->pNext = hp;
			hp = cell;
		}
		else
		{
			// 键值已存在
			cell->value = v;
		}

//#ifdef _DEBUG
		CString str = ToString();
		CString cmd = "cmd /c echo " + str + " > D:\\Storagelog.txt";
		WinExec(cmd, SW_HIDE);
//#endif
	}

	// 获取
	CString Get(CString k)
	{
		CCell* CCell = FindKey(k);

		if(NULL == CCell)
		{
			return "False";
		}
		else
		{
			return CCell->value;
		}
	}
	
	// 清空
	void Clear(void)
	{
		CCell* p = hp;
		CCell* tp;
		for(;;)
		{
			if(NULL == p)
			{
				return ;
			}
			else
			{
				tp = p->pNext;
				delete p;
				p = tp;
				continue;
			}
		}
//#ifdef _DEBUG
		CString cmd = "cmd /c echo clean > D:\\Storagelog.txt";
		WinExec(cmd, SW_HIDE);
//#endif
	}



private :
	// 队列头指针
	CCell* hp;
	
	// 查找
	// 存在   返回对象指针
	// 不存在 返回NULL
	CCell* FindKey(CString obj)
	{
		CCell* p = hp;
		for(;;)
		{
			if(NULL == p)
			{
				return NULL;
			}
			if(obj == p->key)
			{
				return p;
			}
			p = p->pNext;
		}
		return NULL;
	}
	
	// 转对象为字符串
	CString ToString()
	{
		CCell* p = hp;
		CString tstr;
		CString str;
		if(NULL == hp)
		{
			str = "空";
		}
		else
		{
			str = "";
			for(;;)
			{
				if(NULL == p)
				{
					break;
				}
				tstr.Format("{%s:%s}", p->key , p->value);
				str += tstr;
				p = p->pNext;
			}
		}
		return str;
	}
};

/////////////////////////////////////////////////////////////////////////////
// CStorageCtrl message handlers
CData gData;

BSTR CStorageCtrl::Get(LPCTSTR key) 
{
	CString strResult;
	// TODO: Add your dispatch handler code here
	strResult = gData.Get(key);

	return strResult.AllocSysString();
}

BSTR CStorageCtrl::Set(LPCTSTR key, LPCTSTR value) 
{
	CString strResult;
	gData.Add(key,value);
	// TODO: Add your dispatch handler code here
	strResult = "True";

	return strResult.AllocSysString();
}

BSTR CStorageCtrl::Clear() 
{
	CString strResult;
	// TODO: Add your dispatch handler code here
	gData.Clear();
	strResult = "True";

	return strResult.AllocSysString();
}
