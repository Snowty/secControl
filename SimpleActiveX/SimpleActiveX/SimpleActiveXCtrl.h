#pragma once

// SimpleActiveXCtrl.h : Declaration of the CSimpleActiveXCtrl ActiveX Control class.


// CSimpleActiveXCtrl : See SimpleActiveXCtrl.cpp for implementation.

class CSimpleActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CSimpleActiveXCtrl)

// Constructor
public:
	CSimpleActiveXCtrl();

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Implementation
protected:
	~CSimpleActiveXCtrl();

	DECLARE_OLECREATE_EX(CSimpleActiveXCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CSimpleActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CSimpleActiveXCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CSimpleActiveXCtrl)		// Type name and misc status

// Message maps
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	DECLARE_DISPATCH_MAP()

// Event maps
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
		eventidDataPosted = 2L,
		dispidstrHtml = 8,
		dispidstrRequest = 7,
		dispidstrObjectName = 6,
		dispidstrServerName = 5,
		dispidPostData = 4L,
		eventidParameterLoaded = 1L,
		dispidLoadParameter = 3L,
		dispidOutputParameter = 2,
		dispidInputParameter = 1
	};
protected:
	void OnInputParameterChanged(void);
	CString m_InputParameter;
	void OnOutputParameterChanged(void);
	CString m_OutputParameter;
	void LoadParameter(void);

	void FireParameterLoaded(void)
	{
		FireEvent(eventidParameterLoaded, EVENT_PARAM(VTS_NONE));
	}
	void PostData(void);
	void OnstrServerNameChanged(void);
	CString m_strServerName;
	void OnstrObjectNameChanged(void);
	CString m_strObjectName;
	void OnstrRequestChanged(void);
	CString m_strRequest;
	void OnstrHtmlChanged(void);
	CString m_strHtml;

	void FireDataPosted(void)
	{
		FireEvent(eventidDataPosted, EVENT_PARAM(VTS_NONE));
	}
};

