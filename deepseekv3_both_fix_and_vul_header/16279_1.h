#include <stdint.h>
#include <stddef.h>

typedef uint64_t SteamNetworkingMicroseconds;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;

struct UDPDataMsgHdr {
    uint32_t m_unToConnectionID;
    uint16_t m_unSeqNum;
    uint8_t m_unMsgFlags;
    static const uint8_t kFlag_ProtobufBlob;
};

struct CMsgSteamSockets_UDP_Stats {
    bool ParseFromArray(const void* data, int size) { return false; }
};

struct UDPRecvPacketContext_t {
    SteamNetworkingMicroseconds m_usecNow;
    void* m_pTransport;
    CMsgSteamSockets_UDP_Stats* m_pStatsIn;
};

enum ESteamNetworkingConnectionState {
    k_ESteamNetworkingConnectionState_Dead,
    k_ESteamNetworkingConnectionState_None,
    k_ESteamNetworkingConnectionState_ClosedByPeer,
    k_ESteamNetworkingConnectionState_FinWait,
    k_ESteamNetworkingConnectionState_ProblemDetectedLocally,
    k_ESteamNetworkingConnectionState_Connecting,
    k_ESteamNetworkingConnectionState_Linger,
    k_ESteamNetworkingConnectionState_Connected,
    k_ESteamNetworkingConnectionState_FindingRoute
};

class CConnectionTransportUDPBase {
public:
    void Received_Data(const uint8* pPkt, int cbPkt, SteamNetworkingMicroseconds usecNow);
    uint32_t ConnectionIDLocal();
    ESteamNetworkingConnectionState ConnectionState();
    struct Connection {
        bool DecryptDataChunk(uint16 nWirePktNumber, int cbPkt, const void* pChunk, int cbChunk, UDPRecvPacketContext_t& ctx);
        bool ProcessPlainTextDataChunk(int usecTimeSinceLast, UDPRecvPacketContext_t& ctx);
    } m_connection;
    void RecvValidUDPDataPacket(UDPRecvPacketContext_t& ctx);
    void RecvStats(CMsgSteamSockets_UDP_Stats& msg, SteamNetworkingMicroseconds usecNow);
};

inline uint32_t LittleDWord(uint32_t val) { return val; }
inline uint16_t LittleWord(uint16_t val) { return val; }

const uint8_t* DeserializeVarInt(const uint8_t* pIn, const uint8_t* pEnd, uint32_t& result);
void ReportBadUDPPacketFromConnectionPeer(const char* type, const char* fmt, ...);
bool BCheckGlobalSpamReplyRateLimit(SteamNetworkingMicroseconds usecNow);
void SendNoConnection(uint32_t connectionID, int reason);
void Assert(bool condition);
void SendConnectionClosedOrNoConnection();