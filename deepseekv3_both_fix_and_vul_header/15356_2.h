#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <thread>
#include <cstring>
#include <cerrno>

#define ALOGE(...) 
#define ALOGW(...) 

struct pollfd;

namespace android {
namespace netdutils {
    int threadLaunch(void*);
}
}

class MDnsSdListener {
public:
    class Monitor {
    public:
        Monitor();
    private:
        void* mHead;
        int mLiveCount;
        pollfd* mPollFds;
        void** mPollRefs;
        int mPollSize;
        int mCtrlSocketPair[2];
        std::thread* mRescanThread;
        void run();
    };
};