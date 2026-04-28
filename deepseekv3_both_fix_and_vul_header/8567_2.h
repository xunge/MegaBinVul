#include <stdlib.h>

#define UNUSED __attribute__((unused))

class FrameworkCommandCollection {
public:
    FrameworkCommandCollection();
};

class FrameworkListener {
public:
    void init(const char *socketName UNUSED, bool withSeq);
    FrameworkCommandCollection* mCommands;
    int errorRate;
    int mCommandCount;
    bool mWithSeq;
    bool mSkipToNextNullByte;
};