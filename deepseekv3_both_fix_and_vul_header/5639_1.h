#include <pthread.h>
#include <stddef.h>
#include <assert.h>

#define DCHECK(condition) assert(condition)

class WebAudioCapturerSource {
public:
    void Stop();
};

struct ThreadChecker {
    bool CalledOnValidThread() { return true; }
};

namespace base {
    class AutoLock {
    public:
        AutoLock(pthread_mutex_t& lock) {}
    };
}

pthread_mutex_t lock_;
void* track_;
ThreadChecker thread_checker_;
void removeFromBlinkSource() {}