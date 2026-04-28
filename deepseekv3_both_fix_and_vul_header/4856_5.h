#include <functional>
#include <memory>

using std::bind;
using std::unique_ptr;

class KURL {
public:
    KURL copy() const;
};

class String {
public:
    String isolatedCopy() const;
};

class ExecutionContextTask {
public:
    virtual ~ExecutionContextTask() = default;
};

class CallClosureTask : public ExecutionContextTask {
public:
    static unique_ptr<ExecutionContextTask> create(std::function<void()>);
};

template<typename T> class RefPtrWillBeRawPtr {
public:
    explicit RefPtrWillBeRawPtr(T*);
};

template<typename T> class OwnPtr {
public:
    OwnPtr(unique_ptr<T>&&);
    unique_ptr<T> release();
};

class WorkerThreadableWebSocketChannel {
    class Bridge {
    public:
        class Peer {
        public:
            void connect(const KURL&, const String&);
        };
        
        class SyncHelper {
        public:
            bool connectRequestResult();
        };

        bool connect(const KURL&, const String&);
        bool hasTerminatedPeer() const;
        bool waitForMethodCompletion(unique_ptr<ExecutionContextTask>);
        SyncHelper* m_syncHelper;
        Peer* m_peer;
    };
};