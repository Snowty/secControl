// SimpleActiveXCtrl.cpp : Implementation of the CSimpleActiveXCtrl ActiveX Control class.

#include "stdafx.h"
#include "SimpleActiveX.h"
#include "SimpleActiveXCtrl.h"
#include "SimpleActiveXPropPage.h"
#include "afxdialogex.h"
#include "afxinet.h"

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
	DISP_FUNCTION_ID(CSimpleActiveXCtrl, "PostData", dispidPostData, PostData, VT_EMPTY, VTS_NONE)
	DISP_PROPERTY_NOTIFY_ID(CSimpleActiveXCtrl, "strServerName", dispidstrServerName, m_strServerName, OnstrServerNameChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY_ID(CSimpleActiveXCtrl, "strObjectName", dispidstrObjectName, m_strObjectName, OnstrObjectNameChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY_ID(CSimpleActiveXCtrl, "strRequest", dispidstrRequest, m_strRequest, OnstrRequestChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY_ID(CSimpleActiveXCtrl, "strHtml", dispidstrHtml, m_strHtml, OnstrHtmlChanged, VT_BSTR)
END_DISPATCH_MAP()

// Event map

BEGIN_EVENT_MAP(CSimpleActiveXCtrl, COleControl)
	EVENT_CUSTOM_ID("ParameterLoaded", eventidParameterLoaded, FireParameterLoaded, VTS_NONE)
	EVENT_CUSTOM_ID("DataPosted", eventidDataPosted, FireDataPosted, VTS_NONE)
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
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	//pdc->Ellipse(rcBounds);
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


void CSimpleActiveXCtrl::OnstrObjectNameChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your property handler code here

	SetModifiedFlag();
}

void CSimpleActiveXCtrl::OnstrServerNameChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your property handler code here

	SetModifiedFlag();
}


void CSimpleActiveXCtrl::OnstrRequestChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your property handler code here

	SetModifiedFlag();
}


void CSimpleActiveXCtrl::OnstrHtmlChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your property handler code here

	SetModifiedFlag();
}

void CSimpleActiveXCtrl::PostData(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your dispatch handler code here
	CInternetSession m_InetSession;  //初始化一个或多个Internet会话
	CHttpConnection *pServer = NULL;	//管理应用程序域服务器建立的连接
	CHttpFile* pFile = NULL;	//查找和获取HTTP服务器上的文件功能
	
	m_strServerName = "123.206.22.33";
	m_strObjectName = "p";
	m_strRequest = "username=hhh&hostname=127.0.0.1&ip=127.0.0.1&package=123&language=123&time=123&submit=Submit";

	try{
		INTERNET_PORT nPort;
		nPort = 5000;
		pServer = m_InetSession.GetHttpConnection(m_strServerName,nPort);
		pFile = pServer->OpenRequest(CHttpConnection::HTTP_VERB_POST,m_strObjectName);
		
		pFile->AddRequestHeaders(_T("User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko)"));
		pFile->AddRequestHeaders(_T("Content-Type: application/x-www-form-urlencoded"));
		pFile->AddRequestHeaders(_T("Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8"));
		pFile->AddRequestHeaders(_T("Accept-Encoding: gzip, deflate"));
		pFile->AddRequestHeaders(_T("Accept-Language: zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3"));
		

		USES_CONVERSION;
		#ifdef _UNICODE  
			pFile->SendRequest(NULL,0,W2A(m_strRequest),m_strRequest.GetLength());  
		#else 
			pFile->SendRequest(NULL,0,(LPVOID)(LPCTSTR)m_strRequest,m_strRequest.GetLength());  
		#endif


		DWORD dwRet;
		pFile->QueryInfoStatusCode(dwRet);
		CString str;

		//m_Mutex.Lock();
		m_strHtml="";
		char szBuff[1024];

		if(dwRet == HTTP_STATUS_OK)
		{
			UINT nRead;
			while((nRead = pFile->Read(szBuff,1023))>0)
			{
				m_strHtml += CString(szBuff,nRead);
			}
		}
		//m_Mutex.Unlock();

		delete pFile;
		delete pServer;
	}
	catch(CInternetException *e){
		CString s;
		s.Format(_T("Internet Exception/r/nm_dwError%u,m_dwContextError%u"),e->m_dwError,e->m_dwContext);
		AfxMessageBox(s);
	}

}