#include <pthread.h>

class CSNode;
class CSndUList {
public:
    CSndUList();
    
private:
    CSNode** m_pHeap;
    int m_iArrayLength;
    int m_iLastEntry;
    pthread_mutex_t m_ListLock;
    void* m_pWindowLock;
    void* m_pWindowCond;
    void* m_pTimer;
};