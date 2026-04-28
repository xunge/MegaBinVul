#include <functional>
#include <memory>

class ExecutionContextTask;

class Peer {
public:
    void destroy();
};

class LoaderProxy {
public:
    void postTaskToLoader(ExecutionContextTask*);
};

class CallClosureTask {
public:
    static ExecutionContextTask* create(std::function<void()>);
};

namespace WorkerThreadableWebSocketChannel {
    class Bridge {
    public:
        void terminatePeer();
        bool hasTerminatedPeer();
        void waitForMethodCompletion(ExecutionContextTask*);
        
        LoaderProxy m_loaderProxy;
        Peer* m_peer;
        void* m_syncHelper;
        void* m_workerGlobalScope;
    };
}

template<typename T>
class OwnPtr {
public:
    OwnPtr(T* ptr) : m_ptr(ptr) {}
    T* release() { T* ptr = m_ptr; m_ptr = nullptr; return ptr; }
private:
    T* m_ptr;
};

#define ASSERT(expr) 
#define ENABLE(OILPAN) 0

using std::bind;