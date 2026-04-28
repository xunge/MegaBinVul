#include <pthread.h>

enum EReschedule {};

class CSNode {
public:
    int m_iHeapLoc;
    long long m_llTimeStamp_tk;
};

class CUDT {
public:
    CSNode* m_pSNode;
};

class CTimer {
public:
    void interrupt();
};

class CGuard {
public:
    CGuard(pthread_mutex_t&) {}
};

class CSndUList {
public:
    void update(const CUDT* u, EReschedule reschedule);
private:
    pthread_mutex_t m_ListLock;
    CTimer* m_pTimer;
    void remove_(const CUDT*);
    void insert_norealloc_(int, const CUDT*);
    void insert_norealloc(int, const CUDT*);
    void insert_(int, const CUDT*);
};