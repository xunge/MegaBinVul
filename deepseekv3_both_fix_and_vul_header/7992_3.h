#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <limits.h>

#define MEDIA_MIMETYPE_VIDEO_AVC "video/avc"
#define OK 0
#define NO_ERROR 0
#define ERROR_MALFORMED (-1)

typedef int status_t;

struct DrmBuffer {
    char* data;
    size_t length;
    DrmBuffer() : data(NULL), length(0) {}
    DrmBuffer(char* d, size_t l) : data(d), length(l) {}
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

class ReadOptions {};

class MediaBuffer {
public:
    virtual size_t range_length() = 0;
    virtual void* data() = 0;
    virtual size_t range_offset() = 0;
    virtual size_t size() = 0;
    virtual void set_range(size_t, size_t) = 0;
    virtual void release() = 0;
    virtual status_t read(MediaBuffer**, const ReadOptions*) = 0;
};

class Format {
public:
    virtual bool findCString(const char*, const char**) const = 0;
};

class DrmManagerClient {
public:
    virtual status_t decrypt(void* decryptHandle, int trackId,
                           DrmBuffer* encryptedBuffer,
                           DrmBuffer** decryptedBuffer) = 0;
};

#define CHECK(expr) ((void)0)
#define CHECK_EQ(a, b) ((void)0)

static inline uint16_t U16_AT(const uint8_t* ptr) {
    return ptr[0] << 8 | ptr[1];
}

static inline uint32_t U32_AT(const uint8_t* ptr) {
    return ptr[0] << 24 | ptr[1] << 16 | ptr[2] << 8 | ptr[3];
}

static const char* kKeyMIMEType = "mime";

class DRMSource {
public:
    Mutex mDRMLock;
    MediaBuffer* mOriginalMediaSource;
    DrmManagerClient* mDrmManagerClient;
    void* mDecryptHandle;
    int mTrackId;
    Format* getFormat();
    int mNALLengthSize;
    bool mWantsNALFragments;
    status_t read(MediaBuffer**, const ReadOptions*);
};