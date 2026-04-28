#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef int32_t status_t;
typedef uint32_t OMX_U32;
typedef int32_t OMX_ERRORTYPE;

#define BAD_VALUE (-1)
#define OK (0)
#define NELEM(x) (sizeof(x)/sizeof((x)[0]))
#define OMX_ErrorNone 0

typedef struct native_handle native_handle_t;

template<typename T> class sp {
public:
    sp() {}
    sp(T*) {}
    bool operator!=(const T*) const { return false; }
    bool operator==(const T*) const { return false; }
    T* operator->() const { return nullptr; }
};

class NativeHandle {
public:
    static sp<NativeHandle> create(native_handle_t*, bool);
    native_handle_t* handle() const;
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

class BufferMeta {
public:
    BufferMeta(size_t, OMX_U32) {}
};

class OMX_BUFFERHEADERTYPE {
public:
    void* pBuffer;
    void* pAppPrivate;
};

class GraphicBufferSource {
public:
    void addCodecBuffer(OMX_BUFFERHEADERTYPE*) {}
};

extern "C" {
    OMX_ERRORTYPE OMX_AllocateBuffer(
        void* hComponent,
        OMX_BUFFERHEADERTYPE** ppBuffer,
        OMX_U32 nPortIndex,
        void* pAppPrivate,
        OMX_U32 nSizeBytes);
    void android_errorWriteLog(int, const char*);
}

namespace OMX {
    typedef int buffer_id;
}

class OMXNodeInstance {
public:
    status_t allocateSecureBuffer(
        OMX_U32 portIndex, size_t size, OMX::buffer_id *buffer,
        void **buffer_data, sp<NativeHandle> *native_handle);

private:
    enum {
        kSecureBufferTypeNativeHandle,
    };
    OMX_BUFFERHEADERTYPE* mHandle;
    Mutex mLock;
    int mSecureBufferType[2];
    static const int kPortIndexInput = 0;

    OMX::buffer_id makeBufferID(OMX_BUFFERHEADERTYPE*);
    void addActiveBuffer(OMX_U32, OMX::buffer_id);
    sp<GraphicBufferSource> getGraphicBufferSource();
    status_t StatusFromOMXError(OMX_ERRORTYPE);
};

#define ALOGE(...)
#define CLOG_ERROR(...)
#define CLOG_BUFFER(...)
#define CHECK_EQ(a, b)