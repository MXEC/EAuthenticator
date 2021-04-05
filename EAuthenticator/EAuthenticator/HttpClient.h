#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <afxinet.h>
#include <string>
using namespace std;

#define  IE_AGENT  "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.2; WOW64; Trident/7.0; .NET4.0C; .NET4.0E; Tablet PC 2.0; .NET CLR 2.0.50727; .NET CLR 3.0.30729; .NET CLR 3.5.30729)"

// �����ɹ�
#define SUCCESS        0
// ����ʧ��
#define FAILURE        1
// ������ʱ www.it165.net
#define OUTTIME        2

class CHttpClient
{
public:
    CHttpClient(LPCTSTR strAgent = IE_AGENT);
    virtual ~CHttpClient(void);

    int HttpGet(LPCTSTR strUrl, LPCTSTR strPostData, CString& strResponse);
    int HttpPost(LPCTSTR strUrl, LPCTSTR strPostData, CString& strResponse);

private:
    int ExecuteRequest(LPCTSTR strMethod, LPCTSTR strUrl, LPCTSTR strPostData, CString& strResponse);
    void Clear();

private:
    CInternetSession* m_pSession;
    CHttpConnection* m_pConnection;
    CHttpFile* m_pFile;
};

#endif // HTTPCLIENT_H