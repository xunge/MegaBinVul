#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define OMX_BUFFERFLAG_EOS 0x00000001
#define ALOGE(...)
#define android_errorWriteLog(...)
#define CHECK_EQ(a,b) assert((a)==(b))
#define CHECK_GE(a,b) assert((a)>=(b))

typedef uint32_t OMX_U32;
typedef int32_t OMX_S32;
typedef int16_t OMX_S16;
typedef uint8_t OMX_U8;
typedef int32_t OMX_ERRORTYPE;
typedef void *OMX_HANDLETYPE;
typedef void *OMX_PTR;

enum OMX_EVENTTYPE {
    OMX_EventError
};

enum OMX_ERROR {
    OMX_ErrorNone = 0,
    OMX_ErrorOverflow,
    OMX_ErrorStreamCorrupt,
    OMX_ErrorUndefined
};

enum {
    MODE_NARROW,
    MODE_WIDE
};

enum {
    NONE
};

typedef enum {
    MIME_IETF
} Frame_Type_3GPP;

typedef uint8_t UWord8;
typedef int16_t int16;

typedef struct RX_State_wb {
    int dummy;
} RX_State_wb;

struct OMX_BUFFERHEADERTYPE {
    OMX_U8 *pBuffer;
    OMX_U32 nSize;
    OMX_U32 nVersion;
    OMX_U32 nAllocLen;
    OMX_U32 nFilledLen;
    OMX_U32 nOffset;
    OMX_U32 nFlags;
    OMX_S32 nTimeStamp;
};

struct BufferInfo {
    struct OMX_BUFFERHEADERTYPE *mHeader;
    bool mOwnedByUs;
};

template <class T>
class List {
public:
    bool empty() const;
    void erase(T*);
    T* begin();
};

class SoftAMR {
protected:
    bool mSignalledError;
    int mOutputPortSettingsChange;
    int64_t mAnchorTimeUs;
    int64_t mNumSamplesOutput;
    int mMode;
    void* mState;
    int16_t mInputSampleBuffer[1024];
    void* mDecoderBuf;
    void* mDecoderCookie;
    int mInputBufferCount;

    List<BufferInfo*>& getPortQueue(int portIndex);
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE* header);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE* header);
    void notify(OMX_EVENTTYPE event, OMX_ERRORTYPE error, OMX_U32 data, OMX_PTR info);
    size_t getFrameSize(int mode);
    
    void onQueueFilled(OMX_U32 portIndex);
};

extern const size_t WmfDecBytesPerFrame[];
extern const int kNumSamplesPerFrameNB;
extern const int kNumSamplesPerFrameWB;
extern const int kSampleRateNB;
extern const int kSampleRateWB;

extern int AMRDecode(void*, Frame_Type_3GPP, UWord8*, int16_t*, int);
extern void mime_unsorting(uint8_t*, int16_t*, int16_t*, int16_t*, int, RX_State_wb*);
extern void pvDecoder_AmrWb(int16_t, int16_t*, int16_t*, int16_t*, void*, int16_t, void*);