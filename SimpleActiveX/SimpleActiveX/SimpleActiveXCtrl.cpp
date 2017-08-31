// SimpleActiveXCtrl.cpp : Implementation of the CSimpleActiveXCtrl ActiveX Control class.

#include "stdafx.h"
#include "SimpleActiveX.h"
#include "SimpleActiveXCtrl.h"
#include "SimpleActiveXPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CSimpleActiveXCtrl, COleControl)

// Message map

BEGIN_MESSAGE_MAP(CSimpleActiveXCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// Dispatch map

BEGIN_DISPATCH_MAP(CSimpleActiveXCtrl, COleControl)
	DISP_PROPERTY_NOTIFY_ID(CSimpleActiveXCtrl, "InputParameter", dispidInputParameter, m_InputParameter, OnInputParameterChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY_ID(CSimpleActiveXCtrl, "OutputParameter", dispidOutputParameter, m_OutputParameter, OnOutputParameterChanged, VT_BSTR)
	DISP_FUNCTION_ID(CSimpleActiveXCtrl, "LoadParameter", dispidLoadParameter, LoadParameter, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// Event map

BEGIN_EVENT_MAP(CSimpleActiveXCtrl, COleControl)
	EVENT_CUSTOM_ID("ParameterLoaded", eventidParameterLoaded, FireParameterLoaded, VTS_NONE)
END_EVENT_MAP()

// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CSimpleActiveXCtrl, 1)
	PROPPAGEID(CSimpleActiveXPropPage::guid)
END_PROPPAGEIDS(CSimpleActiveXCtrl)

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CSimpleActiveXCtrl, "SIMPLEACTIVEX.SimpleActiveXCtrl.1",
	0x24695d2d, 0xc9c, 0x460b, 0x84, 0xd6, 0x41, 0xc3, 0x95, 0x7, 0xdf, 0xdd)

// Type library ID and version

IMPLEMENT_OLETYPELIB(CSimpleActiveXCtrl, _tlid, _wVerMajor, _wVerMinor)

// Interface IDs

const IID IID_DSimpleActiveX = { 0xD8651415, 0xCAA2, 0x4169, { 0xAF, 0x97, 0x36, 0x2C, 0xF6, 0xF0, 0x78, 0xB4 } };
const IID IID_DSimpleActiveXEvents = { 0xDE3ADEF6, 0xCDC7, 0x45CA, { 0x9B, 0x13, 0x64, 0xEA, 0x56, 0x49, 0xD8, 0x34 } };

// Control type information

static const DWORD _dwSimpleActiveXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CSimpleActiveXCtrl, IDS_SIMPLEACTIVEX, _dwSimpleActiveXOleMisc)

// CSimpleActiveXCtrl::CSimpleActiveXCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CSimpleActiveXCtrl

BOOL CSimpleActiveXCtrl::CSimpleActiveXCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_SIMPLEACTIVEX,
			IDB_SIMPLEACTIVEX,
			afxRegApartmentThreading,
			_dwSimpleActiveXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CSimpleActiveXCtrl::CSimpleActiveXCtrl - Constructor

CSimpleActiveXCtrl::CSimpleActiveXCtrl()
{
	InitializeIIDs(&IID_DSimpleActiveX, &IID_DSimpleActiveXEvents);
	// TODO: Initialize your control's instance data here.
}

// CSimpleActiveXCtrl::~CSimpleActiveXCtrl - Destructor

CSimpleActiveXCtrl::~CSimpleActiveXCtrl()
{
	// TODO: Cleanup your control's instance data here.
}

// CSimpleActiveXCtrl::OnDraw - Drawing function

void CSimpleActiveXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CSimpleActiveXCtrl::DoPropExchange - Persistence support

void CSimpleActiveXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}


// CSimpleActiveXCtrl::OnResetState - Reset control to default state

void CSimpleActiveXCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


// CSimpleActiveXCtrl message handlers


void CSimpleActiveXCtrl::OnInputParameterChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your property handler code here

	SetModifiedFlag();
}


void CSimpleActiveXCtrl::OnOutputParameterChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your property handler code here

	SetModifiedFlag();
}


void CSimpleActiveXCtrl::LoadParameter(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your dispatch handler code here
	m_OutputParameter = m_InputParameter;
	FireParameterLoaded();
}
