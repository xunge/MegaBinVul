#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdint>
#include <iostream>

class CGuard {
public:
    CGuard(void*) {}
};
class CPacket {};
class CUDT {
public:
    bool m_bListening;
    bool m_bConnecting;
    bool m_bConnected;
    bool m_bClosing;
    bool m_bShutdown;
    bool m_bBroken;
    bool m_bPeerHealth;
    bool m_bOpened;
    sockaddr* m_pPeerAddr;
    int socketID();
    int packData(CPacket&, uint64_t);
};
class CTimer {
public:
    static void rdtsc(uint64_t&);
};
class CSndUList {
public:
    int pop(sockaddr*& addr, CPacket& pkt);
private:
    void* m_ListLock;
    int m_iLastEntry;
    struct Entry {
        uint64_t m_llTimeStamp_tk;
        CUDT* m_pUDT;
    }** m_pHeap;
    void remove_(CUDT*);
    void insert_norealloc_(uint64_t, CUDT*);
    void insert_norealloc(uint64_t, CUDT*);
};

struct mglog {
    static struct Debug {
        template <typename T>
        Debug& operator<<(const T&) { return *this; }
    } Debug;
};

#define HLOGC(stream, expr) (void)0
extern mglog mglog;
extern std::ostream log;