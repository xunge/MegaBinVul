#include <pthread.h>

class CGuard;
class CUDT;
class CSNode;
class CTimer;

enum EReschedule {};

class CGuard {
public:
    CGuard(pthread_mutex_t&);
    ~CGuard();
};

class CTimer {
public:
    void interrupt();
};

class CSndUList {
public:
    void update(const CUDT* u, EReschedule reschedule);
private:
    pthread_mutex_t m_ListLock;
    CTimer* m_pTimer;
    void remove_(const CUDT*);
    void insert_(int, const CUDT*);
    void insert_norealloc(int, const CUDT*);
};

class CUDT {
public:
    CSNode* m_pSNode;
};

class CSNode {
public:
    int m_iHeapLoc;
    long long m_llTimeStamp_tk;
};