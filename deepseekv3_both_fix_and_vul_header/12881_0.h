#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RTSP_PARAM_STRING_MAX 256
#define RTSP_BUFFER_SIZE 2048

enum RTSP_CMD_TYPES {
    RTSP_OPTIONS,
    RTSP_DESCRIBE,
    RTSP_SETUP,
    RTSP_PLAY,
    RTSP_TEARDOWN
};

class CRtspSession {
public:
    bool ParseRtspRequest(char const * aRequest, unsigned aRequestSize);
    
private:
    void Init();
    
    char CmdName[RTSP_PARAM_STRING_MAX];
    char CurRequest[RTSP_BUFFER_SIZE];
    unsigned m_ClientRTPPort;
    unsigned m_ClientRTCPPort;
    RTSP_CMD_TYPES m_RtspCmdType;
    bool m_TcpTransport;
    char m_URLHostPort[RTSP_PARAM_STRING_MAX];
    char m_URLSuffix[RTSP_PARAM_STRING_MAX];
    char m_URLPreSuffix[RTSP_PARAM_STRING_MAX];
    char m_CSeq[RTSP_PARAM_STRING_MAX];
    unsigned m_ContentLength;
};

void CRtspSession::Init() {
    memset(CmdName, 0, sizeof(CmdName));
    memset(CurRequest, 0, sizeof(CurRequest));
    m_ClientRTPPort = 0;
    m_ClientRTCPPort = 0;
    m_RtspCmdType = RTSP_OPTIONS;
    m_TcpTransport = false;
    memset(m_URLHostPort, 0, sizeof(m_URLHostPort));
    memset(m_URLSuffix, 0, sizeof(m_URLSuffix));
    memset(m_URLPreSuffix, 0, sizeof(m_URLPreSuffix));
    memset(m_CSeq, 0, sizeof(m_CSeq));
    m_ContentLength = 0;
}