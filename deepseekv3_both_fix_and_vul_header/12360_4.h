#include <string.h>
#include <stdint.h>
#include <stdlib.h>

typedef int64_t int64;

#define IOFLAG_WRITE 1
#define MAX_SNAPSHOT_PACKSIZE 900

struct CNetChunk
{
    unsigned char *m_pData;
    int m_DataSize;
    int m_Flags;
};

class CUnpacker
{
public:
    enum
    {
        SANITIZE_CC = 1,
        SKIP_START_WHITESPACES = 2
    };
    void Reset(unsigned char *pData, int Size);
    int GetInt();
    const char *GetString(int Flags = 0);
    const unsigned char *GetRaw(int Size);
    bool Error();
};

class CMsgPacker
{
public:
    CMsgPacker(int Msg);
    void AddInt(int Value);
};

class IConsole
{
public:
    enum
    {
        OUTPUT_LEVEL_ADDINFO,
        OUTPUT_LEVEL_DEBUG,
        OUTPUT_LEVEL_STANDARD
    };
    void Print(int Level, const char *pLabel, const char *pText);
    void RegisterTemp(const char *pName, const char *pParams, int Flags, const char *pHelp);
    void DeregisterTemp(const char *pName);
    void DeregisterTempAll();
};

class IClient
{
public:
    enum
    {
        STATE_LOADING,
        STATE_ONLINE
    };
    int State();
};

class CSnapshot
{
public:
    static const int MAX_PARTS = 64;
    static const int MAX_SIZE = 65536;
    void Clear();
    int Crc();
    int m_Tick;
};

class CVariableInt
{
public:
    static int Decompress(const void *pSrc, int SrcSize, void *pDest);
};

enum
{
    NETMSG_MAP_CHANGE,
    NETMSG_MAP_DATA,
    NETMSG_CON_READY,
    NETMSG_PING,
    NETMSG_PING_REPLY,
    NETMSG_RCON_CMD_ADD,
    NETMSG_RCON_CMD_REM,
    NETMSG_RCON_AUTH_STATUS,
    NETMSG_RCON_LINE,
    NETMSG_INPUTTIMING,
    NETMSG_SNAP,
    NETMSG_SNAPSINGLE,
    NETMSG_SNAPEMPTY,
    NETMSG_REQUEST_MAP_DATA
};

enum
{
    NET_CHUNKFLAG_VITAL = 1
};

enum
{
    MSGFLAG_VITAL = 1,
    MSGFLAG_FLUSH = 2
};

enum
{
    CFGFLAG_SERVER = 1
};

enum
{
    PREDICTION_MARGIN = 100
};

enum
{
    SNAP_PREV,
    SNAP_CURRENT
};

class CMapChecker
{
public:
    bool IsMapValid(const char *pMap, int MapCrc, int MapSize);
};

class IStorage
{
public:
    enum
    {
        TYPE_SAVE
    };
    void *OpenFile(const char *pFilename, int Flags, int Type);
};

class CDemoRecorder
{
public:
    bool IsRecording();
    void RecordSnapshot(int Tick, const void *pData, int Size);
    void RecordMessage(const void *pData, int Size);
};

class CInputPrediction
{
public:
    void Update(void *pGraph, int64 Target, int TimeLeft, int AdjustSpeed);
    void Init(int64 Time);
    void SetAdjustSpeed(int Direction, float Value);
    int64 Get(int64 Now);
};

class CGameTime
{
public:
    void Init(int64 Time);
    void Update(void *pGraph, int64 Time, int TimeLeft, int Direction);
    int64 Get(int64 Now);
};

class CConfig
{
public:
    int m_Debug;
};

extern CConfig g_Config;

static int64 time_get() { return 0; }
static int time_freq() { return 1; }
static void io_close(void *pFile) {}
static int io_write(void *pFile, const void *pData, int Size) { return 0; }

class IGameClient
{
public:
    void OnConnected();
    void OnRconLine(const char *pLine);
    void OnMessage(int Msg, CUnpacker *pUnpacker);
};

class CClient
{
public:
    void ProcessServerPacket(CNetChunk *pPacket);
    void DisconnectWithReason(const char *pError);
    const char* LoadMapSearch(const char *pMap, int MapCrc);
    void SendReady();
    void SendMsgEx(CMsgPacker *pMsg, int Flags);
    const char* LoadMap(const char *pName, const char *pFilename, int Crc);
    void SendInput();
    void SetState(int State);
    void DemoRecorder_HandleAutoStart();
    IGameClient* GameClient();
    int State() { return 0; }
    
    CMapChecker m_MapChecker;
    IConsole *m_pConsole;
    IStorage *Storage();
    int m_MapdownloadChunk;
    void *m_MapdownloadFile;
    int m_MapdownloadCrc;
    int m_MapdownloadTotalsize;
    int m_MapdownloadAmount;
    char m_aMapdownloadFilename[256];
    char m_aMapdownloadName[256];
    int m_RconAuthed;
    int m_UseTempRconCommands;
    int64 m_PingStartTime;
    struct
    {
        int m_Tick;
        int64 m_PredictedTime;
        int64 m_Time;
    } m_aInputs[200];
    CInputPrediction m_PredictedTime;
    CGameTime m_GameTime;
    int m_CurrentRecvTick;
    unsigned m_SnapshotParts;
    unsigned char m_aSnapshotIncommingData[CSnapshot::MAX_SIZE];
    int m_SnapCrcErrors;
    int m_AckGameTick;
    CDemoRecorder m_DemoRecorder;
    int m_RecivedSnapshots;
    CSnapshot *m_aSnapshots[2];
    int64 m_LocalStartTime;
    void *m_InputtimeMarginGraph;
    void *m_GametimeMarginGraph;
    struct
    {
        CSnapshot *m_pFirst;
        CSnapshot *m_pLast;
        int Get(int Tick, int *pSize, CSnapshot **ppSnapshot, int *pDataSize);
        void PurgeUntil(int Tick);
        void Add(int Tick, int64 Time, int Size, CSnapshot *pSnapshot, int DataSize);
    } m_SnapshotStorage;
    struct
    {
        void *EmptyDelta();
        int UnpackDelta(CSnapshot *pFrom, CSnapshot *pTo, void *pData, int DataSize);
    } m_SnapshotDelta;
};

static inline void str_format(char *buffer, int buffer_size, const char *format, ...) {}
static inline void str_copy(char *dest, const char *src, int dest_size) {}
static inline void mem_copy(void *dest, const void *src, size_t size) {}