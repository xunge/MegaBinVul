#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

typedef uint32_t OMX_U32;
#define OMX_BUFFERFLAG_EOS 0x00000001
#define OMX_EventError 0
#define OMX_ErrorUndefined 0

#define ALOGE(fmt, ...) fprintf(stderr, "E: " fmt "\n", ##__VA_ARGS__)
#define android_errorWriteLog(tag, msg) fprintf(stderr, "E: %s %s\n", tag, msg)

struct OMX_BUFFERHEADERTYPE {
    uint8_t *pBuffer;
    uint32_t nSize;
    uint32_t nVersion;
    uint32_t nAllocLen;
    uint32_t nFilledLen;
    uint32_t nOffset;
    uint32_t nFlags;
    uint64_t nTimeStamp;
};

struct BufferInfo {
    OMX_BUFFERHEADERTYPE *mHeader;
    bool mOwnedByUs;
};

template<typename T> class List {
public:
    bool empty() const;
    T* begin();
    void erase(T* pos);
};

class SoftG711 {
private:
    bool mSignalledError;
    bool mIsMLaw;
    static const int kMaxNumSamplesPerFrame;

    void notify(int eEvent, uint32_t nData1, uint32_t nData2, void* pEventData);
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE *header);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE *header);
    List<BufferInfo *>& getPortQueue(OMX_U32 portIndex);
    void DecodeMLaw(int16_t *out, const uint8_t *in, size_t inSize);
    void DecodeALaw(int16_t *out, const uint8_t *in, size_t inSize);
    
public:
    void onQueueFilled(OMX_U32 portIndex);
};