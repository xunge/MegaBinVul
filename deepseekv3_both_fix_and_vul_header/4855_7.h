#include <functional>
#include <memory>

class String {
public:
    String isolatedCopy() const;
};

class ExecutionContextTask {
public:
    virtual ~ExecutionContextTask() = default;
    virtual void performTask() = 0;
};

class CallClosureTask : public ExecutionContextTask {
public:
    static std::unique_ptr<ExecutionContextTask> create(std::function<void()>);
    void performTask() override;
};

template<typename T>
class RefPtrWillBeRawPtr {
public:
    RefPtrWillBeRawPtr(T*);
};

class WebSocketChannel {
public:
    enum SendResult { SendFail };
};

class WorkerThreadableWebSocketChannel {
public:
    class Bridge {
    public:
        class Peer {
        public:
            void send(const String&);
        };
        
        class SyncHelper {
        public:
            WebSocketChannel::SendResult sendRequestResult();
        };
        
        bool hasTerminatedPeer() const;
        bool waitForMethodCompletion(std::unique_ptr<ExecutionContextTask>);
        Peer* m_peer;
        SyncHelper* m_syncHelper;
        
        WebSocketChannel::SendResult send(const String& message);
    };
};

template<typename T>
class OwnPtr {
public:
    OwnPtr(std::unique_ptr<T>&&);
    std::unique_ptr<T> release();
};

template<typename T, typename U, typename... Args>
auto bind(T (U::*func), U* obj, Args&&... args) {
    return std::bind(func, obj, std::forward<Args>(args)...);
}