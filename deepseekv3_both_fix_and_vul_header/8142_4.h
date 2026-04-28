#include <stdbool.h>
#include <stdint.h>
#include <cstddef>

#define FBD 0
#define EBD 1
#define OMX_ErrorBadParameter 0
#define WITH_STATS(x) x
#define FULL_BUFFER(a,b,c) ""
#define EMPTY_BUFFER(a,b,c) ""
#define onFillBufferDone "onFillBufferDone"

struct OMX_BUFFERHEADERTYPE {
    void* pAppPrivate;
    uint32_t nOffset;
    uint32_t nFilledLen;
    uint32_t nAllocLen;
    int64_t nTimeStamp;
};

struct omx_message {
    enum {
        FILL_BUFFER_DONE,
        EMPTY_BUFFER_DONE
    } type;
    union {
        struct {
            OMX_BUFFERHEADERTYPE* buffer;
        } buffer_data;
        struct {
            OMX_BUFFERHEADERTYPE* buffer;
            int64_t timestamp;
        } extended_buffer_data;
    } u;
    int fenceFd;
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex& mutex) {}
    };
};

template<typename T>
class List {
public:
    void remove(T* item) {}
};

template<typename T>
class sp {
public:
    T* operator->() const { return nullptr; }
    operator bool() const { return false; }
    bool operator!=(std::nullptr_t) const { return false; }
};

class GraphicBufferSource {
public:
    void codecBufferFilled(OMX_BUFFERHEADERTYPE* buffer) {}
    void codecBufferEmptied(OMX_BUFFERHEADERTYPE* buffer, int fenceFd) {}
};

class BufferMeta {
public:
    void CopyFromOMX(OMX_BUFFERHEADERTYPE* buffer) {}
};

class OMXNodeInstance {
public:
    bool handleMessage(omx_message &msg);
private:
    Mutex mDebugLock;
    List<OMX_BUFFERHEADERTYPE> mOutputBuffersWithCodec;
    List<OMX_BUFFERHEADERTYPE> mInputBuffersWithCodec;
    int kPortIndexOutput;
    int kPortIndexInput;
    OMX_BUFFERHEADERTYPE* findBufferHeader(OMX_BUFFERHEADERTYPE* buffer, int portIndex) { return nullptr; }
    OMX_BUFFERHEADERTYPE* findBufferHeader(OMX_BUFFERHEADERTYPE* buffer) { return nullptr; }
    sp<GraphicBufferSource> getGraphicBufferSource() { return sp<GraphicBufferSource>(); }
    void unbumpDebugLevel_l(int portIndex) {}
    void CLOG_BUMPED_BUFFER(int type, const char* stats) {}
    void CLOG_ERROR(const char* func, int error, const char* details) {}
};