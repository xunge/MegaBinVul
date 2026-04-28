#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <limits.h>

#define OMX_BUFFERFLAG_EOS 0x00000001
#define OMX_BUFFERFLAG_CODECCONFIG 0x00000002
#define OMX_EventError 0x80000000
#define OMX_ErrorUndefined 0x80001000

typedef uint8_t OMX_U8;
typedef uint8_t uint8;  // 添加uint8类型定义
typedef uint32_t OMX_U32;
typedef uint64_t OMX_U64;
typedef int32_t OMX_S32;
typedef int64_t OMX_S64;
typedef int32_t status_t;
typedef unsigned char Bool;

enum {
    NONE,
    AWAITING_DISABLED,
    AWAITING_ENABLED
};

struct OMX_BUFFERHEADERTYPE {
    OMX_U8* pBuffer;
    OMX_U32 nSize;
    OMX_U32 nVersion;
    OMX_U32 nAllocLen;
    OMX_U32 nFilledLen;
    OMX_U32 nOffset;
    OMX_U32 nFlags;
    OMX_S64 nTimeStamp;
};

struct BufferInfo {
    OMX_BUFFERHEADERTYPE* mHeader;
    bool mOwnedByUs;
};

template <typename T> class List {
public:
    class iterator {
    public:
        T& operator*() const;
        iterator& operator++();
        bool operator!=(const iterator& other) const;
    };
    
    iterator begin();
    iterator end();
    bool empty() const;
    size_t size() const;
    void erase(iterator pos);
    T& editItemAt(size_t index);
};

template <typename KEY, typename VALUE> class KeyedVector {
public:
    void add(KEY key, VALUE value);
    VALUE valueFor(KEY key) const;
    void removeItem(KEY key);
};

struct PortInfo {
    List<BufferInfo> mBuffers;
};

enum MP4DecodingMode {
    MPEG4_MODE,
    H263_MODE
};

#define PV_TRUE 1
#define PV_FALSE 0

typedef void* VideoDecControls;

#define ALOGW(...)
#define ALOGE(...)
#define android_errorWriteLog(...)

struct PVHandle {
    size_t size;
};

class SoftMPEG4 {
public:
    enum {
        MODE_MPEG4,
        MODE_H263
    };

    bool mSignalledError;
    int mOutputPortSettingsChange;
    bool mInitialized;
    bool mFramesConfigured;
    OMX_U32 mWidth;
    OMX_U32 mHeight;
    OMX_U32 mInputBufferCount;
    OMX_U32 mNumSamplesOutput;
    OMX_U32 mPvTime;
    int mMode;
    PVHandle* mHandle;
    KeyedVector<uint32_t, OMX_S64> mPvToOmxTimeMap;
    static const int kNumOutputBuffers = 2;

    List<BufferInfo*>& getPortQueue(OMX_U32 portIndex);
    PortInfo* editPortInfo(OMX_U32 portIndex);
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE* header);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE* header);
    void notify(int event, int error, int data, void* info);
    bool handlePortSettingsChange();
    OMX_U32 outputBufferWidth();
    OMX_U32 outputBufferHeight();
    void onQueueFilled(OMX_U32 portIndex);
};

extern "C" {
    void PVCleanUpVideoDecoder(void* handle);
    Bool PVInitVideoDecoder(void* handle, uint8_t** vol_data, int32_t* vol_size, 
                           int32_t num_vol_bufs, OMX_U32 width, OMX_U32 height, 
                           MP4DecodingMode mode);
    MP4DecodingMode PVGetDecBitstreamMode(void* handle);
    void PVSetPostProcType(VideoDecControls* handle, int type);
    Bool PVDecodeVideoFrame(void* handle, uint8_t** bitstream, uint32_t* timestamp, 
                           int32_t* bufferSize, uint32_t* useExtTimestamp, 
                           uint8_t* outBuffer);
    void PVSetReferenceYUV(void* handle, uint8_t* refFrame);
};