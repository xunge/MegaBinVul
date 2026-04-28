#include <functional>
#include <memory>

class String {
public:
    String isolatedCopy() const;
};

enum class MessageLevel {};

class ExecutionContextTask {};
class CallClosureTask {
public:
    static ExecutionContextTask* create(std::function<void()>);
};

namespace WorkerThreadableWebSocketChannel {
    class Peer {
    public:
        void fail(const String&, MessageLevel, const String&, unsigned);
    };

    class Bridge {
    public:
        bool hasTerminatedPeer();
        Peer* m_peer;
        
        class LoaderProxy {
        public:
            void postTaskToLoader(ExecutionContextTask*);
        };
        LoaderProxy m_loaderProxy;
        
        void fail(const String&, MessageLevel, const String&, unsigned);
    };
}

template<typename T> class OwnPtr {
public:
    OwnPtr(T* ptr) : m_ptr(ptr) {}
    T* release() { return m_ptr; }
private:
    T* m_ptr;
};

template<typename T> OwnPtr<T> adoptPtr(T* ptr) { return OwnPtr<T>(ptr); }

using std::bind;