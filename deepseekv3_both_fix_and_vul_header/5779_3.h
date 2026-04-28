#include <cstddef>
#include <vector>
#include <functional>

#define DCHECK(condition) ((void)0)
#define NULL nullptr

class PendingRequest {
public:
    void Cancel() {}
};

class GpuChannel {
public:
    void DestroyChannel() {}
};

class WaitableEvent {
public:
    void Signal() {}
};

template<typename T>
class scoped_refptr {
public:
    T* get() const { return ptr_; }
    T* operator->() const { return ptr_; }
    operator bool() const { return ptr_ != nullptr; }
    void reset(T* p = nullptr) { ptr_ = p; }
    scoped_refptr& operator=(T* p) { ptr_ = p; return *this; }

private:
    T* ptr_ = nullptr;
};

class Callback {
public:
    void Run() {}
};

class BrowserGpuChannelHostFactory {
public:
    ~BrowserGpuChannelHostFactory();
    bool IsMainThread() { return true; }

private:
    std::vector<Callback> established_callbacks_;
    scoped_refptr<PendingRequest> pending_request_;
    scoped_refptr<GpuChannel> gpu_channel_;
    scoped_refptr<WaitableEvent> shutdown_event_;
};