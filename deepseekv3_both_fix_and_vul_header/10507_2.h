#include <stdlib.h>
#include <stdbool.h>

typedef int OMX_ERRORTYPE;
#define OMX_ErrorNone 0

struct EncParams;
struct Handle;

class SoftMPEG4Encoder {
public:
    EncParams* mEncParams;
    Handle* mHandle;
    bool mStarted;
    void* mInputFrameData;
    
    OMX_ERRORTYPE releaseEncoder();
};

extern "C" {
    void PVCleanUpVideoEncoder(void* handle);
}