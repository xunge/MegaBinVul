#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <endian.h>
#include <new>
#include <byteswap.h>

class String8 {
public:
    void setTo(const char*);
    void setTo(const char*, size_t);
    void setTo(const char16_t*, size_t);
};

class ID3 {
public:
    enum {
        ID3_V1,
        ID3_V1_1
    };
    
    int mVersion;
    
    class Iterator {
    public:
        void getstring(String8 *id, bool otherdata) const;
        const ID3& mParent;
        const uint8_t* mFrameData;
        size_t mFrameSize;
        size_t mOffset;
        
        size_t getHeaderLength() const;
    };
};