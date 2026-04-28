#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <endian.h>
#include <new>

typedef int32_t status_t;

#define FOURCC(a, b, c, d) ((a) << 24 | (b) << 16 | (c) << 8 | (d))

enum {
    OK = 0,
    ERROR_MALFORMED = -1,
    ERROR_IO = -2
};

enum {
    kKeyTitle = 1,
    kKeyArtist = 2,
    kKeyWriter = 3,
    kKeyGenre = 4,
    kKeyAlbum = 5,
    kKeyCDTrackNumber = 6,
    kKeyYear = 7
};

static inline uint16_t U16_AT(const void *ptr) {
    return be16toh(*((uint16_t *)ptr));
}

static inline uint16_t bswap_16(uint16_t x) {
    return (x >> 8) | (x << 8);
}

class String8 {
public:
    String8(const char16_t* str, size_t len);
    const char* string() const;
};

class MetaData {
public:
    void setCString(uint32_t key, const char* value);
};

class DataSource {
public:
    virtual ssize_t readAt(off64_t offset, void *data, size_t size) = 0;
};

class MPEG4Extractor {
public:
    DataSource* mDataSource;
    MetaData* mFileMetaData;
    uint32_t* mPath;
    status_t parse3GPPMetaData(off64_t offset, size_t size, int depth);
};