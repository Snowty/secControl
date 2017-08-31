// SimpleActiveX.cpp : Implementation of CSimpleActiveXApp and DLL registration.

#include "stdafx.h"
#include "SimpleActiveX.h"
#include "comcat.h"
#include "strsafe.h"
#include "objsafe.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


const CATID CLSID_SafeItem = 
{0x24695d2d, 0xc9c, 0x460b, {0x84, 0xd6, 0x41, 0xc3, 0x95, 0x7, 0xdf, 0xdd}};

CSimpleActiveXApp theApp;

const GUID CDECL _tlid = { 0x818DFE54, 0xE590, 0x40B0, { 0xBD, 0x8A, 0x96, 0x90, 0x49, 0xC6, 0x6A, 0x7C } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CSimpleActiveXApp::InitInstance - DLL initialization

BOOL CSimpleActiveXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CSimpleActiveXApp::ExitInstance - DLL termination

int CSimpleActiveXApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}

//HRESULT CreateComponentCategory - Used to register ActiveX control as safe
HRESULT CreateComponentCategory(CATID catid, WCHAR *catDescription)
{
	ICatRegister *pcr = NULL;
	HRESULT hr = S_OK;

	hr = CoCreateInstance(CLSID_StdComponentCategoriesMgr,
		NULL,CLSCTX_INPROC_SERVER,IID_ICatRegister,(void **)&pcr);

	if(FAILED(hr))
		return hr;

	//Make sure the HKCR\Component Categoried\{..catid..} key is registered
	CATEGORYINFO catinfo;
	catinfo.catid = catid;
	catinfo.lcid = 0x0409; //english
	size_t len;

	hr = StringCchLength(catDescription,STRSAFE_MAX_CCH,&len);
	if(SUCCEEDED(hr))
	{
		if(len>127)
		{
			len=127;
		}
	}
	else
	{
		//TODO:Write an error handler;
	}
	//The second parameter of StringCchCopy is 128 because you need room for a NULL-terminator
	hr = StringCchCopy(catinfo.szDescription,len+1,catDescription);
	//Make sure the description is null terminated
	catinfo.szDescription[len+1] = '\0';

	hr = pcr->RegisterCategories(1,&catinfo);
	pcr->Release();

	return hr;


}

//HRESULT RegisterCLSIDInCategory Register your component categoried information
HRESULT RegisterCLSIDInCategory(REFCLSID clsid,CATID catid)
{
	ICatRegister *pcr = NULL;
	HRESULT hr = S_OK;
	hr = CoCreateInstance(CLSID_StdComponentCategoriesMgr,
		NULL,CLSCTX_INPROC_SERVER,IID_ICatRegister,(void **)&pcr);
	if(SUCCEEDED(hr))
	{
		CATID rgcatid[1];
		rgcatid[0] = catid;
		hr = pcr->RegisterClassImplCategories(clsid,1,rgcatid);
	}
	if(pcr!=NULL)
		pcr->Release();
	return hr;
}

HRESULT UnRegisterCLSIDInCategory(REFCLSID clsid,CATID catid)
{
	ICatRegister *pcr = NULL;
	HRESULT hr = S_OK;

	hr = CoCreateInstance(CLSID_StdComponentCategoriesMgr,
		NULL,CLSCTX_INPROC_SERVER,IID_ICatRegister,(void**)&pcr);
	if(SUCCEEDED(hr))
	{
		CATID rgcatid[1];
		rgcatid[0] = catid;
		hr = pcr->UnRegisterClassImplCategories(clsid,1,rgcatid);
	}
	if(pcr!=NULL)
		pcr->Release();

	return hr;
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	HRESULT hr;
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);
	//Mark the control as safe for initializing
	hr = CreateComponentCategory(CATID_SafeForInitializing,
		L"Controls safely initializable from persistent data!");
	if(FAILED(hr))
		return hr;

	//Mark the control as safe for scripting.
	hr = CreateComponentCategory(CATID_SafeForScripting,
		L"Controls safely scriptable");
	if(FAILED(hr))
		return hr;

	hr = RegisterCLSIDInCategory(CLSID_SafeItem,CATID_SafeForScripting);
	if(FAILED(hr))
		return hr;

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}