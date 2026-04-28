#include <poll.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <mutex>

typedef void* DNSServiceRef;

#define LOG_ALWAYS_FATAL_IF(cond, ...) if (cond) exit(1)
#define ALOGD(...)
#define ALOGE(...)
#define VDBG 0
#define DBG 0

struct MDnsSdListener {
    struct Monitor {
        void run();
    };
};

struct pollfd* mPollFds;
DNSServiceRef** mPollRefs;
int mPollSize;
int mCtrlSocketPair[2];
std::mutex mMutex;
const char RESCAN[1] = {0};

int rescan();
void DNSServiceProcessResult(DNSServiceRef ref);