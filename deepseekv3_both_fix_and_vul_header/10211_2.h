#include <cstring>

namespace rdr {
    typedef unsigned int U32;
}

struct RTTInfo {
};

class Writer {
public:
    void writeFence(rdr::U32 flags, unsigned len, const char data[]);
};

const rdr::U32 fenceFlagRequest = 0x1;
const rdr::U32 fenceFlagSyncNext = 0x2;
const rdr::U32 fenceFlagBlockBefore = 0x4;
const rdr::U32 fenceFlagBlockAfter = 0x8;

class VNCSConnectionST {
public:
    bool pendingSyncFence;
    rdr::U32 fenceFlags;
    unsigned fenceDataLen;
    char* fenceData;

    void fence(rdr::U32 flags, unsigned len, const char data[]);
    void handleRTTPong(const struct RTTInfo& rttInfo);
    Writer* writer();
};

class VLog {
public:
    void error(const char* msg);
};

extern VLog vlog;