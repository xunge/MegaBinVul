#include <stdint.h>
#include <pthread.h>

struct CUDT;
struct CTimer;

struct CSNode {
    int m_iHeapLoc;
    int64_t m_llTimeStamp_tk;
};

class CSndUList {
public:
    void insert_(int64_t ts, const CUDT* u);

private:
    CSNode** m_pHeap;
    int m_iLastEntry;
    int m_iArrayLength;
    CTimer* m_pTimer;
    pthread_mutex_t* m_pWindowLock;
    pthread_cond_t* m_pWindowCond;

    void realloc_();
    void insert_norealloc(int64_t ts, const CUDT* u);
};

struct CUDT {
    CSNode* m_pSNode;
};

struct CTimer {
    void interrupt();
};