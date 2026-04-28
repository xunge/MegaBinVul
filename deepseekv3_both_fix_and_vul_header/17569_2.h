#include <string.h>
#include <cstring>

#define MAX_CLIENTS 64

enum
{
    MSGFLAG_VITAL = 1,
    MSGFLAG_FLUSH = 2,
    MSGFLAG_NORECORD = 4,
    MSGFLAG_NOSEND = 8
};

enum
{
    NETSENDFLAG_VITAL = 1,
    NETSENDFLAG_FLUSH = 2
};

struct CNetChunk
{
    int m_ClientID;
    const void *m_pData;
    int m_DataSize;
    int m_Flags;
};

class CClient
{
public:
    enum STATE
    {
        STATE_EMPTY,
        STATE_INGAME
    };
    STATE m_State;
    bool m_Quitting;
};

class CMsgPacker
{
public:
    const void *Data() const;
    int Size() const;
};

class CNetServer
{
public:
    void Send(CNetChunk *pChunk);
};

class CDemoRecorder
{
public:
    void RecordMessage(const void *pData, int Size);
};

class IGameServer
{
public:
    bool IsClientBot(int ClientID);
};

class CServer
{
public:
    CClient m_aClients[MAX_CLIENTS];
    CNetServer m_NetServer;
    CDemoRecorder m_DemoRecorder;
    IGameServer* GameServer();
    int SendMsg(CMsgPacker *pMsg, int Flags, int ClientID);
    
    static void mem_zero(void *p, size_t size) { memset(p, 0, size); }
};