#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <cstddef>

#define NO_INIT 0
#define OK 0
#define UNKNOWN_ERROR (-1)
#define ERROR_MALFORMED (-2)
#define NO_MEMORY (-3)

#define MEDIA_MIMETYPE_CONTAINER_MPEG4 "video/mp4"
#define kKeyMIMEType "mime"
#define kKeyPssh "pssh"

#define ALOGE(...)
#define CHECK_NE(a, b)

typedef int32_t status_t;
typedef int64_t off64_t;

struct PsshInfo {
    uint8_t uuid[16];
    uint32_t datalen;
    uint8_t* data;
};

class MetaData {
public:
    void setCString(const char* key, const char* value);
    void setData(const char* key, uint32_t type, const void* data, size_t size);
};

class MPEG4Extractor {
public:
    status_t mInitCheck;
    bool mMdatFound;
    bool mMoofFound;
    bool mHasVideo;
    std::vector<PsshInfo> mPssh;
    MetaData* mFileMetaData;

    status_t readMetaData();
    status_t parseChunk(off64_t* offset, int depth);
};