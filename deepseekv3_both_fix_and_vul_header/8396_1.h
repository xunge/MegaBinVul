#include <stddef.h>
#include <string.h>
#include <stdbool.h>

typedef struct OMX_BUFFERHEADERTYPE {
    unsigned long nAllocLen;
    void *pBuffer;
} OMX_BUFFERHEADERTYPE;

struct SoftMP3 {
    void *memsetSafe(OMX_BUFFERHEADERTYPE *outHeader, int c, size_t len);
    void notify(int, int, int, void*);
    bool mSignalledError;
};

#define OMX_EventError 0
#define OMX_ErrorUndefined 0
#define OUTPUT_BUFFER_TOO_SMALL 0

#define ALOGE(...)
#define android_errorWriteLog(...)