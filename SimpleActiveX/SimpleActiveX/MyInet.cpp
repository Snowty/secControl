// MyInet.cpp : implementation file
//

#include "stdafx.h"
#include "SimpleActiveX.h"
#include "MyInet.h"


// MyInet

MyInet::MyInet(LPCTSTR pstrAgent /*= NULL*/,
		DWORD dwContext /*= 1*/,
		DWORD dwAccessType /*= PRE_CONFIG_INTERNET_ACCESS*/,
		LPCTSTR pstrProxyName /*= NULL*/,
		LPCTSTR pstrProxyBypass /*= NULL*/,
		DWORD dwFlags /*= 0*/)
		: CInternetSession (pstrAgent, dwContext, dwAccessType, pstrProxyName, 
							pstrProxyBypass, dwFlags)
							, m_strRequest(_T(""))
							, m_strServerName(_T(""))
							, m_strObjectName(_T(""))
							, m_strHtml(_T(""))
{
}

MyInet::~MyInet()
{
}


// MyInet member functions


void MyInet::PostBack(void)
{
	CInternetSession m_InetSession;
	CHttpConnection *pServer = NULL;
	CHttpFile* pFile = NULL;
	try{
		INTERNET_PORT nPort;
		nPort = 80;
		pServer = m_InetSession.GetHttpConnection(m_strServerName,nPort);
		pFile = pServer->OpenRequest(CHttpConnection::HTTP_VERB_POST,m_strObjectName);
		char szHeaders[100];
		strcpy_s(szHeaders,"Accept: text*/*/rContent-Type: application/x-www/form-urlencoded");
		pFile->AddRequestHeaders((LPCTSTR)szHeaders);

		pFile->SendRequestEx(m_strRequest.GetLength());
		pFile->WriteString(m_strRequest);
		pFile->EndRequest();
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
