#pragma once
#include "afxinet.h"

// MyInet command target

class MyInet : public CInternetSession
{
public:
	MyInet(LPCTSTR pstrAgent = NULL,
		DWORD dwContext = 1,
		DWORD dwAccessType = PRE_CONFIG_INTERNET_ACCESS,
		LPCTSTR pstrProxyName = NULL,
		LPCTSTR pstrProxyBypass = NULL,
		DWORD dwFlags = 0);
	virtual ~MyInet();
	void PostBack(void);
private:
	CString m_strRequest;
	CString m_strServerName;
	CString m_strObjectName;
	CString m_strHtml;
};


