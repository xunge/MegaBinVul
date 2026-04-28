#include <memory>
#include <mutex>

class AutoLock {
public:
    explicit AutoLock(std::mutex& lock);
};

class Channel {};
class Factory {
public:
    bool IsMainThread();
    class MainLoop* GetMainLoop();
};

class MainLoop {
public:
    void DeleteSoon(const char* from_here, Channel* channel);
};

class GpuChannelHost {
public:
    void DestroyChannel();
private:
    std::unique_ptr<Channel> channel_;
    std::mutex context_lock_;
    Factory* factory_;
};

#define DCHECK(condition) (void)(condition)
#define FROM_HERE __FILE__