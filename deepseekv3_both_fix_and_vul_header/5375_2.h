#include <mutex>

class TtsMessageFilter {
public:
    void OnDestruct() const;
private:
    mutable std::mutex mutex_;
    mutable bool valid_;
};

namespace base {
class AutoLock {
public:
    explicit AutoLock(std::mutex& mutex) : mutex_(mutex) { mutex_.lock(); }
    ~AutoLock() { mutex_.unlock(); }
private:
    std::mutex& mutex_;
};
}  // namespace base

class BrowserThread {
public:
    class DeleteOnUIThread {
    public:
        static void Destruct(const void* obj);
    };
};