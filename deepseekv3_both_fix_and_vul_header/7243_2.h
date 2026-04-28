#include <vector>
#include <functional>

class Instance {
public:
    using IdleCb = std::function<void()>;
};

class ConnPoolImplBase {
protected:
    bool is_draining_for_deletion_;
    std::vector<Instance::IdleCb> idle_callbacks_;

    virtual void closeIdleConnectionsForDrainingPool() = 0;
    virtual void checkForIdleAndNotify() = 0;
    virtual bool isIdleImpl() = 0;
    
    void checkForIdleAndCloseIdleConnsIfDraining();
};

#define ENVOY_LOG(level, ...)