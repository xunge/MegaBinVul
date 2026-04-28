#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

typedef int64_t int64;
typedef uint64_t uint64;
typedef int32_t SteamNetworkingMicroseconds;
typedef unsigned char byte;

#define k_EResultLimitExceeded 1
#define k_EResultIgnored 2
#define k_cbMaxUnreliableMsgSize 1200
#define k_cbMaxUnreliableMsgSizeSend 1200
#define k_nSteamNetworkingSend_Reliable 0x1
#define k_nSteamNetworkingSend_NoDelay 0x2
#define k_nSteamNetworkingSend_NoNagle 0x4
#define k_nSteamNetworkingSend_UseCurrentThread 0x8
#define k_ESteamNetworkingConnectionState_Connected 3

#define Assert assert

struct CSteamNetworkingMessage {
    int m_cbSize;
    int m_nFlags;
    int64 m_nMessageNumber;
    int m_cbSNPSendReliableHeader;
    void Release();
    void SNPSend_SetReliableStreamPos(int64 pos);
    byte* SNPSend_ReliableHeader();
    bool SNPSend_IsReliable();
    void SNPSend_SetUsecNagle(SteamNetworkingMicroseconds usec);
    SteamNetworkingMicroseconds SNPSend_UsecNagle();
};

struct SenderState {
    int PendingBytesTotal();
    int m_nLastSentMsgNum;
    int64 m_nReliableStreamPos;
    int64 m_nLastSendMsgNumReliable;
    int m_nMessagesSentReliable;
    int m_cbPendingReliable;
    int m_nMessagesSentUnreliable;
    int m_cbPendingUnreliable;
    void ClearNagleTimers();
    double CalcTimeUntilNextSend();
    int m_n_x;
    struct MessageQueue {
        CSteamNetworkingMessage* m_pFirst;
        void push_back(CSteamNetworkingMessage* msg);
    } m_messagesQueued;
};

struct ConfigValue {
    int m_value;
    int Get() { return m_value; }
};

struct ConnectionConfig {
    ConfigValue m_SendBufferSize;
    ConfigValue m_NagleTime;
    ConfigValue m_LogLevel_Message;
};

class CSteamNetworkConnectionBase {
public:
    SenderState m_senderState;
    ConnectionConfig m_connectionConfig;
    void SNP_ClampSendRate();
    void SNP_TokenBucket_Accumulate(SteamNetworkingMicroseconds usecNow);
    SteamNetworkingMicroseconds SNP_GetNextThinkTime(SteamNetworkingMicroseconds usecNow);
    const char* GetDescription();
    void EnsureMinThinkTime(SteamNetworkingMicroseconds usec);
    void CheckConnectionStateAndSetNextThinkTime(SteamNetworkingMicroseconds usecNow);
    void SetNextThinkTimeASAP();
    int GetState();
    void SpewWarningRateLimited(SteamNetworkingMicroseconds usecNow, const char* fmt, ...);
    void SpewVerboseGroup(int level, const char* fmt, ...);
    void SpewVerbose(const char* fmt, ...);
    int64 SNP_SendMessage(CSteamNetworkingMessage* pSendMessage, SteamNetworkingMicroseconds usecNow, bool* pbThinkImmediately);
};

byte* SerializeVarInt(byte* p, uint64 val);