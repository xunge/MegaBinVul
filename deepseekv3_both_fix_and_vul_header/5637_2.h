#include <pthread.h>
#include <assert.h>

#define DCHECK(condition) assert(condition)

class WebAudioCapturerSource {
public:
    ~WebAudioCapturerSource();
};

struct ThreadChecker {
    bool CalledOnValidThread() const { return true; }
};

extern ThreadChecker thread_checker_;
extern void removeFromBlinkSource();