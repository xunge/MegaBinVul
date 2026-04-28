#include <string.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct OMX_BUFFERHEADERTYPE {
    unsigned long nAllocLen;
    void* pBuffer;
} OMX_BUFFERHEADERTYPE;

#define OMX_EventError 0
#define OMX_ErrorUndefined 0
#define OUTPUT_BUFFER_TOO_SMALL 0

#define ALOGE(...)

void notify(int, int, int, void*);
bool mSignalledError;
void android_errorWriteLog(unsigned, const char*);

struct SoftMP3 {
    void* memsetSafe(OMX_BUFFERHEADERTYPE*, int, size_t);
};