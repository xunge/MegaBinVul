#include <stdint.h>
#include <stdbool.h>
#include <cstddef>

#define OMX_BUFFERFLAG_EOS 0x00000001
#define OMX_BUFFERFLAG_CODECCONFIG 0x00000002
#define OMX_EventError 0x80000000
#define OMX_ErrorUndefined 0x80001000

typedef int32_t OMX_U32;
typedef int32_t OMX_S32;
typedef uint8_t OMX_BOOL;
typedef uint8_t Bool;

enum PortSettingsChange {
    NONE,
    MODE_MPEG4
};

enum MP4DecodingMode {
    MPEG4_MODE = 0,
    H263_MODE = 1
};

struct OMX_BUFFERHEADERTYPE {
    uint8_t* pBuffer;
    OMX_U32 nSize;
    OMX_U32 nVersion;
    OMX_U32 nAllocLen;
    OMX_U32 nFilledLen;
    OMX_U32 nOffset;
    OMX_U32 nFlags;
    OMX_S32 nTimeStamp;
};

struct BufferInfo {
    OMX_BUFFERHEADERTYPE* mHeader;
    bool mOwnedByUs;
};

template<typename T>
class List {
public:
    class iterator {
    public:
        T& operator*();
        iterator& operator++();
        bool operator!=(const iterator& other);
    };
    
    iterator begin();
    iterator end();
    void erase(iterator pos);
    bool empty();
    size_t size();
    T& editItemAt(size_t index);
};

template<typename K, typename V>
class KeyedVector {
public:
    void add(K key, V value);
    V valueFor(K key);
    void removeItem(K key);
};

struct PortInfo {
    List<BufferInfo> mBuffers;
};

class SoftMPEG4 {
private:
    bool mSignalledError;
    int mOutputPortSettingsChange;
    int mNumSamplesOutput;
    int mInputBufferCount;
    void* mHandle;
    bool mInitialized;
    int mMode;
    int mWidth;
    int mHeight;
    bool mFramesConfigured;
    uint32_t mPvTime;
    KeyedVector<uint32_t, int64_t> mPvToOmxTimeMap;
    static const int kNumOutputBuffers = 2;

    List<BufferInfo*>& getPortQueue(int portIndex);
    PortInfo* editPortInfo(int portIndex);
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE* header);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE* header);
    void notify(int event, OMX_U32 data1, OMX_U32 data2, void* data);
    bool handlePortSettingsChange();
    int outputBufferWidth();
    int outputBufferHeight();
public:
    void onQueueFilled(OMX_U32 portIndex);
};

#define PV_TRUE 1
#define PV_FALSE 0
typedef void* VideoDecControls;

void PVCleanUpVideoDecoder(void* handle);
Bool PVInitVideoDecoder(void* handle, uint8_t** vol_data, int32_t* vol_size, 
                       int32_t num_vol_buffers, int width, int height, MP4DecodingMode mode);
MP4DecodingMode PVGetDecBitstreamMode(void* handle);
void PVSetPostProcType(VideoDecControls handle, int type);
int PVDecodeVideoFrame(void* handle, uint8_t** bitstream, uint32_t* timestamp, 
                      int32_t* bufferSize, uint32_t* useExtTimestamp, uint8_t* outBuffer);
void PVSetReferenceYUV(void* handle, uint8_t* outBuffer);

#define ALOGW(...)
#define ALOGE(...)
#define android_errorWriteLog(...)