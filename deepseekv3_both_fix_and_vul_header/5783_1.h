#include <memory>
#include <iostream>

namespace IPC {
class Message {
public:
    void set_unblock(bool unblock) {}
};
}  // namespace IPC

namespace base {
class ThreadRestrictions {
public:
    class ScopedAllowWait {
    public:
        ScopedAllowWait() {}
    };
};
}  // namespace base

template <typename T>
class scoped_ptr {
public:
    explicit scoped_ptr(T* ptr) : ptr_(ptr) {}
    ~scoped_ptr() { delete ptr_; }
    T* get() { return ptr_; }
    T* release() {
        T* ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }
    T* operator->() { return ptr_; }
private:
    T* ptr_;
};

class GpuChannelHost {
public:
    bool Send(IPC::Message* msg);
private:
    class Factory {
    public:
        bool IsMainThread() { return false; }
    };
    class Channel {
    public:
        bool Send(IPC::Message* msg) { return false; }
    };
    class SyncFilter {
    public:
        bool Send(IPC::Message* msg) { return false; }
    };
    Factory* factory_;
    Channel* channel_;
    SyncFilter* sync_filter_;
};

#define DVLOG(level) std::cout