// SimpleActiveXPropPage.cpp : Implementation of the CSimpleActiveXPropPage property page class.

#include "stdafx.h"
#include "SimpleActiveX.h"
#include "SimpleActiveXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CSimpleActiveXPropPage, COlePropertyPage)

// Message map

BEGIN_MESSAGE_MAP(CSimpleActiveXPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CSimpleActiveXPropPage, "SIMPLEACTIVEX.SimpleActiveXPropPage.1",
	0x25e63230, 0x776b, 0x42e3, 0xb8, 0x6c, 0x6e, 0x4f, 0x7d, 0x9f, 0x81, 0x75)

// CSimpleActiveXPropPage::CSimpleActiveXPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CSimpleActiveXPropPage

BOOL CSimpleActiveXPropPage::CSimpleActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_SIMPLEACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CSimpleActiveXPropPage::CSimpleActiveXPropPage - Constructor

CSimpleActiveXPropPage::CSimpleActiveXPropPage() :
	COlePropertyPage(IDD, IDS_SIMPLEACTIVEX_PPG_CAPTION)
{
}

// CSimpleActiveXPropPage::DoDataExchange - Moves data between page and properties

void CSimpleActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CSimpleActiveXPropPage message handlers
