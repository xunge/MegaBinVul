#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

typedef int32_t status_t;
#define BAD_VALUE (-1)
#define NELEM(x) (sizeof(x)/sizeof((x)[0]))

typedef uint32_t OMX_U32;
typedef int32_t OMX_ERRORTYPE;
typedef int32_t OMX_INDEXTYPE;
typedef char* OMX_STRING;
typedef int32_t OMX_BOOL;

enum {
    OMX_ErrorNone = 0
};

enum SecureBufferType {
    kSecureBufferTypeUnknown,
    kSecureBufferTypeOpaque,
    kSecureBufferTypeNativeHandle
};

struct EnableAndroidNativeBuffersParams {
    OMX_U32 nSize;
    struct {
        uint8_t nVersionMajor;
        uint8_t nVersionMinor;
        uint16_t nRevision;
        uint16_t nStep;
    } nVersion;
    OMX_U32 nPortIndex;
    OMX_BOOL enable;
};

#define InitOMXParams(p) \
    do { \
        (p)->nSize = sizeof(*(p)); \
        (p)->nVersion.nVersionMajor = 1; \
        (p)->nVersion.nVersionMinor = 0; \
        (p)->nVersion.nRevision = 0; \
        (p)->nVersion.nStep = 0; \
    } while (0)

#define PROPERTY_VALUE_MAX 92
static inline char* property_get(const char*, char*, const char*) { return NULL; }

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex& mutex) : mLock(mutex) {}
    private:
        Mutex& mLock;
    };
};

class OMXNodeInstance {
public:
    status_t enableNativeBuffers(OMX_U32 portIndex, OMX_BOOL graphic, OMX_BOOL enable);
private:
    SecureBufferType mSecureBufferType[2];
    void* mHandle;
    Mutex mLock;
};

static inline OMX_ERRORTYPE OMX_GetExtensionIndex(void*, OMX_STRING, OMX_INDEXTYPE*) { return OMX_ErrorNone; }
static inline OMX_ERRORTYPE OMX_SetParameter(void*, OMX_INDEXTYPE, void*) { return OMX_ErrorNone; }
static inline const char* portString(OMX_U32) { return ""; }
static inline status_t StatusFromOMXError(OMX_ERRORTYPE) { return 0; }

#define ALOGE(...)
#define android_errorWriteLog(...)
#define CLOG_CONFIG(...)
#define CLOG_IF_ERROR(...)
#define CLOG_ERROR_IF(...)