#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

typedef struct OMX_BUFFERHEADERTYPE {
    uint32_t nAllocLen;
    uint32_t nFilledLen;
} OMX_BUFFERHEADERTYPE;

class SoftVPX {
public:
    bool outputBufferSafe(OMX_BUFFERHEADERTYPE *outHeader);
    uint32_t outputBufferWidth();
    uint32_t outputBufferHeight();
};

#define ALOGE(...)
#define android_errorWriteLog(...)