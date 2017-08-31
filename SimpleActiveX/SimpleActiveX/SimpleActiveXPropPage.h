#pragma once

// SimpleActiveXPropPage.h : Declaration of the CSimpleActiveXPropPage property page class.


// CSimpleActiveXPropPage : See SimpleActiveXPropPage.cpp for implementation.

class CSimpleActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CSimpleActiveXPropPage)
	DECLARE_OLECREATE_EX(CSimpleActiveXPropPage)

// Constructor
public:
	CSimpleActiveXPropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_SIMPLEACTIVEX };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};

