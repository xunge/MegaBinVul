#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#define ALOGW printf

class String8 {
public:
    void setTo(const char*);
};

class ID3 {
public:
    enum {
        ID3_V2_3,
        ID3_V2_4
    };
    int mVersion;

    class Iterator {
    public:
        Iterator(const ID3&, const char*);
        bool done() const;
        void next();
        const uint8_t* getData(size_t*);
    };

    size_t StringSize(const uint8_t*, size_t, uint8_t) const;
    size_t StringSize(const uint8_t*, uint8_t) const;
    const void* getAlbumArt(size_t*, String8*) const;
};