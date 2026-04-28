#include <mutex>
#include <cassert>
#include <iostream>

#define DCHECK_IS_ON() 1
#define DCHECK(condition) if (!(condition)) std::cerr

class AutoLock {
public:
    explicit AutoLock(std::mutex& lock) : lock_(lock) { lock_.lock(); }
    ~AutoLock() { lock_.unlock(); }
private:
    std::mutex& lock_;
};

class GpuChannelHost {
private:
    std::mutex context_lock_;
    void* channel_;
public:
    ~GpuChannelHost();
    void DestroyChannel();
};